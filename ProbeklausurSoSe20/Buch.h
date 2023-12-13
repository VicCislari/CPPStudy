//
// Created by Victor Cislari on 23.07.23.
//

#pragma once
#include <iostream>
#include <vector>
#include "Seite.h"
using namespace std;

class Buch{

private:
    char* titel;
    vector<Seite> seiten;

protected:
    void titel_ausgeben() const;
    void seiten_ausgeben() const;

public:
    void set_titel(const char*);
    const char* get_title() const;
    Buch();
    virtual ~Buch();
    Buch(const char*);
    Buch(const Buch&); //kopierkonstruktor
    Buch& operator=(const Buch&); //das braucht man mit, wenn kopierkonstrutor
    void seite_hinzu(Seite);
    virtual void info() const;
};