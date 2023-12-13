//
// Created by Victor Cislari on 22.07.23.
//

#include "Ware.h"
#include <iostream>
#include <string.h>

using namespace std;

void Ware::set_bezeichnung(const char *neu) {
    if (neu != NULL){
        delete(bezeichnung);
        bezeichnung = strdup(neu); //maybe _strdup(...)?
    }
}

const char* Ware::get_bezeichnung() const {
    return bezeichnung;
}

Ware::Ware(const char* bezeichnung){
    this->bezeichnung = NULL; //apparently this line is very necessary. //why do i need this exactly?
    set_bezeichnung(bezeichnung);
}

Ware::~Ware(){
    delete(bezeichnung);
}

Ware::Ware(const Ware& orig){
    cout<<"calling constructor function" <<endl;
    bezeichnung = NULL; //als Anfang...
    set_bezeichnung(orig.bezeichnung);
}

Ware& Ware::operator = (const Ware& orig){
    cout<<endl;
    cout<<"calling operator function" <<endl;

    cout<<this->bezeichnung<<endl;

    set_bezeichnung(orig.bezeichnung);

    cout<<"das neue:"<<this->bezeichnung<<endl;
    return *this;
}

void Ware::info() const{
    if(bezeichnung != NULL){
        cout<<"Bezeichnung: "<< bezeichnung << endl;
    }
}












