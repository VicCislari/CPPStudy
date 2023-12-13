//
// Created by Victor Cislari on 23.07.23.
//

#include "Buch.h"
#include <iostream>
using namespace std;

void Buch::set_titel(const char *neu) {
    if(neu != nullptr){
        delete(titel);
        titel = strdup(neu);
    }
}

const char* Buch::get_title() const {
    return titel;
}

Buch::Buch():titel(nullptr){}

Buch::~Buch() {
    delete(titel);
}

Buch::Buch(const char* titel):titel(nullptr){
    set_titel(titel);
}

Buch::Buch(const Buch &orig):titel(nullptr) {
    set_titel(orig.titel);
    seiten = orig.seiten; //ist automatisch eine deep_copy bei vectoren.
}

Buch& Buch::operator=(const Buch& orig){
    set_titel(orig.titel);
    seiten = orig.seiten;
    return *this;
}

void Buch::seite_hinzu(Seite neu) {
    seiten.push_back(neu);
}

void Buch::info() const{
    titel_ausgeben();
    seiten_ausgeben();
}

void Buch::titel_ausgeben() const{
    if(titel!= nullptr){
        std::cout<<"Buchtitel"<<titel<<std::endl;
    }
}

void Buch::seiten_ausgeben() const {
    int seitenanzahl = 0;
    for (Seite seite: seiten){
        cout << "Seite " << ++seitenanzahl <<":"<< endl;
        cout << seite.get_seiteninhalt() << endl;
    }
}