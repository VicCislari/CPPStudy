//
// Created by Victor Cislari on 23.07.23.
//

#include "Minus.h"

Minus::Minus(Knoten* links, Knoten* rechts): Knoten(links, rechts){}

double Minus::get_wert() {
    return links->get_wert() - rechts->get_wert();
}

std::ostream& Minus::print(std::ostream& out) const{
    out<<"(" << links << "-" << rechts << ")";
    return out;
}

