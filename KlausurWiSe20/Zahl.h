//
// Created by Victor Cislari on 23.07.23.
//

#pragma once
#include "Knoten.h"

class Zahl : public Knoten{
private:
    int wert = 0;

protected:
    std::ostream & print(std::ostream& out) const override;

public:
    double get_wert() override;
    Zahl(int);

};