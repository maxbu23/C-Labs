#pragma once
#include <cmath>
#include "Interface.h"

class Point{

private:
    double _x;
    double _y;
public:
    Point(){}
    Point(double x, double y):_x(x),_y(y){}

    void setX(double x){
        this->_x = x;
    }
    void setY(double y){
        this->_y = y;
    }
    double getX()const{
        return this->_x;
    }
    double getY()const{
        return this->_y;
    }
};

std::ostream& operator<<(std::ostream &os, const Point &p){
    os<<"("<<p.getX()<<", "<<p.getY()<<")";
    return os;
}

class Section:public Drawable, public Transformable{

private:
    Point _a;
    Point _b;
public:
    Section(){}
    Section(Point a, Point b):_a(a),_b(b){}

    void draw()const{
        std::cout<<"Rysujemy odcinek od "<<_a<<" do "<<_b<<std::endl;
    }
    double length()const{
        double l = sqrt(pow(_a.getX()-_b.getX(),2) +pow(_a.getY()-_b.getY(),2));
        return l;
    }
    void shift(double x, double y){
        _a.setX(_a.getX() + x);
        _b.setX(_b.getX() + x);
        _a.setY(_a.getY() + y);
        _b.setY(_b.getY() + y);
    }

    Point getA(){
        return _a;
    }

    Point getB(){
        return _b;
    }
};

class Circle: public ClosedShape{

private:
    Point _p;
    double _radius;
public:
    Circle(Point p, double r):_p(p),_radius(r){}
    void draw()const{
        std::cout<<"Rysujemy kolo o srodku "<<_p<<" i promieniu "<<_radius<<std::endl;
    }
    double length()const{
        return 2*3.1415*_radius;
    }
    void shift(double x, double y){
        _p.setX(_p.getX() + x);
        _p.setY(_p.getY() + y);
    }
    double area()const{
        return 3.1415*pow(_radius,2);
    }
};

class Deltoid : public ClosedShape{

private:
    Point _p1;
    Point _p2;
    Point _p3;
    Point _p4;
    Section _d1;
    Section _d2;
public:
    Deltoid(Point p1,Point p2,Point p3,Point p4):_p1(p1),_p2(p2),_p3(p3),_p4(p4){
        Section d1(_p1,_p3);
        _d1 = d1;
        Section d2(_p2,_p4);
        _d2 = d2;
    }
    Deltoid(Section d1, Section d2):_d1(d1),_d2(d2){
        _p1 = _d1.getA();
        _p3 = _d1.getB();
        _p2 = _d2.getA();
        _p4 = _d2.getB();
    }

    void draw()const{
        std::cout<<"Rysujemy deltoid o wierzcholkach "<<_p1<<", "<<_p2<<", "<<_p3<<", "<<_p4<<std::endl;
    }
    double length()const{
        Section s1(_p1,_p2);
        Section s2(_p2,_p3);
        Section s3(_p3,_p4);
        Section s4(_p4,_p1);
    
        
        return s1.length() + s2.length() + s3.length() + s4.length();
    }
    void shift(double x, double y){
        _p1.setX(_p1.getX()+x);
        _p1.setY(_p1.getY()+y);
        _p2.setX(_p2.getX()+x);
        _p2.setY(_p2.getY()+y);
        _p3.setX(_p3.getX()+x);
        _p3.setY(_p3.getY()+y);
        _p4.setX(_p4.getX()+x);
        _p4.setY(_p4.getY()+y);
    }
    double area()const{
        double a = _d1.length() * _d2.length();
        return a;
    }
};

void draw(Drawable *d){
    d->draw();
}