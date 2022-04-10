#pragma once
#include <functional>
#include <vector>

using std::function;
using std::vector;

class FilterCriteria{

public:
    vector<function<bool(int)>> _vec;

    /**
     * @brief 
     * dodaje funckje do wektora 
     */
    void add(function<bool(int)> f){
        _vec.push_back(f);
    }

    /**
     * @brief 
     * zwraca romiar wektora przechowywujacego kryteria(funkcje)
     */
    int size()const{
        return _vec.size();
    }


    /**
     * @brief 
     * zwraca kryterium(funkcje), ktore znajduje sie pod podanym indeksem
     * 
     */
    function<bool(int)> get(int index){
        return _vec[index];
    }


};