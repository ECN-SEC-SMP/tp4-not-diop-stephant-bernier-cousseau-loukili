#ifndef POLYGONE_H
#define POLYGONE_H
#include <vector>
#include "Point2D.h" 

/**
 * @class Polygone
 * @brief Représente un polygone générique composé d'une liste de sommets Point2D<T>.
 */
template <typename T>
class Polygone {
private:
    // - sommets : Vector<Point2D<T>> (Utilise std::vector en C++)
    std::vector<Point2D<T>> sommets;

public:
    // --- Constructeurs ---
    // + Polygone()
    Polygone();

    // + Polygone(Vector<Point2D<T>> listeSommets)
    Polygone(const std::vector<Point2D<T>>& listeSommets);

    // + Polygone(Polygone<T> poly) (Constructeur de copie)
    Polygone(const Polygone<T>& poly);

    // --- Méthodes d'Accès et de Modification ---
    // + getSommets() : Vector<Point2D<T>>
    std::vector<Point2D<T>> getSommets() const;

    // + setSommets(Vector<Point2D<T>> listeSommets) : void
    void setSommets(const std::vector<Point2D<T>>& listeSommets);

    // + getSurface() : float (nous utiliserons double pour plus de précision)
    double getSurface() const;

    // + addPoint(Point2D<T> p) : void
    void addPoint(const Point2D<T>& p);

    // --- Méthode de Transformation ---
    // + translate(T x, T y) : void
    void translate(T dx, T dy);
};

// Inclusion de l'implémentation (méthodes) pour les templates
// C'est une méthode courante pour contourner les problèmes de liaison.
#include "Polygone.cpp"

#endif // POLYGONE_H