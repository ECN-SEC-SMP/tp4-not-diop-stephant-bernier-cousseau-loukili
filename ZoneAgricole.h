#include <iostream>
using namespace std;

#include "ZoneNaturelle.h"
#include "Constructible.h"

//la classe ZoneAgricole hérite de la classe ZoneNaturelle
class ZoneAgricole:public ZoneNaturelle, public Constructible{
    private:
    string typeCulture; //type de culture (céréales, légumes, etc.)

    public:
    //constructeur
};