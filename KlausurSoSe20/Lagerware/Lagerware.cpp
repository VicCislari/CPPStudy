//
// Created by Victor Cislari on 22.07.23.
//

#include "Lagerware.h"
#include <iostream>
using namespace std;

void Lagerware::set_preis(double neuer_preis){
    if(neuer_preis >= 0) preis = neuer_preis;
}

double Lagerware::get_preis() const {
    return preis;
}

void Lagerware::set_vorrat(int anzahl) {
    if(anzahl >= 0) vorrat = anzahl;
}

int Lagerware::get_vorrat() const {
    return vorrat;
}

Lagerware::Lagerware(const char* bezeichnung, double preis, int vorrat):
Ware(bezeichnung), preis(0), vorrat(0) {
    set_preis(preis); //wenn etwas definiert.
    set_vorrat(vorrat); //wenn etwas definiert.
}

Lagerware::Lagerware(const Lagerware &orig): Ware(orig), preis(0), vorrat(0) {
    set_preis(orig.preis);
    set_vorrat(orig.vorrat);
}

Lagerware& Lagerware::operator=(const Lagerware &orig) {
    Ware::operator=(orig);
    set_preis(orig.preis);
    set_vorrat(orig.vorrat);
    return *this;
}

void Lagerware::info() const {
    Ware::info(); //deswegen haben wir den override
    cout<<"Preis: "<<preis<< endl;
    cout<<"Vorrat: "<<vorrat<< endl;
}
















