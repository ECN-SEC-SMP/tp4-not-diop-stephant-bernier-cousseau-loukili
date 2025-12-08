#include <algorithm>
#include "ZoneAgricole.h"

/// @brief Constructeur par défaut
/// @details valeurs par défaut des attributs
ZoneAgricole::ZoneAgricole()
{
    surfaceConstruite = 0; // Pour la règle des 10% et du 200m²
    typeParcelle = "ZA";
    typeCulture = " ";
}

/// @brief Constructeur avec un param
/// @details valeur du type de culture
ZoneAgricole::ZoneAgricole(std::string culture) : typeCulture(culture) {}

/// @brief getter
/// @details valeur du type de culture
std::string ZoneAgricole::getTypeCulture() const
{
    return typeCulture;
}

/// @brief getter
/// @details valeur de la surface déjà construite
float ZoneAgricole::getSurfaceConstruite() const
{
    return surfaceConstruite;
}

/// @brief setter
/// @details le type de culture pour ZA
void ZoneAgricole::setTypeCulture(std::string &culture)
{
    typeCulture = culture;
}

/// @brief setter
/// @details valeur de la surface construite
void ZoneAgricole::setSurfaceConstruite(float& aire){
    surfaceConstruite = aire;
}

// @brief Méthode, construire un bâtiment
/// @details Permet de construire un bâtiment dans une zone agricole à condition que la
/// surface construite ne dépasse pas 10% de la surface de la ZA et 200m2 au maximum
///(chiffres fictifs).
void ZoneAgricole::construireBatiment()
{
    float surface_bat;
    float surface_zone;
    surface_zone = getSurface();
    std::cout << "Quelle est la surface du batiment que vous souhaitez construire ?";
    std::cin >> surface_bat;

    if (surface_bat + surfaceConstruite <= std::min(0.1 * surface_zone, 200))
    {
        std::cout << "construction OK";
    }
    else
    {
        std::cout << "Construction impossible";
        if (surface_bat + surfaceConstruite > 0.1 * surface_zone)
            std::cout << "surface supérieure à 10% de la ZA. ";
        if (surface_bat + surfaceConstruite > 200)
            std::cout << "surface supérieure à 200 m².";
        std::cout << "\n";
    }
}