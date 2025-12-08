///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include <ostream>
#include "ZoneUrbaine.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"

///
/// @brief Création d'une zone urbaine
/// @details Création d'une zone urbaine, en fonction de la surface déjà construite
/// @param[in]  surfaceConstruite float
///
ZoneUrbaine::ZoneUrbaine(int numero, std::string proprietaire, Polygone<int> forme,float surfaceConstruite) : Parcelle(numero, proprietaire, forme)
{
    this->surfaceConstruite = surfaceConstruite;
}

///
/// @brief Création d'une zone urbaine
/// @details Création d'une zone urbaine, avec une zone construite nulle
/// @param[in]  surfaceConstruite float
///
ZoneUrbaine::ZoneUrbaine(int numero, std::string proprietaire, Polygone<int> forme) : Parcelle(numero, proprietaire, forme)
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
float ZoneUrbaine::SurfaceConstructible(Polygone<int> zone)
{
    float surfaceConstructible = zone.getSurface() - this->surfaceConstruite;
    return surfaceConstructible;
}

///
/// @brief Surchage <<
/// @details Surcharge de l'opérateur << pour l'affichage des informations d'une zone urbaine.
/// @param[in] z ZoneUrbaine
///
std::ostream& operator<<(std::ostream& os, ZoneUrbaine const& z)
{
    float surfaceTotale = z.getForme().getSurface();
    float surfaceConstruite = z.getSurfaceConstruite();
    os << "Parcelle n°" << z.getNumero() << " :" << "\n";
    os << "     Type : Zone Urbaine \n";
    os << "     Propriétaire: " << z.getProprietaire() << "\n";
    os << "     Surface totale: " << surfaceTotale << "\n";
    os << "     Surface construite: " << surfaceConstruite << "\n";
    os << "     Surface constructible: " << (surfaceTotale - surfaceConstruite) << "\n";
    return os;
}