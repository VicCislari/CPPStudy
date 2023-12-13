//
// Created by Victor Cislari on 23.07.23.
//

#pragma once

#include "Knoten.h"
using namespace std;

class Geteilt: public Knoten{

protected:
    ostream & print(ostream& out) const override;

public:
    Geteilt(Knoten*, Knoten*);
    double get_wert() override;
};