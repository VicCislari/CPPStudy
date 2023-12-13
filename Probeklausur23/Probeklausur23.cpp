//
// Created by Victor Cislari on 23.07.23.
//

#include <iostream>
#pragma once
using namespace std;

class Person {
protected:
    char* name;
    void set_name(char* name) {
        if (name != nullptr) {
            delete(this->name);
            this->name = strdup(name);
        }
    }
    virtual void print(ostream& out) const {
        if (name != nullptr) out << name;
        else out << "<unbekannt>";
    }
public:
    Person(char* name) : name(nullptr) {
        set_name(name);
    }
    Person(const Person&) = delete;
    Person& operator=(const Person&) = delete;
    virtual ~Person() {
        delete(name);
    }
    friend ostream& operator<<(ostream& out, const Person& person) {
        person.print(out);
        return out;
    }
};

class Gast : public Person {
private:
    int eintrittspreis;
protected:
    virtual void print(ostream& out) const override {
        if (name != nullptr) out << name << " (" << eintrittspreis << " Euro)";
        else out << "<unbekannt> (" << eintrittspreis << " Euro)";
    }
public:
    Gast(char* name, int preis) : Person(name), eintrittspreis(preis) {
        cout << *this << " hat den Laden für " << eintrittspreis << " Euro betreten.\n";
    };
    ~Gast() {
        cout << *this << " hat den Laden wieder verlassen.\n";
    }
};

class VIP : public Person {
protected:
    virtual void print(ostream& out) const override {
        if (name != nullptr) out << name << " (VIP)";
        else out << "<unbekannt> (VIP)";
    }
public:
    VIP(char* name) : Person(name) {};
};

class Party {
private:
    vector<Person*> gaeste;
public:
    void hereinlassen(Person* person) {
        gaeste.push_back(person);
    }

    friend ostream& operator<<(ostream& out, const Party& vorlesung) {
        out << "Auf der Party sind folgende " << vorlesung.gaeste.size() << " Personen:\n";
        for(const Person* person : vorlesung.gaeste) {
            out << *person << endl;
        }
        return out;
    }
};

void testingProbeklausur23() {
    Person* paula = new Gast((char*)"Paula Partygirl",1);
    Person* simon = new Gast((char*)"Simon Supersimp",100);
    Person* ina = new VIP((char*)"Ina Influencer");
    Party party;
    party.hereinlassen(paula);
    party.hereinlassen(simon);
    party.hereinlassen(ina);
    cout << party;
    delete(paula);
    delete(simon);
    delete(ina);
}