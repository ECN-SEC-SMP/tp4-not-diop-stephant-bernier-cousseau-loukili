#ifndef ZONEURBAINE_HPP
#define ZONEURBAINE_HPP

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
class ZoneUrbaine : public Parcelle
{
public:
    // Paramètres
    float surfaceConstruite;

    // Constructeurs
    ZoneUrbaine();
    ZoneUrbaine(float surfaceConstruite);

    // Accesseurs
    float getSurfaceConstruite() const; 

    // Mutateurs
    void setSurfaceConstruite(float surface);

    // Méthodes
    float SurfaceConstructible(float surface);
};

#endif