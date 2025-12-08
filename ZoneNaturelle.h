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
    ZoneNaturelle();
    ZoneNaturelle(int ZN_numero, const std::string &ZN_proprietaire);

    // surcharge opérateur pour le display
    friend std::ostream &operator<<(std::ostream &os, const ZoneNaturelle &ZN)
    {
        os << "Parcelle n: " << ZN.getNumero() << '\n';
        os << "Type: " << ZN.getType() << '\n';
        os << "Polygone: " << ZN.getForme() << '\n';
        os << "Propriétaire: " << ZN.getProprietaire() << '\n';
        os << "Surface: " << ZN.getSurface();

        return os;
    }
};
