//
// Created by Victor Cislari on 18.05.23.
//

#include "../Node/Node2.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#endif //UNTITLED_LIST_H

class List {

public:
    Node2 *first;

    // Node2: get Node at Position x
    Node2 *Node2_at(short pos, Node2 *first);

    int data_at(short pos, Node2 *first);

    // done: anzahl elemente zählen
    short count(Node2 *iterator);

    // Fügt data ans Ende der Liste first
    void append(int data, Node2 *&first);

    // Hängt die Liste source an die Liste destination an
    void append_list(Node2 *source, Node2 *&destination);

    void remove(short pos, Node2 *&first);

    // Löscht alle Elemente aus der Liste first
    void delete_list(Node2 *&first);

    void print_Node2(Node2 *Node2);

    void getNode2AtPositionX(Node2 *first);

    // Sortiert die Liste nach ihren Inhalten aufsteigend
    void sort(Node2* first);

    void insert(Node2*& first, short pos, int data);

    // Gibt die Liste list aus
    void print_list(Node2* list);

};
