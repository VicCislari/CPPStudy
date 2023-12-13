//
// Created by Victor Cislari on 23.07.23.
//

#pragma once
#include <iostream>
using namespace std;

class Knoten{

protected:
    Knoten* links;
    Knoten* rechts;
    Knoten(Knoten*, Knoten*);
    virtual std::ostream& print(std::ostream&) const = 0;

public:
    virtual double get_wert() = 0;//zeigt sich bei Laufzeit was passieren soll... heir wird das erklärt https://www.youtube.com/watch?v=T8f4ajtFU9g
    friend ostream& operator<<(ostream&, const Knoten*); //what the fuck! https://www.youtube.com/watch?v=BnMnozsSPmw
    //friend explained here https://www.youtube.com/watch?v=KXDzBglp83M

};