#pragma once

class Drawable{

public:
    virtual void draw()const=0;
    virtual double length()const=0;

};

class Transformable{
public:
    virtual void shift(double x, double y)=0;
};

class ClosedShape:public Drawable, public Transformable{
public:
    virtual double area()const=0;
};