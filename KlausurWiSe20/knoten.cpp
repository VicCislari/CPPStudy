//
// Created by Victor Cislari on 23.07.23.
//

#include <iostream>
#include "Knoten.h"
Knoten::Knoten(Knoten* links, Knoten* rechts):
links(links), rechts(rechts){}

std::ostream& operator<<(std::ostream& out, const Knoten* knoten){
    knoten->print(out);
    return out;
}

