//
// Created by Victor Cislari on 23.07.23.
//

#include "Plus.h"
using namespace std;

Plus::Plus(Knoten* links, Knoten* rechts): Knoten(links, rechts){}

double Plus::get_wert() {
    return links->get_wert() + rechts->get_wert();
}

ostream& Plus::print(ostream& out) const{
    out<<"(" << links << "+" << rechts << ")";
    return out;
}

