#pragma once
#include <iostream>
#include <string>

#include "ZoneNaturelle.hpp"

///
/// @brief classe ZoneAgricole, fille de la classe ZoneNanturelle
class ZoneAgricole : public ZoneNaturelle
{
private:
    std::string typeCulture; // type de culture (céréales, légumes, etc.)
    float surfaceConstruite; //surface construite en m²
    std::string typeParcelle;
public:
    ZoneAgricole(int ZN_numero, std::string &ZN_proprietaire, Polygone<int> forme);
    ZoneAgricole(int ZN_numero, std::string &ZN_proprietaire, Polygone<int> forme, std::string culture);

    //getter
    std::string getTypeCulture() const ;
    float getSurfaceConstruite() const;

    //setter
    void setTypeCulture(std::string &culture);
    void setSurfaceConstruite(float &aire);

    // construire une zone agricole
    void construireBatiment();

    // surcharge opérateur pour le display
    void print(std::ostream& os) const // Indirection pour l'opérateur <<
    {
        os << "Parcelle n: " << getNumero() << '\n';
        os << "Type: " << getType() << '\n';
        os << "Polygone: " << getForme() << '\n';
        os << "Propriétaire: " << getProprietaire() << '\n';
        os << "Surface: " << getSurface()<<'\n';
        os<< "TypeCulture: "<< getTypeCulture()<<'\n';
    }
};