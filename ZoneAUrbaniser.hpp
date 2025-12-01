#include "ZoneUrbaine.hpp"

#ifndef ZONEAURBANISER_HPP
#define ZONEAURBANISER_HPP

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
class ZoneAUrbaniser : public ZoneUrbaine
{
public:
    // Paramètres

    // Constructeurs
    ZoneAUrbaniser(ZoneUrbaine zone);

    // Accesseurs

    // Mutateurs

    // Méthodes
    float SurfaceConstructible(ZoneUrbaine zone);
};

#endif