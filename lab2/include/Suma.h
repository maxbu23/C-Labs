#pragma once
#include <iostream>
#include "Algo.h"

class Suma:public Algo{

    public:
    Argumenty wykonaj(const Argumenty& arg){
        double sum = 0;

        for(auto i:arg.args){
            sum += i;
        }

        Argumenty a(1);
        a(0,sum);
        return a;

    }   

    Suma* sklonuj()const{
        return new Suma;
    }

};