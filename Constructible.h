#include <iostream>
#include "Polygone.hpp"


class Constructible {
    private: 
    bool isConstructible;

    public:
    //fonction virtuelle pure
    virtual float surfaceConstructible() = 0;

};