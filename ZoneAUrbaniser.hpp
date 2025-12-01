#ifndef ZONEAURBANISER_HPP
#define ZONEAURBANISER_HPP

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
class ZoneAUrbaniser : public Parcelle
{
public:
    // Paramètres
    float surfaceConstruite;

    // Constructeurs
    ZoneAUrbaniser();
    ZoneAUrbaniser(float surfaceConstruite);

    // Accesseurs
    float getSurfaceConstruite() const; 

    // Mutateurs
    void setSurfaceConstruite(float surface);

    // Méthodes
    float SurfaceConstructible(float surface);
};

#endif