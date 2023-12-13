#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void List::print_Node2(Node2 *Node2) {
    cout << "printing";
    for (short i = 0; i < count(Node2); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist "
                  << data_at(i, Node2) << endl;
    }
}

void List::getNode2AtPositionX(
        Node2 *first) // this function I am gonna need to do again some time. made a bunch of mistakes the first time
{
    std::cout << "\nTest: Knoten an Position x finden\n";
    for (short i = 0; i < count(first); i++) {
        cout << i << " : ";
        Node2_at(i, first);
    }
}

// done: get Node2 at Position x
Node2 *List::Node2_at(short pos, Node2 *first) {
    short myCount = count(first);
    if (pos < 0 || pos >= myCount)
        return NULL;

    Node2 *myNode2 = first;
    for (short i = 0; i < pos; i++) {
        myNode2 = myNode2->next;
    }
    // cout << myNode2->data << endl;
    return myNode2;
}

int List::data_at(short pos, Node2 *first) {
    Node2 *Node2 = Node2_at(pos, first);
    if (Node2 == NULL) {
        std::cout << "Speicherzugriffsfehler! Index " << pos
                  << " existiert nicht." << std::endl;
        exit(1);
    }
    return Node2->data;
}

// done: anzahl elemente zählen
short List::count(Node2 *iterator) {
    short count = 0;
    while (iterator != NULL) {
        count++;
        iterator = iterator->next;
    }
    return count;
}

// Fügt data ans Ende der Liste first
// he made a mistake...
void List::append(int data, Node2 *&first) {
    Node2 *Node2 = new struct Node2();
    Node2->data = data;
    //** Node2 ->next = NULL;
    if (first == NULL) {
        first = Node2;
        Node2->next = NULL; // das kann dann weg.
    } else {
        // was hier fehlt ist Node2->next = NULL;
        //** siehe oben
        Node2_at(count(first) - 1, first)->next = Node2;
    }
}

// Hängt die Liste source an die Liste destination an
void List::append_list(Node2 *source, Node2 *&destination) {
    while (source != NULL) {
        List::append(source->data, destination);
        source = source->next;
    }
}

void List::remove(short pos, Node2 *&first) {
    //basically bring everything from the rest of the Node2 down one position beginning with position i.
    //don't need no for loop for that though, because the Node2s are seperate objects and they know each other, they aren't arranged in a set or something like that.
    Node2 *remove_Node2 = Node2_at(pos, first);
    if (remove_Node2 == NULL) {
        cout << "wrong position";
        exit(1);
    }
    if (remove_Node2 == first) {
        first = first->next;
    } else {
        Node2 *previouse_Node2 = Node2_at(pos - 1, first);
        previouse_Node2->next = remove_Node2->next;
    }
    delete (remove_Node2);
}

// Löscht alle Elemente aus der Liste first
void List::delete_list(Node2 *&first) {
    while (first != NULL)
        remove(0, first);
}

// Sortiert die Liste nach ihren Inhalten aufsteigend
void List::sort(Node2 *first) {
    short length = count(first);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (Node2_at(i, first)->data > Node2_at(j, first)->data) {
                // Kopieren der Inhalte nicht sehr effizient!
                int temp = Node2_at(i, first)->data;
                Node2_at(i, first)->data = Node2_at(j, first)->data;
                Node2_at(j, first)->data = temp;
            }
        }
    }
}

void List::insert(Node2*& first, short pos, int data) {
    Node2* new_node = new Node2();
    new_node->data = data;
    if (pos == 0) {
        new_node->next = first;
        first = new_node;
    }
    else {
        Node2* pre_node = Node2_at(pos - 1, first);
        if (pre_node == NULL) {
            std::cout << "Speicherzugriffsfehler. Index " << pos << " existiert nicht.\n";
            exit(1);
        }
        new_node->next = pre_node->next;
        pre_node->next = new_node;
    }
}



// Gibt die Liste list aus
void List::print_list(Node2* list) {
    short anzahl = count(list);
    for (int i = 0; i < anzahl; i++) {
        std::cout << data_at(i, list);
        if (i != anzahl - 1) std::cout << ", ";
        else std::cout << ".";
    }
}

