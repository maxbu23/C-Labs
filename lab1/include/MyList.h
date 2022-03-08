#pragma once
#include<iostream>
#include <initializer_list> 
#include <functional>

class MyNode{


    public:
    int _value;
    MyNode *_next;

    /////////////////////////////////////////////////////////////
    MyNode():_next(nullptr){};
    MyNode(int value):_value(value),_next(nullptr){};
    ////////////////////////////////////////////////////////////

    int val()const{
        return _value;
    };
    


};

class MyList{

    public:
    MyNode *_head;
    int _size;

    //////////////////////////////////////////////////////////////
    MyList():_head(nullptr),_size(0){
        std::cout<<"KONST: Domyslny"<<std::endl;
    };
    MyList(int n);
    MyList(std::initializer_list<int> list);
    MyList(std::function<int (MyNode*)> fun, int n);
    MyList(const MyList& list);
    MyList(MyList&& list);
    ~MyList();
    //////////////////////////////////////////////////////////////
    void initList(int size);
    void clear();
    void add(int x);
    bool empty()const;
    int size()const;
    void print()const;
};