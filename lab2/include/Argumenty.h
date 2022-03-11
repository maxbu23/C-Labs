#pragma once
#include <vector>
#include <iostream>

class Argumenty{

  friend class Suma;
  friend class Pierwiastek;
  private:
  std::vector<double> args;

  public:
  int _size;
  Argumenty(int n){
      _size = n;
      args.resize(n);
  }

  Argumenty& operator()(int index, double value){
      args[index] = value;
        return *this;
  }  

  void print(std::string s)const{
      std::cout<<s<<" ";
      for(auto i:args){
          std::cout<<i<<" ";
      }
      std::cout<<std::endl;
  }

  void print(std::string s, std::ostream &os){
      std::cout<<s<<" ";
      for(auto i:args){
          std::cout<<i<<" ";
      }
      std::cout<<std::endl;
  }
};