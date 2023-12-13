//
// Created by Victor Cislari on 23.07.23.
//

#pragma once

#include "Knoten.h"

class Mal: public Knoten{

protected:
    std::ostream & print(std::ostream& out) const override;

public:
    Mal(Knoten*, Knoten*);
    double get_wert() override;
};