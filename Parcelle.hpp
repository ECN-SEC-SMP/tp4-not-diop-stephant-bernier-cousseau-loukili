#pragma once

#include <string>

#include "Polygone.hpp"

class Parcelle {
private:
    int numero;
    std::string proprietaire;
    float surface;
    Polygone<int, float> forme;

protected:
    Parcelle(int numero, std::string proprietaire, float surface, Polygone<int, float> forme);

public:
    int getNumero();
    std::string getProprietaire();
    float getSurface();
    const Polygone<int, float>& getForme() const;

    void setNumero(int numero);
    void setProprietaire(std::string proprietaire);
    void setForme(Polygone<int, float> forme);
};