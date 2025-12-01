#include "Parcelle.hpp"

Parcelle::Parcelle(int numero, std::string proprietaire, Polygone<int, float> forme) {
    this->numero = numero;
    this->proprietaire = proprietaire;
    setForme(forme);
}

int Parcelle::getNumero() {
    return numero;
}

std::string Parcelle::getProprietaire() {
    return proprietaire;
}
float Parcelle::getSurface() {
    return surface;
}

const Polygone<int, float>& Parcelle::getForme() const {
    return forme;
}

void Parcelle::setNumero(int numero) {
    this->numero = numero;
}

void Parcelle::setProprietaire(std::string proprietaire) {
    this->proprietaire = proprietaire;
}

void Parcelle::setForme(Polygone<int, float> forme) {
    this->forme = forme;
    this->surface = forme.getSurface();
}