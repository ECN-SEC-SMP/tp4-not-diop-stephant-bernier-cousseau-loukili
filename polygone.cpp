#include "Polygone.h"
#include <iostream>

// Constructeurs

// + Polygone()
template <typename T>
Polygone<T>::Polygone() : sommets() {}

// + Polygone(Vector<Point2D<T>> listeSommets)
template <typename T>
Polygone<T>::Polygone(const std::vector<Point2D<T>>& listeSommets) {
    this->sommets = listeSommets; // Copie des Point2D
}

// + Polygone(Polygone<T> poly) (Constructeur de copie)
template <typename T>
Polygone<T>::Polygone(const Polygone<T>& poly) {
    // Création d'une copie profonde des sommets
    for (const auto& point : poly.sommets) {
        // Utilise le constructeur de copie de Point2D
        sommets.push_back(point); 
    }
}

// Méthodes d'accès et de modification
// + getSommets() : Vector<Point2D<T>>
template <typename T>
std::vector<Point2D<T>> Polygone<T>::getSommets() const {
    return sommets; // Retourne une copie
}

// + setSommets(Vector<Point2D<T>> listeSommets) : void
template <typename T>
void Polygone<T>::setSommets(const std::vector<Point2D<T>>& listeSommets) {
    this->sommets = listeSommets;
}

// + addPoint(Point2D<T> p) : void
template <typename T>
void Polygone<T>::addPoint(const Point2D<T>& p) {
    sommets.push_back(p);
}

//Méthode de Transformation 

// + translate(T x, T y) : void
template <typename T>
void Polygone<T>::translate(T dx, T dy) {
    // Délègue la translation à chaque Point2D
    for (auto& point : sommets) {
        point.translate(dx, dy);
    }
}