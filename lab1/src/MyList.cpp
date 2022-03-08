#include <iostream>
#include "MyList.h"

MyList::MyList(int n):MyList(){
    std::cout<<"KONST: Jednoargumentowy"<<std::endl;
    this -> _size = n;
    if(_size!=0)
        _head = new MyNode(0); 
    MyNode *iterator = _head;
    for(int i=1; i<n; i++){
        iterator -> _next = new MyNode(i);
        iterator = iterator -> _next;
    }

}
MyList::MyList(std::initializer_list<int> list):MyList(){
    std::cout<<"KONST: std::initializer_list"<<std::endl;
    for(int value:list){
        add(value);
    }
}
MyList::MyList(std::function<int (MyNode*)> fun, int n){
    std::cout<<"KONST: funkcja generujaca"<<std::endl;
    _head = nullptr;
    _head = new MyNode(fun(_head));
    _size = n;

    MyNode *iterator = _head;
    for(int i = 1; i<n; i++){
        iterator -> _next = new MyNode(fun(iterator));
        iterator = iterator -> _next;
    }
}

//konstruktor kopiujacy
MyList::MyList(const MyList& list):MyList(){
    std::cout<<"KONST: kopiujacy"<<std::endl;
    MyNode *iteratorList =list._head;
    this -> _size = list._size;
    if(_size!=0)
        _head = new MyNode(list._head->_value); 
    MyNode *iterator = _head;
    for(int i=1; i<_size; i++){
        iteratorList = iteratorList -> _next;
        iterator -> _next = new MyNode(iteratorList->_value);
        iterator = iterator -> _next;
    }
}

MyList::MyList(MyList&& list){
    std::cout<<"KONST: przenoszacy"<<std::endl;
    _size = std::exchange(list._size,0);
    _head = std::exchange(list._head,nullptr);
}

MyList::~MyList(){
    std::cout<<"DESTRUKTOR (rozmiar = "<<_size<<")"<<std::endl;
    
    MyNode *iterator = _head;
    MyNode *next;

    while(iterator!= nullptr){
        next = iterator -> _next;
        delete iterator;
        iterator = next;
    }

    _head = nullptr;
    _size = 0;

}
//////////////////////////////////////////////////////////////

void MyList::clear(){
    MyNode *iterator = _head;
    MyNode *next;

    while(iterator!= nullptr){
        next = iterator -> _next;
        delete iterator;
        iterator = next;
    }

    _head = nullptr;
    _size = 0;
}
void MyList:: add(int x){

    if(_head == nullptr){
        _head = new MyNode(x);
        _size ++;
    }else{
        MyNode *iterator = _head;
        while(iterator->_next != nullptr){
        
            iterator = iterator->_next;
        }
        iterator -> _next = new MyNode(x);
        _size ++;
        }
}

bool MyList::empty()const{

    return _head == nullptr;

}
int MyList::size()const{
    return _size;
}
void MyList::print()const{
    MyNode *currentNode = _head;
    std::cout<<"[";
    while(currentNode != nullptr)
    {   
        if(currentNode -> _next == nullptr){
            std::cout<<currentNode->_value;
        }else{
            std::cout<<currentNode->_value<<", ";
            
        }
        currentNode = currentNode -> _next;
    }
    std::cout<<"]\n";
    
}