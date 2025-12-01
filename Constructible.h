#include <iostream>
#include "Polygone.h"


class Constructible {
    private: 
    bool isConstructible;

    public:
    float CalculSurface(Polygone<int, float> forme);
    //fonction virtuelle pure
    virtual float surfaceConstructible = 0;

};