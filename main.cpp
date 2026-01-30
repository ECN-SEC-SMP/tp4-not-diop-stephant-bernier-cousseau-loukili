#include <cstdlib>
#include <iostream>
#include "Carte.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello World !" << std::endl;

    if(argc != 2) {
        std::cout << "Usage: tp4 <fichierCarte>" << std::endl;
        exit(-1);
    }

    std::string fichier(argv[1]);

    Carte carte(fichier);

    carte.afficher();

    std::cout << "Surface totale de la carte : " << carte.surfaceTotale() << std::endl;
}