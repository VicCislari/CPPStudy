//
// Created by Victor Cislari on 23.07.23.
//

#pragma once

#include "Knoten.h"

class Minus: public Knoten{

protected:
    std::ostream & print(std::ostream& out) const override;

public:
    Minus(Knoten*, Knoten*);
    double get_wert() override;

};