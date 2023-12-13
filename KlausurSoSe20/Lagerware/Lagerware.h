//
// Created by Victor Cislari on 22.07.23.
//

#pragma once
#include "../Ware/Ware.h"

class Lagerware: public Ware{

private:
    double preis;
    int vorrat;

public:
    void set_preis(double);
    double get_preis() const;
    void set_vorrat(int);
    int get_vorrat() const;
    Lagerware(const char* bezeichnung, double preis, int vorrat);

    Lagerware(const Lagerware&);
    Lagerware& operator=(const Lagerware&);

    void info() const override; //override, weil virtual

};
