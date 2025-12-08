///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include "Polygone.hpp"
#include <iostream>
#include <cmath> // Pour std::abs

// Constructeurs

// + Polygone()
///
/// @brief Création d'un polygone
/// @details Création d'un polygone
/// @param[in]  sommets vector<Point2D<T>>
///
template <typename T>
Polygone<T>::Polygone() : sommets() {}

// + Polygone(Vector<Point2D<T>> listeSommets)
///
/// @brief Création d'un polygone
/// @details Création d'un polygone à partir d'une liste de sommets'
/// @param[in]  listeSommets vector<Point2D<T>>
///
template <typename T>
Polygone<T>::Polygone(const std::vector<Point2D<T>> &listeSommets)
{
    this->sommets = listeSommets; // Copie des Point2D
}

// + Polygone(Polygone<T> poly) (Constructeur de copie)
///
/// @brief Création d'un polygone
/// @details Création d'un polygone à partir d'une copie profonde
/// @param[in]  poly Polygone<T>
///
template <typename T>
Polygone<T>::Polygone(const Polygone<T> &poly)
{
    // Création d'une copie profonde des sommets
    for (const auto &point : poly.sommets)
    {
        // Utilise le constructeur de copie de Point2D
        sommets.push_back(point);
    }
}

// Méthodes d'accès et de modification
// + getSommets() : Vector<Point2D<T>>
///
/// @brief Accesseurs
/// @details Fonctions permettant l'accès aux différents paramètres d'un polygone.
///
template <typename T>
std::vector<Point2D<T>> Polygone<T>::getSommets() const
{
    return sommets; // Retourne une copie
}

// + setSommets(Vector<Point2D<T>> listeSommets) : void
///
/// @brief Mutateurs
/// @details Fonctions permettant la modification des sommets à partir d'une liste de sommets.
///
template <typename T>
void Polygone<T>::setSommets(const std::vector<Point2D<T>> &listeSommets)
{
    this->sommets = listeSommets;
}
// + getSurface() : float
///
/// @brief Accesseurs
/// @details Fonctions permettant de récupérer la surface d'un polygone.
///
template <typename T>
double Polygone<T>::getSurface() const
{
    // La méthode accède directement aux attributs internes (this->sommets) sans avoir besoin d'appeler getSommets() sur elle-même
    int n = sommets.size();

    // Vérification minimale (moins de 3 sommets = surface nulle)
    if (n < 3)
    {
        return 0.0;
    }

    double surface = 0.0;

    for (int i = 0; i < n; i++)
    {
        // Accès direct aux sommets internes
        const Point2D<T> &p1 = sommets[i];
        const Point2D<T> &p2 = sommets[(i + 1) % n];

        double x1 = static_cast<double>(p1.getX());
        double y1 = static_cast<double>(p1.getY());
        double x2 = static_cast<double>(p2.getX());
        double y2 = static_cast<double>(p2.getY());

        // Formule du lacet : (x1 * y2) - (x2 * y1)
        surface += (x1 * y2) - (x2 * y1);
    }

    // Retourne la valeur absolue de la surface divisée par 2.0
    return std::abs(surface) / 2.0;
}

// + addPoint(Point2D<T> p) : void
///
/// @brief Méthode, ajout d'un point
/// @details Fonctions permettant l'ajout d'un point dans un polygone.
/// @param[in] p Point2D<T>
///
template <typename T>
void Polygone<T>::addPoint(const Point2D<T> &p)
{
    sommets.push_back(p);
}

// Méthode de Transformation

// + translate(T x, T y) : void
///
/// @brief Méthode, translation
/// @details Fonctions permettant la translation d'un polygone, en fonction de coordonnées en x et en y.
/// @param[in] dx T
/// @param[in] dy T
///
template <typename T>
void Polygone<T>::translate(T dx, T dy)
{
    // Délègue la translation à chaque Point2D
    for (auto &point : sommets)
    {
        point.translate(dx, dy);
    }
}