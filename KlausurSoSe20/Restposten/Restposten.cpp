//
// Created by Victor Cislari on 22.07.23.
//

#include "Restposten.h"
#include <iostream>
using namespace std;

void Restposten::set_rabatt(double rabatt) {
    if(rabatt>=0 && rabatt<=100){
        this->rabatt = rabatt;
    }
}

double Restposten::get_rabatt() const {
    return rabatt;
}

Restposten::Restposten(const char* bezeichnung, double preis, int vorrat, double rabatt):
Lagerware(bezeichnung, preis, vorrat), rabatt(0){
    set_rabatt(rabatt);
}

Restposten::Restposten(const Restposten& orig):
Lagerware(orig), rabatt(0) {
    set_rabatt(orig.rabatt);
}

Restposten& Restposten::operator=(const Restposten& orig){
    Lagerware::operator=(orig);
    set_rabatt(orig.rabatt);
    return *this;
}

void Restposten::info() const {
    Lagerware::info();
    cout << "rabatierter Preis: " << get_preis()*(1-rabatt/100) << endl;
}














