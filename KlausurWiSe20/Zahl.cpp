//
// Created by Victor Cislari on 23.07.23.
//

#include "Zahl.h"
using namespace std;

Zahl::Zahl(int wert):Knoten(nullptr, nullptr){
    if(wert>=0 && wert <= 100)
        this->wert = wert;
    else
        throw out_of_range("Zahlen können nur im natürlichen Bereich von 0 bis 100 erzeugt werden.");
    this->wert=wert;
}

double Zahl::get_wert(){
    return wert;
}

std::ostream& Zahl::print(std::ostream& out) const{
    out<<wert;
    return out;
}

