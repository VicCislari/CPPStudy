//
// Created by Victor Cislari on 23.07.23.
//

#include "Geteilt.h"
using namespace std;

Geteilt::Geteilt(Knoten* links, Knoten* rechts): Knoten(links, rechts){}

double Geteilt::get_wert() {
    return links->get_wert() / rechts->get_wert();
}

ostream& Geteilt::print(ostream& out) const{
    out<<"(" << links << "/" << rechts << ")";
    return out;
}

