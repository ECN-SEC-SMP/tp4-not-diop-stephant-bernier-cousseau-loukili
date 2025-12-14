#include "Carte.hpp"

#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "Point2D.hpp"
#include "Polygone.hpp"
#include "ZoneUrbaine.hpp"
#include "ZoneNaturelle.hpp"
#include "ZoneAUrbaniser.hpp"
#include "ZoneAgricole.hpp"

class MapFileNotFoundException : public std::exception {
public:
    const char * what () {
        return "Fichier carte introuvable/inouvrable";
    }
};

class InvalidZoneTypeException : public std::exception {
public:
    const char * what () {
        return "Type de Parcelle invalide";
    }
};

class MalformatedMapData : public std::exception {
public:
    const char * what () {
        return "Données de carte invalides";
    }
};

Carte::Carte() {

}

Carte::~Carte() {
    //Liberez toutes nos parcelles
    for (auto parcelle : listeParcelles) {
        delete parcelle;
    }
}

Polygone<int> readPolygon(std::string& polygon) {
    std::istringstream iss(polygon);

    std::string currentPoint;
    std::vector<Point2D<int>> pointList;

    while(std::getline(iss, currentPoint, ' ')) {
        if(currentPoint[0] != '[') {
            throw MalformatedMapData();
        }

        if(currentPoint[currentPoint.length()-1] != ']') {
            throw MalformatedMapData();
        }
        
        int i = 1;
        char currentChar = currentPoint[i];
        std::string buf;
        while(currentChar != ';')  {
            buf += currentChar;
            currentChar = currentPoint[++i];
        }

        //Essaie de convertir de la string en nombre
        int x;

        try {
            x = std::stoi(buf);
        } catch (std::exception& e) {
            std::cerr << "Echec conversion x. Point :" << currentPoint << std::endl;
            std::cerr << e.what() << std::endl;
            exit(-2);
        }

        //Skip le ;
        currentChar = currentPoint[++i];

        buf.clear();

        while(currentChar != ']')  {
            buf += currentChar;
            currentChar = currentPoint[++i];
        }

        int y;

        try {
            y = std::stoi(buf);
        } catch (std::exception& e) {
            std::cerr << "Echec conversion y. Point :" << currentPoint << " Buf : " << buf << std::endl;
            std::cerr << e.what() << std::endl;
            exit(-3);
        }

        Point2D<int> point(x, y);
        pointList.push_back(point);
    }

    //Vraissemblablement on a ici assez de points pour construire un polygone
    Polygone<int> poly(pointList);

    return poly;
}

Carte::Carte(std::string& nomFichier) { 
    //Deserialization
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        throw MapFileNotFoundException();
    }

    std::string currentLine;
    std::string polyLine;
    while (std::getline(fichier, currentLine))
    {
        std::istringstream iss(currentLine);
        std::string type;
        std::string proprietaire;

        int numero;

        if (!(iss >> type)) { break; } // error
        if (!(iss >> numero)) { break; } // error
        if (!(iss >> proprietaire)) { break; } // error

        if(!std::getline(fichier, polyLine)) {
            throw MalformatedMapData();
        }

        Polygone<int> poly = readPolygon(polyLine);

        // /!\ La surface constructible est donnée en pourcentage pour une raison obscure
        //     Il va falloir modifier les constructeurs des classes des zones pour prendre ça en compte
        if(type == "ZU") {
            int constructible;
            int surfaceConstruite;
            
            if (!(iss >> constructible)) { break; } // error
            if (!(iss >> surfaceConstruite)) { break; } // error

            //Nous pouvons juste ignorer constructible car il est recalculé par la fonction dans tous les cas
            ZoneUrbaine* zu = new ZoneUrbaine(numero, proprietaire, poly, surfaceConstruite);
            listeParcelles.push_back(zu);
        } else if (type == "ZAU") {
            int constructible;
            
            if (!(iss >> constructible)) { break; } // error

            ZoneAUrbaniser* zau = new ZoneAUrbaniser(numero, proprietaire, poly, constructible);
            listeParcelles.push_back(zau);
        } else if (type == "ZN") {
            ZoneNaturelle* zn = new ZoneNaturelle(numero, proprietaire, poly);
            listeParcelles.push_back(zn);
        } else if (type == "ZA") {
            std::string typeCulture;
            
            if (!(iss >> typeCulture)) { break; } // error

            ZoneAgricole* zau = new ZoneAgricole(numero, proprietaire, poly, typeCulture);
            listeParcelles.push_back(zau);
        } else {
            throw InvalidZoneTypeException();
        }
    }
}

void Carte::afficher() {
    std::cout << "Liste des parcelles :" << std::endl;
    for (auto parcelle : listeParcelles) {
        std::cout << parcelle << std::endl;
    }
}