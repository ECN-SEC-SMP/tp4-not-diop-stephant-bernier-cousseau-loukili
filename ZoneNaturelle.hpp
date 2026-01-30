#pragma once

#include <iostream>
#include <string>
#include "Parcelle.hpp"


/// @brief classe ZoneNaturelle, fille de la classe Parcelle
class ZoneNaturelle : public Parcelle
{
public:
    ZoneNaturelle(int ZN_numero, std::string &ZN_proprietaire, Polygone<int> forme): Parcelle(ZN_numero, ZN_proprietaire, forme){};

    std::string getType()const{
        return "ZN";
    }

    void print(std::ostream& os) const override    // Indirection pour l'opérateur <<
    {
        os << "Parcelle n: " <<  getNumero() << '\n';
        os << "Type: " << getType() << '\n';
        os << "Polygone: " << getForme() << '\n';
        os << "Propriétaire: " << getProprietaire() << '\n';
        os << "Surface: " << getSurface();
    }
};
