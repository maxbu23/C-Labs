#pragma once
#include "Argumenty.h"

class Algo{

    public:
    Algo(){}
    virtual Argumenty wykonaj(const Argumenty& arg){
        return arg;
    }

    virtual Algo* sklonuj()const{
        return new Algo;
    }

};