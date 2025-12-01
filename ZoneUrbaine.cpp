// Bibliothèques
#include "ZoneUrbaine.hpp"
#include "Polygone.hpp"

// Classe zone urbaine (ZU). Une ZU est une parcelle déjà parteillement (ou totalement) construite.
ZoneUrbaine::ZoneUrbaine(string nom, string nom_fichier) : Parcelle(int num, string prop, Polygone<int, float> forme)
{
    // Paramètres
    float surfaceConstruite;

    // Constructeurs
    ZoneUrbaine();

    // Accesseurs
    getSurfaceConstruite() { return this->surfaceConstruite; }

    // Mutateurs
    setSurfaceConstruite(float surface) { this->surfaceConstruite = surface; }

    // Méthodes
    float SurfaceConstructible(float surface);
}
