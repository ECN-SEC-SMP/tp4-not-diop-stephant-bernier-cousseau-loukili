#pragma once

#include <iostream>
#include <string>
#include "Parcelle.hpp"


/// @brief classe ZoneNaturelle, fille de la classe Parcelle
class ZoneNaturelle : public Parcelle
{
private:
    std::string typeParcelle;

public:
    ZoneNaturelle(int ZN_numero, std::string &ZN_proprietaire, Polygone<int> forme): Parcelle(ZN_numero, ZN_proprietaire, forme){};

    std::string getType()const{
        return "ZN";
    }

    // surcharge opérateur pour le display
    friend std::ostream &operator<<(std::ostream &os,const ZoneNaturelle &ZN)
    {
        os << "Parcelle n: " <<  ZN.getNumero() << '\n';
        os << "Type: " << ZN.getType() << '\n';
        os << "Polygone: " << ZN.getForme() << '\n';
        os << "Propriétaire: " << ZN.getProprietaire() << '\n';
        os << "Surface: " << ZN.getSurface();

        return os;
    }
};
