#pragma once
#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::function;
using std::cout;
using std::endl;

class List{

public:

    vector<int> _vec;
    /**
     * @brief 
     * funckja dodaje wartosc typu int na koniec wektora _vec
     */
    void insert(int x){
        _vec.push_back(x);
    }

    /**
     * @brief
     * funkcja drukuje wartosc parametru s a nastepnie wszystkie wartosci wektora _vec 
     */
    void print(std::string s)const{
        cout<<s<<"[ ";
        for(auto i:_vec)
            cout<<i<<" ";
        
        cout<<"]"<<endl;
    }

    /**
     * @brief
     * funkcja drukuje wszytskie wartosci wektora _vec
     */
    void print()const{
        cout<<"[ ";
        for(auto i:_vec)
            std::cout<<i<<" ";
        
        cout<<"]"<<endl;
    }

    /**
     * @brief 
     * operator[] zwracajacy referencje do wartosci znajdujacej sie w wektorze _vec pod podanym indexem
     */
    int& operator[](int index){
        return _vec[index];
    }

    /**
     * @brief 
     * funkcja zwracajaca nowy obiekt typu List, ktory przechowuje wartosci przefiltorwane z listy na rzecz ktorej
        ta funkcja zostala wywolana, filtrowaniem zajmuje sie funkcja podana jako parametr metody 
     */
    List filter(function<bool(int)> f){
        List newList;
        for(auto i:_vec){
            if(f(i)){
                newList.insert(i);
            }
        }
        return newList;
    }

};