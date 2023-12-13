//
// Created by Victor Cislari on 23.07.23.
//

#include "Mal.h"

Mal::Mal(Knoten* links, Knoten* rechts): Knoten(links, rechts){}

double Mal::get_wert() {
    return links->get_wert() * rechts->get_wert();
}

std::ostream& Mal::print(std::ostream& out) const{
    out<<"(" << links << "*" << rechts << ")";
    return out;
}

