//
// Created by Victor Cislari on 23.07.23.
//

#include "Seite.h"

std::string Seite::get_seiteninhalt() const {
    return seiteninhalt;
}

void Seite::set_seiteninhalt(std::string inhalt) {
    seiteninhalt=inhalt;
}

Seite::Seite():seiteninhalt(""){}

Seite::Seite(std::string inhalt): seiteninhalt(inhalt){}


