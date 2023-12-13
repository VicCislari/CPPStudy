//
// Created by Victor Cislari on 23.07.23.
//

#include "Fachbuch.h"
#include <iostream>
using namespace std;

void Fachbuch::set_fachgebiet(const char *neu) {
    if(neu!= nullptr){
        delete(fachgebiet);
        fachgebiet = strdup(neu);
    }
}

const char* Fachbuch::get_fachgebiet() {
    return fachgebiet;
}

Fachbuch::Fachbuch():fachgebiet(nullptr) {}

Fachbuch::~Fachbuch() {
    //hier wird auch automatisch der destruktor von elternklasse aufgerufen
    delete(fachgebiet);
}

Fachbuch::Fachbuch(const char* titel, const char* fachgebiet):
Buch(titel), fachgebiet(nullptr){
    set_fachgebiet(fachgebiet);
}

Fachbuch::Fachbuch(const Fachbuch& orig):
Buch(orig), fachgebiet(nullptr){
    set_fachgebiet(orig.fachgebiet);
}

Fachbuch& Fachbuch::operator=(const Fachbuch &orig) {
    Buch::operator=(orig);
    set_fachgebiet(orig.fachgebiet);
    return *this;
}

void Fachbuch::fachgebiet_ausgeben() const{
    if(fachgebiet!= nullptr){
        cout<<"Fachgebiet: "<< fachgebiet <<endl;
    }
}

void Fachbuch::info() const {
    titel_ausgeben();
    fachgebiet_ausgeben();
    seiten_ausgeben();
}

