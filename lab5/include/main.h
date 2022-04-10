#pragma once
#include "ClosedShape.h"

/**
 * Klasy abstrakcyjne Drawable i Transformable sa klasami bazowymi dla klas ClosedShape(ktora tez jest wirtualna,
 ale posiada dodatkowa metode area()) oraz Section. Klasy Circle oraz Deltoid dziedzicza po klasie ClosedShape,a nie
 bezposrednio po Drawable i Transformable poniewaz potrzebuja jeszcze posiadac metode area() ktora nie jest potrzebna w klasie
 Section, poniewaz nie mozna zdefiniowac pola powierzchni dla odcinka
 * 
 */