///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include <ostream>
#include "ZoneAUrbaniser.hpp"
#include "ZoneUrbaine.hpp"
///
/// @brief Création d'une zone à urbaniser
/// @details Création d'une zone à urbaniser
///
ZoneAUrbaniser::ZoneAUrbaniser(int numero, std::string proprietaire, Polygone<int> forme,float surfaceConstruite, ZoneUrbaine zone) : ZoneUrbaine(numero, proprietaire, forme, surfaceConstruite)
{
    zone.setSurfaceConstruite(0);
}

///
/// @brief Méthode, surface constructible restante
/// @details Fonctions permettant de déterminer la surface constructible de la zone, renvoie la surface restante disponible pour la construction.
/// @param[in] zone Parcelle
///
float ZoneAUrbaniser::SurfaceConstructible(ZoneUrbaine zone)
{
    return zone.getSurface();
}

///
/// @brief Surchage <<
/// @details Surcharge de l'opérateur << pour l'affichage des informations d'une zone à urbaniser.
/// @param[in] z ZoneUrbaine
///
std::ostream& operator<<(std::ostream& os, ZoneAUrbaniser const& z)
{
    float surfaceTotale = z.getForme().getSurface();
    float surfaceConstruite = z.getSurfaceConstruite();
    os << "Parcelle n°" << z.getNumero() << " :" << "\n";
    os << "     Type : Zone à urbaniser \n";
    os << "     Propriétaire: " << z.getProprietaire() << "\n";
    os << "     Surface totale: " << surfaceTotale << "\n";
    os << "     Surface constructible: " << (surfaceTotale - surfaceConstruite) << "\n";
    return os;
}