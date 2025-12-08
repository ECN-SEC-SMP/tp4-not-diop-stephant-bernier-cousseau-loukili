#include "ZoneNaturelle.h"

/// @brief Constructeur
/// @details Fixe les valeurs par défauts des différents attributs
ZoneNaturelle::ZoneNaturelle(){
    typeParcelle = "ZN";
    pConstructible = 0% //les ZN sont non constructibles
}

/// @brief Constructeur
/// @details Fixe les 
ZoneNaturelle::ZoneNaturelle(int ZN_numero, const std::string &ZN_proprietaire){
    this->numero = ZN_numero;
    this->proprietaire = ZN_proprietaire;
}
²