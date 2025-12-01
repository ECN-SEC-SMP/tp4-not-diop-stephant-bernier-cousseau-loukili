///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include "ZoneUrbaine.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"

///
/// @brief Création d'une zone urbaine
/// @details Création d'une zone urbaine, en fonction de la surface déjà construite
/// @param[in]  surfaceConstruite float
///
ZoneUrbaine::ZoneUrbaine(float surfaceConstruite)
{
    this->surfaceConstruite = surfaceConstruite;
}

///
/// @brief Création d'une zone urbaine
/// @details Création d'une zone urbaine, avec une zone construite nulle
/// @param[in]  surfaceConstruite float
///
ZoneUrbaine::ZoneUrbaine(Polygone zone)
{
    this->surfaceConstruite = 0;
}

///
/// @brief Accesseurs
/// @details Fonctions permettant l'accès aux différents paramètres d'une zone urbaine.
///
float ZoneUrbaine::getSurfaceConstruite() const { return this->surfaceConstruite; }

///
/// @brief Mutateurs
/// @details Fonctions permettant la modification des différents paramètres d'une zone.
///
void ZoneUrbaine::setSurfaceConstruite(float surface) { this->surfaceConstruite = surface; }

///
/// @brief Méthode, surface constructible restante
/// @details Fonctions permettant de déterminer la surface constructible de la zone, renvoie la surface restante disponible pour la construction.
/// @param[in] surface Parcelle
///
float ZoneUrbaine::SurfaceConstructible(Parcelle zone)
{
    float surfaceConstructible = zone.getSurface() - this->surfaceConstruite;
    return surfaceConstructible;
}