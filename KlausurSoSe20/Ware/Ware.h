//
// Created by Victor Cislari on 22.07.23.
//

#pragma once
using namespace std;

class Ware{
private:
    char* bezeichnung;

public:
    Ware(const char* bezeichnung);
    virtual ~Ware();
    Ware(const Ware&);
    Ware& operator=(const Ware&);
    const char* get_bezeichnung() const;
    void set_bezeichnung(const char*);
    virtual void info() const;
};