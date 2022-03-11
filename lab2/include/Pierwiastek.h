#pragma once
#include <iostream>
#include <cmath>

class Pierwiastek:public Algo{

    public:
    

    Argumenty wykonaj(const Argumenty &arg)const{

        Argumenty a(arg._size);
        int counter =0;
        for(auto i:arg.args){
            double sqr = sqrt(i);
            a(counter,sqr);
            counter ++;
        }
        return a;
    }

    Pierwiastek* sklonuj()const{
        return new Pierwiastek;
    }


};