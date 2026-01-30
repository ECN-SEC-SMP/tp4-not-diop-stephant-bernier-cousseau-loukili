#ifndef ZONEAURBANISER_HPP
#define ZONEAURBANISER_HPP

#include <ostream>
#include "ZoneUrbaine.hpp"

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
class ZoneAUrbaniser : public ZoneUrbaine
{
private:
    float constructible = 0;
public:

    // Constructeurs
    ZoneAUrbaniser(int numero, std::string proprietaire, Polygone<int> forme,float surfaceConstructible);

    // Accesseurs

    // Mutateurs

    // Méthodes
    float surfaceConstructible() override;

    // Surcharge
    void print(std::ostream& os) const override;    // Indirection pour l'opérateur <<
};

#endif