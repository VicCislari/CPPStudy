//
// Created by Victor Cislari on 23.07.23.
//

#pragma once
#include "Buch.h"
#include <iostream>
using namespace std;

class Fachbuch: public Buch{

private:
    char* fachgebiet;

protected:
    void fachgebiet_ausgeben() const;

public:
    void set_fachgebiet(const char*);
    const char* get_fachgebiet();
    Fachbuch();
    virtual ~Fachbuch();
    Fachbuch(const char* titel, const char* fachgebiet);
    Fachbuch(const Fachbuch&);
    Fachbuch& operator=(const Fachbuch&);
    void info() const override;
};