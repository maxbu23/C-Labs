#pragma once

class DivisibleBy{

public:
    int _value;
    DivisibleBy(int value):_value(value){}

    /**
     * @brief 
     * zwraca wartosc true gdy _value jest podzielne przez wartosc podana przez parametr x oraz 
     * false w przeciwnym wypadku 
     */
    bool operator()(int x){
        return x%_value == 0;
    }

};

class GreaterThan{

public:
    int _value;
    GreaterThan(int value):_value(value){}

    /**
     * @brief 
     * zwraca wartosc true gdy _value jest mniejsze od wartosci podanej przez parametr x oraz 
     * false w przeciwnym wypadku 
     */
    bool operator()(int x){
        return x>_value;
    }

};