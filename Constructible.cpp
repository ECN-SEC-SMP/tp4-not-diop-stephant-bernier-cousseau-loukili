#include <iostream>
#include <vector>
using namespace std;
#include "Constructible.h"


//definition de la fonction CalculSurface
float Constructible::CalculSurface(Polygone<float> forme){
    sommets= forme.getSommets( ) ;//je récupère les sommets du polyhone depuis la classe Polygone
    //sommets est un vecteur de points
    float surface =0.0;
    int n = sommets.size();
    for(int i=0; i<n; i++){
        Point<float> p1;
        Point<float> p2;
        //Deux sommets consécutifs
        p1 = sommets[i];
        p2 = sommets[(i+1)]; //le point suivant, en bouclant
        //formule du calcul de la surface du polygone
        surface += (p1.getX() * p2.getY()) - (p2.getX() * p1.getY());
    }

    return abs(surface) / 2.0;
}
