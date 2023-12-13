//
// Created by Victor Cislari on 22.07.23.
//

#include "../Lagerware/Lagerware.h"
#pragma once

class Restposten: public Lagerware{
private:
    double rabatt;
public:
    void set_rabatt(double);
    double get_rabatt() const;
    Restposten(const char* bezeichnung, double preis, int vorrat, double rabatt);
    Restposten(const Restposten&);
    Restposten& operator=(const Restposten&);
    void info() const override;
};