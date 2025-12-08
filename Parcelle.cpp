#include "Parcelle.hpp"

Parcelle::Parcelle(int numero, std::string proprietaire, Polygone<int> forme) {
    this->numero = numero;
    this->proprietaire = proprietaire;
    setForme(forme);
}

int Parcelle::getNumero() const{
    return numero;
}

std::string Parcelle::getProprietaire() const{
    return proprietaire;
}
float Parcelle::getSurface() const{
    return forme.getSurface();
}

const Polygone<int>& Parcelle::getForme() const {
    return forme;
}

void Parcelle::setNumero(int numero) {
    this->numero = numero;
}

void Parcelle::setProprietaire(std::string proprietaire) {
    this->proprietaire = proprietaire;
}

void Parcelle::setForme(Polygone<int> forme) {
    this->forme = forme;
}