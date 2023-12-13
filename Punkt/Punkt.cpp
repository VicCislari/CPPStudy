//
// Created by Victor Cislari on 11.05.23.
//

#include <iostream>
#include "Punkt.h"
using namespace std;

void Punkt::ausgabe(){
    cout << "x:" << this->x << "; y:" << this->y;
}

void Punkt::einlesen(){
    cout << "x: ";
    cin >> this->x;
    cout << "y: ";
    cin >> this->y;
}

double Punkt::abstand(Punkt *koordinate){
    return sqrt((double) (pow(this->x - koordinate->x, 2) + pow(this->y - koordinate->y, 2)));
}/**/