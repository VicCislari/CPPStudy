//
// Created by Victor Cislari on 23.07.23.
//

#pragma once
#include<iostream>

class Seite{
private:
    std::string seiteninhalt;

public:
    void set_seiteninhalt(std::string);
    std::string get_seiteninhalt() const;
    Seite();
    Seite(std::string);

};