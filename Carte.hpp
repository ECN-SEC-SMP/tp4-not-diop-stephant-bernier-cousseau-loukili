#pragma once

#include <vector>
#include <string>
#include "Parcelle.hpp"

/**
 * @brief Carte regroupe des parcelles et permet d'en afficher la liste
 * 
 */
class Carte {
private:
    std::vector<Parcelle*> listeParcelles;

public:
    /**
     * @brief Construit un nouvel objet Carte
     * 
     */
    Carte();
    /**
     * @brief Construit un nouvel objet Carte depuis un fichier
     * 
     * @param nomFichier Chemin vers le fichier à charger
     */
    Carte(std::string& nomFichier);

    /**
     * @brief Destroy the Carte object
     * 
     */
    ~Carte();

    /**
     * @brief Permet d'ajouter une parcelle à la Carte
     * 
     * @param parcelle Pointeur vers la parcelle à ajouter
     */
    void ajouterParcelle(Parcelle* parcelle);
    /**
     * @brief Permet de retirer une parcelle de la Carte
     * 
     * @param parcelle 
     */
    void retirerParcelle(Parcelle* parcelle);
    /**
     * @brief Affiche chaque parcelle
     * 
     */
    void afficher();
    /**
     * @brief Calcule la surface totale des zones de la carte
     * 
     * @return float Surface totale
     */
    float surfaceTotale();
};