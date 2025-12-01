#include "Parcelle.hpp"

#ifndef ZONEURBAINE_HPP
#define ZONEURBAINE_HPP

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
class ZoneUrbaine : public Parcelle, public Constructible
{
public:
    // Paramètres
    float surfaceConstruite;

    // Constructeurs
    ZoneUrbaine(Parcelle zone);
    ZoneUrbaine(float surfaceConstruite);

    // Accesseurs
    float getSurfaceConstruite() const; 

    // Mutateurs
    void setSurfaceConstruite(float surface);

    // Méthodes
    float SurfaceConstructible(Polygone zone);
};

#endif