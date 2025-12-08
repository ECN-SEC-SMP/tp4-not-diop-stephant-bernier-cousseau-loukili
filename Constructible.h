#include <iostream>
#include "Polygone.hpp"


class Constructible {
    private: 
    bool isConstructible;

    public:
    float CalculSurface(Polygone<int> forme);
    //fonction virtuelle pure
    virtual float surfaceConstructible() = 0;

};