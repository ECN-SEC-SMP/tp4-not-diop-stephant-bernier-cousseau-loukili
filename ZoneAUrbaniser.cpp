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
ZoneAUrbaniser::ZoneAUrbaniser(int numero, std::string proprietaire, Polygone<int> forme,float surfaceConstructible) : ZoneUrbaine(numero, proprietaire, forme, 0)
{
    constructible = surfaceConstructible;
}

///
/// @brief Méthode, surface constructible restante
/// @details Fonctions permettant de déterminer la surface constructible de la zone, renvoie la surface restante disponible pour la construction.
/// @param[in] zone Parcelle
///
float ZoneAUrbaniser::surfaceConstructible()
{
    return constructible;
}

///
/// @brief Surchage <<
/// @details Surcharge de l'opérateur << pour l'affichage des informations d'une zone à urbaniser.
/// @param[in] z ZoneUrbaine
///
void ZoneAUrbaniser::print(std::ostream& os) const
{
    float surfaceTotale = getForme().getSurface();
    float surfaceConstruite = getSurfaceConstruite();
    os << "Parcelle n°" << getNumero() << " :" << "\n";
    os << "     Type : Zone à urbaniser \n";
    os << "     Propriétaire: " << getProprietaire() << "\n";
    os << "     Surface totale: " << surfaceTotale << "\n";
    os << "     Surface constructible: " << (surfaceTotale - surfaceConstruite) << "\n";
}