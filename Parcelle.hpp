#pragma once

#include <string>

#include "Polygone.hpp"

class Parcelle {
private:
    int numero;
    std::string proprietaire;
    Polygone<int> forme;

protected:
    /**
     * @brief Construit un nouvel objet Parcelle.
     *        Ce constructeur n'est pas appelable directement, il faut instancier l'une des classes filles
     * 
     * @param numero Numéro de la parcelle
     * @param proprietaire Nom du propriétaire
     * @param forme Forme de la parcelle
     */
    Parcelle(int numero, std::string proprietaire, Polygone<int> forme);

public:
    /**
     * @brief Accesseur pour le numero
     * 
     * @return int Numéro de la parcelle
     */
    int getNumero();

    /**
     * @brief Accesseur pour le nom du propriétaire
     * 
     * @return std::string Nom du propriétaire
     */
    std::string getProprietaire();

    /**
     * @brief Accesseur pour la surface de la parcelle
     * 
     * @return float Surface de la parcelle
     */
    float getSurface();

    /**
     * @brief Accesseur de la forme de la parcelle
     * 
     * @return const Polygone<int>& Référence vers la forme de la parcelle
     */
    const Polygone<int>& getForme() const;

    /**
     * @brief Mutateur pour le numéro de la parcelle
     * 
     * @param numero Le nouveau numéro
     */
    void setNumero(int numero);

    /**
     * @brief Mutateur pour le nom du propriétaire de la parcelle
     * 
     * @param proprietaire Le nouveau nom du propriétaire
     */
    void setProprietaire(std::string proprietaire);

    /**
     * @brief Mutateur pour la forme de la parcelle
     * 
     * @param forme Nouvelle forme de la parcelle
     */
    void setForme(Polygone<int> forme);
};