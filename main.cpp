#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Example/Example.h"
#include "Punkt/Punkt.h"
#include "VerketteteListe/List/List.h"

using namespace std;

#define AUSGABE 42
#define DEBUGMODE
#define COUNT 0;

#include "ifndef/KlasseA.h"
#include "ifndef/KlasseB.h"
#include <vector>

#include "KlausurSoSe20/Ware/Ware.h"
#include "KlausurSoSe20/Lagerware/Lagerware.h"
#include "KlausurSoSe20/Restposten/Restposten.h"

#include "KlausurWiSe20/Geteilt.h"
#include "KlausurWiSe20/Mal.h"
#include "KlausurWiSe20/Plus.h"
#include "KlausurWiSe20/Minus.h"
#include "KlausurWiSe20/Zahl.h"
#include "KlausurWiSe20/Knoten.h"

#include "ProbeklausurSoSe20/Seite.h"
#include "ProbeklausurSoSe20/Buch.h"
#include "ProbeklausurSoSe20/Fachbuch.h"


void erhoehe_um_zehn_w(int i) { // wertparameter, also ein Klon.
    cout << "(w) i: " << i + 10 << endl;
}

void erhoehe_um_zehn_p(int *i) { // pointer, also ein Klon.
    *i = *i + 10;
    cout << "(p) i: " << *i << endl;
}

void erhoehe_um_zehn_r(int &i) { // referenzparameter. Effizienter, weil keine Kopie.
    i = i + 10;
    cout << "(r) i: " << i << endl;
}

void erhoehe_um_zehn_cr(const int &i) {
    // konstanter Referenzparameter. Effizienter, weil keine Kopie
    //+ man darf das Wert des übergebenen Parameters nicht verändern. Man darf nur damit spielen
    // i = i+10; das hier darf nicht passieren.

    cout << "(cr) i: " << i + 10 << endl;
}

void testing_w_and_p_function_arguments() {
    int i = 42;
    cout << "(1) i: " << i << endl;
    erhoehe_um_zehn_w(i);
    cout << "(2) i: " << i << endl;
    erhoehe_um_zehn_p(&i);
    cout << "(3) i: " << i << endl;
    erhoehe_um_zehn_r(i);
    cout << "(4) i: " << i << endl;
    erhoehe_um_zehn_cr(i);
    cout << "(5) i: " << i << endl;
    cout << "was ist unterschied zwischen pointer und referenzparameter?????"
         << i << endl;
}

void nicht_machen(const int &x) {
    void *p_x = (void *) &x;
    *((int *) p_x) = 100;
    cout << x;

    // I don't understand any of this....
}

const char *zeichenkette() { // const in dem Funktionsnamen bedeutet: bitte ändern nicht was darauf zeigt!
    char *zeichenkette = (char *) malloc(6);
    zeichenkette[0] = 'H';
    zeichenkette[1] = 'a';
    zeichenkette[2] = 'l';
    zeichenkette[3] = 'l';
    zeichenkette[4] = 'o';
    zeichenkette[5] = '\0';
    return zeichenkette;
}

void testing_pointer_change() {
    cout << AUSGABE << endl;
    int antwort = 42;
    nicht_machen(antwort);
    cout << antwort;

    const char *text = zeichenkette();
    // char* text = zeichenkette(); //compiler Fehler...
    // text[0] = 'z'; //geht nicht!
}

void testing_eingabe() {
    const int groesse = 10;
    int feld[groesse];
    int i;

    for (i = 0; i < groesse; i++) {
        feld[i] = (i + 1) * 10;
        cout << feld[i] << " ";
    }
    char text[] = {'H', 'a', 'l', 'l', 'o', 0};
    // char text[6] = {'H', 'a', 'l', 'l', 'o', '\0'}; //beides geht

    cout << text;

    int size = 0;
    cout << "wie viele zahelen sollen eingegeben werden?";
    cin >> size;
    // c.Variante: int* zahlen = (int*)malloc(size * sizeof(int));
    // cpp Variante:
    int *zahlen = new int[size];
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < size; i++) {
            if (j == 0) {
                cout << i + 1 << ".Zahl:";
                cin >> zahlen[i];
            } else
                cout << zahlen[i] << endl;
        }
    }

    // free(zahlen); beides geht hier unten, eifnach aufräumen...
    delete[] zahlen;
}

void zeichenketten() {
    const char *name = "Carsten"; //steht im konstanten speicherbereich der nicht verönderbar ist.
    //name[0]="K"; //geht nicht.

    //free(name); //geht nicht! wir haben den name zum compilezeitpunkt erzeugt.
    //delete(name); //geht nicht. faustregel: ohne new kein delete.

    cout << name << endl;

    char name2[] = {'C', 'a', 'r', 's', 't', 'e', 'n', '\0'}; // die null am ende muss
    name2[5] = 'o'; //das geht
    cout << name2 << endl;

    const wchar_t *name3 = L"Carsten"; //interessant, einfacher größerer char.
//	const char16_t *name4 = u"Carsten";
//	const char32_t *name5 = U"Carsten"; ///ich krieg es nicht das zum laufen zu bringen

    string name6 = "Carsten";
    cout << name6 << endl;

    //string name7 = "Carsten" + " Biemann";//geht nicht weil zwei pointer addiert werden
    string name8 = name6 + " Biemann"; //geht
    cout << name8 << endl;

//	/const char* mehrzeiliger_text = R"(dfdfdfdfdf)";//dfdfdfdfdfdf
    const char *mehrzeiliger_text_new = R"(abc)";
    cout << mehrzeiliger_text_new << endl;

}

void weitere_datentypen() {
    char c = 0; //mindestens 8 Bit
    short s = 0; //mindestens wie char
    int i = 0; //mindestens wie short, in der regel doppelt wie short also 32.
    long l = 0; //gleich wie int
    long long ll = 0; //doppelt wie long
    signed int si = 0; //-1 würde nicht gehen
    //es ist aber nicht genau definiert. man kann es aber definieren

    int8_t i8 = 0; //GENAU 8 bit, immer
    int16_t i16 = 0;
    int32_t i32 = 0;
    int64_t i64 = 0;

}

void tue_was(int zahl) {
}

void tue_was(const char *text) {
    cout << "here";
}

void tue_was(const string &text) {
    cout << "her2e";
}

void tue_was(float zahl) {}

void testing_polymorphismus() {
    string t = "myT";
    char m[] = "hallo";
    tue_was(t);
    tue_was(m);
    tue_was(float(3.14));
    tue_was(3);
}

struct Beispiel {
    int i;
    int zahl2;
    const char *text;
};

void testing_classes() {
    Beispiel beispiel1;
    beispiel1.i = 9;
    //...
}

/*
class Punkt {
public:
    int x, y;

    void ausgabe() {
        cout << "x:" << this->x << "; y:" << this->y;
    }

    void einlesen() {
        cout << "x: ";
        cin >> this->x;
        cout << "y: ";
        cin >> this->y;
    }

    double abstand(Punkt *koordinate) {
        return sqrt((double) (pow(this->x - koordinate->x, 2) + pow(this->y - koordinate->y, 2)));
    }

};
*/

void punkt_aufgabe() {
    Punkt koordinate1;
    Punkt koordinate2;

    koordinate1.einlesen();
    koordinate2.einlesen();

    cout << "abstand: " << endl;
    koordinate1.ausgabe();
    cout << " zu: " << endl;
    koordinate2.ausgabe();
    cout << " ist " << koordinate1.abstand(&koordinate2) << endl;

    //Punkt koordinate = koordinate1.addiere(koordinate2);
    // cout<<"beide koordinaten addiert: "<<endl;
    //koordinate3.ausgabe();
}

class Bruch {
public:
    float a, b;

    Bruch multiply(Bruch *bruch) {
        Bruch ergebnis;
        ergebnis.a = bruch->a * this->a;
        ergebnis.b = bruch->b * this->b;
        return ergebnis;
    }

    Bruch division(Bruch *bruch) {
        Bruch ergebnis;
        ergebnis.a = bruch->a / this->b;
        ergebnis.b = bruch->b / this->a;
        return ergebnis;
    }

    Bruch addition(Bruch *bruch) {
        Bruch ergebnis;
        ergebnis.a = this->a * bruch->b + bruch->a * this->b;
        ergebnis.b = bruch->a * this->b;
        return ergebnis;
    }

    Bruch subtraction(Bruch *bruch) {
        Bruch ergebnis;
        ergebnis.a = this->a * bruch->b - bruch->a * this->b;
        ergebnis.b = bruch->a * this->b;
        return ergebnis;
    }

    void kuerzen() {
        int ggt = this->ggt(this->a, this->b);
        this->a /= ggt;
        this->b /= ggt;
    }

private:

    int ggt(int a, int b) {
        if (b == 0) return a;
        return ggt(b, a % b);
    }
};

void bruch_aufgabe() {
    Bruch viertel;
    Bruch anderer_bruch;
    viertel.a = 1;
    viertel.b = 2;
    anderer_bruch.a = 2;
    anderer_bruch.b = 4;
    Bruch ergebnis = viertel.multiply(&anderer_bruch);
    cout << ergebnis.a << "/" << ergebnis.b;

    anderer_bruch.kuerzen();
}

class EinfachVerketteListe {

public:
    struct Node {
        Node *next;
        int data;
    };

private:
    Node *first;
    Node *second;
    Node *third;

public:

    EinfachVerketteListe() {
        cout << "Anzahl Elemente am Anfang: " << count(first) << endl;
        first = new Node();
        Node *second = new Node();
        Node *third = new Node();
        first->next = second;
        second->next = third;
        third->next = NULL;
        first->data = 1;
        second->data = 2;
        third->data = 3;
        append(5, first);
        append(7, first);
        append(3, first);

        cout << "\nTest: Am Ende anhaengen\n" << endl;

        print_node(first);

        Node *kopie = NULL;

        append_list(first, kopie);
        append(666, kopie);

        cout << "something intetersting" << endl;

        print_node(kopie);

        remove(2, kopie);
        cout << "something intetersting" << endl;

        print_node(kopie);
        delete_list(kopie);
        print_node(kopie);

    }

private:
    void print_node(Node *node) {
        cout << "printing";
        for (short i = 0; i < count(node); i++) {
            std::cout << "Der Inhalt an Position " << i << " ist "
                      << data_at(i, node) << endl;
        }
    }

    void initialize() {
        first = new Node();
        second = new Node();
        third = new Node();

        loadElement(first, second);
        loadElement(second, third);
        loadElement(third, NULL);
        loadData(first, 1);
        loadData(second, 2);
        loadData(third, 3);
    }

    void loadElement(Node *start, Node *next) {
        start->next = next;
    }

    void loadData(Node *node, int data) {
        node->data = data;
    }

    void getNodeAtPositionX(
            Node *first) // this function I am gonna need to do again some time. made a bunch of mistakes the first time
    {
        std::cout << "\nTest: Knoten an Position x finden\n";
        for (short i = 0; i < count(first); i++) {
            cout << i << " : ";
            node_at(i, first);
        }
    }

    // done: get Node at Position x
    Node *node_at(short pos, Node *first) {
        short myCount = count(first);
        if (pos < 0 || pos >= myCount)
            return NULL;

        Node *myNode = first;
        for (short i = 0; i < pos; i++) {
            myNode = myNode->next;
        }
        // cout << myNode->data << endl;
        return myNode;
    }

    int data_at(short pos, Node *first) {
        Node *node = node_at(pos, first);
        if (node == NULL) {
            std::cout << "Speicherzugriffsfehler! Index " << pos
                      << " existiert nicht." << std::endl;
            exit(1);
        }
        return node->data;
    }

    // done: anzahl elemente zählen
    short count(Node *iterator) {
        short count = 0;
        while (iterator != NULL) {
            count++;
            iterator = iterator->next;
        }
        return count;
    }

    // Fügt data ans Ende der Liste first
    // he made a mistake...
    void append(int data, Node *&first) {
        Node *node = new Node();
        node->data = data;
        //** node ->next = NULL;
        if (first == NULL) {
            first = node;
            node->next = NULL; // das kann dann weg.
        } else {
            // was hier fehlt ist node->next = NULL;
            //** siehe oben
            node_at(count(first) - 1, first)->next = node;
        }
    }

    // Hängt die Liste source an die Liste destination an
    void append_list(Node *source, Node *&destination) {
        while (source != NULL) {
            append(source->data, destination);
            source = source->next;
        }
    }

    void remove(short pos, Node *&first) {
        //basically bring everything from the rest of the node down one position beginning with position i.
        //don't need no for loop for that though, because the nodes are seperate objects and they know each other, they aren't arranged in a set or something like that.
        Node *remove_node = node_at(pos, first);
        if (remove_node == NULL) {
            cout << "wrong position";
            exit(1);
        }
        if (remove_node == first) {
            first = first->next;
        } else {
            Node *previouse_node = node_at(pos - 1, first);
            previouse_node->next = remove_node->next;
        }
        delete (remove_node);
    }

    // Löscht alle Elemente aus der Liste first
    void delete_list(Node *&first) {
        while (first != NULL)
            remove(0, first);
    }

};

void testingEinfachVerketteListe() {
    EinfachVerketteListe *einfachVerketteListe = new EinfachVerketteListe();

}

void was_bin_ich() {
    cout << "0,nix";
}

void testing_Beispiel() {
    Example *beispiel = new Example();
    beispiel->x = 1;
    beispiel->was_bin_ich();
    beispiel->info();
}

class Superklasse{
public:
    Superklasse(){
        cout<<"objekt erzeugt"<<endl;
    }
    ~Superklasse(){
        cout<<"objekt zerstört"<<endl;
    }
};

void testingDestructors() {
    int count=0;

    for(int j=0;j<100;j++) {
        Superklasse* y = new Superklasse();
        cout<<++count<<endl;
    }
}

void testingListDeclarationImplementationForVerketteteListe(){
    Punkt koordinate1;
    Punkt koordinate2;

    Node2* first = NULL;
    List list;

    // Test Anzahl Elemente zählen
    std::cout << "Anzahl Elemente am Anfang: " << list.count(first) << std::endl;
    first = new Node2();
    Node2* second = new Node2();
    Node2* third = new Node2();
    first->next = second;
    second->next = third;
    third->next = NULL;
    first->data = 1;
    second->data = 2;
    third->data = 3;

    std::cout << "Anzahl Elemente nach Fuellen: " << list.count(first) << std::endl;

    std::cout << "\nTest: Knoten an Position x finden\n";
    for (short i = 0; i < list.count(first); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.Node2_at(i, first)->data << std::endl;
    }

    std::cout << "\nTest: Inhalt an Position x finden\n";
    for (short i = 0; i < list.count(first); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.data_at(i, first) << std::endl;
    }

    std::cout << "\nTest: Am Ende anhaengen\n";
    list.append(4, first);
    for (short i = 0; i < list.count(first); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.data_at(i, first) << std::endl;
    }

    std::cout << "\nTest: Liste komplett anhaengen und einmal teilweise anhaengen\n";
    Node2* kopie = NULL;
    list.append_list(first, kopie);
    list.append_list(third, kopie);
    for (short i = 0; i < list.count(kopie); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.data_at(i, kopie) << std::endl;
    }

    std::cout << "\nTest: Loesche Element an Position 4\n";
    list.remove(4, kopie);
    for (short i = 0; i < list.count(kopie); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.data_at(i, kopie) << std::endl;
    }

    std::cout << "\nTest: Loesche alle Elemente\n";
    list.delete_list(kopie);
    std::cout << "Anzahl Elemente in Liste kopie: " << list.count(kopie) << std::endl;

    std::cout << "\nTest: Einfuegen von 100 an Position 0, 3, 6\n";
    list.insert(first, 0, 100);
    list.insert(first, 3, 100);
    list.insert(first, 6, 100);
    for (short i = 0; i < list.count(first); i++) {
        std::cout << "Der Inhalt an Position " << i << " ist " << list.Node2_at(i, first)->data << std::endl;
    }

    std::cout << "\nTest: Sortieren und Ausgeben\n";
    list.sort(first);
    list.print_list(first);
}

void testingDefineDebug(){
#ifdef DEBUGMODE
    cout <<"debugmode is defined";
#endif
}

void repeatThis(){
    cout<<"when to use & and *";
    cout<<"when does a destructor activate, here is the link: https://www.youtube.com/watch?v=hNTJWGcKRCY&list=PLjgRvcF5160nwIFrHlZMGafFSL1XMRXcz&index=45. kurzgefasst: am ende des Blocks.";
}

class MyClass {
private:
    int data;
public:
    MyClass(int value){
        std::cout << "Constructor called" << std::endl;
    }

    // Kopierkonstruktor
    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called" << std::endl;
    }

    int getData() {
        return data;
    }
};

void testConstructorPolymorphism(){
    //Kopierkonstruktor
    MyClass obj1(42); // Erzeugt ein Objekt mit dem Wert 42
    MyClass obj2(obj1); // Verwendet den Kopierkonstruktor, um obj2 von obj1 zu kopieren
    std::cout << "Data in obj2: " << obj2.getData() << std::endl;

}

class A {
public:
    int a;
    int b() { return 42; }
};
class B : public A {
public:
    int c;
};

void testingDerivation(){
    A a;
    B b;

    a.a=10;
    cout<< a.b();

    b.a=11;
    b.b();
    b.c=10;
}

class A1 {
public:
    virtual void foo() {
        cout << "A";
    }

    virtual void testing() = 0;
};

class B1 : public A1 {
public:
    void foo() override{
        cout << "B";
    }

    void testing() override{
        cout<<"hey";
        //why do I need override here?
    }
};

class C1 : public B1 {
public:
    void foo() override{
        cout << "C";
    }
};

void testingVirtual(){

A1 *b = new B1();
b->foo();

A1 *c = new C1();
c->testing();
c->foo();

}

class Rechner {
private:
    double zahl;

public:
    void setZahl( double z ) {
        zahl = z;
    }

    double getZahl() {
        return zahl;
    }

    Rechner& operator+ (const Rechner& r) {
        this->zahl += r.zahl;
        return *this;
    }

    Rechner& operator= (const Rechner& orig) {
        this->zahl = orig.zahl + 50;
        return *this;
    }

    ostream& print(ostream& out) const{
        out << zahl << endl;
        return out;
    }
};

void testingOperator(){
    Rechner rechner1;
    Rechner rechner2;
    Rechner rechner3;

    rechner1.setZahl(6.0);
    rechner2.setZahl(12.0);

    rechner2 = rechner1;
    rechner3 = rechner1 + rechner2;

    double ergebnis = rechner3.getZahl();
    cout<<ergebnis;
}

void testingOperator2(){
    Rechner rechner1;
    Rechner rechner2;
    Rechner rechner3;

    rechner1.setZahl(6.0);
    rechner2.setZahl(12.0);
    rechner3 = rechner1;
    cout<<rechner3.getZahl();

    cout<<endl<<rechner1.getZahl();
    //rechner3.print(cout);
    //rechner2 = rechner1;
    //rechner2.print(cout); //11
    //rechner3 = (rechner1 + rechner2);

}

double warenwert(vector<Lagerware*> liste) {
    double summe = 0;
    for(Lagerware* produkt : liste){
        double wert = produkt->get_preis()*produkt->get_vorrat();
        if (Restposten* restposten = dynamic_cast<Restposten*>(produkt))
            wert *= (1-restposten->get_rabatt()/100);

        summe += wert;
    }
    return summe;
}

void testingKlausurSoSe20(){
    vector<Lagerware*> alle_produkte;
    alle_produkte.push_back(new Lagerware("Apple iPhone 11", 599.99, 5));
    alle_produkte.push_back(new Restposten("Kaugummie", 0.1, 20, 50.0));

    cout<<warenwert(alle_produkte);

    Ware *ware1 = new Ware("hallo");
    Ware *ware2 = ware1;
    Ware *ware3 = new Ware(*ware1);
    Ware *ware4;
    ware4 = ware1;
    ware1 = ware3;

    Ware ware5("hey");
    Ware ware6("buh");
    ware6 = ware5;
}

void testingKlausurWiSe20(){
    Knoten* a = new Zahl(10);
    Knoten* b = new Zahl(2);
    Knoten* c = new Zahl(2);
    Knoten* d = new Zahl(3);
    Knoten* e = new Geteilt(a,b);
    Knoten* f = new Zahl(1);
    Knoten* g = new Mal(c,d);
    Knoten* h = new Minus(e,f);
    Knoten* i = new Plus(g,h);

    cout<<i<<"="<<i->get_wert()<<endl;
}

void testingProbeKlausur20(){
    Seite seite1;
    seite1.set_seiteninhalt(R"(Dies ist nummer 1
        sdfsdf
        sdf
        sdf
        sdf)");


    Seite seite2("Test... asdasdas");
    Buch buch("titeltes");
    buch.seite_hinzu(seite1);
    buch.seite_hinzu(seite2);
    buch.info();

    Buch buch2(buch);

}

void testingZeichenkette(){
    
}

class Lagerware1 {

private:
    int id;
    string name;

public:
    // Constructor
    Lagerware1(int id, const string& name) {
        this->id = (id);
        this->name = (name);
    }

    // Copy assignment operator
    Lagerware1& operator=(const Lagerware1& other) {
        if (this == &other) {
            return *this; // Handling self-assignment
        }
        cout<<"hallo";
        // Copy the data from 'other' to 'this'
        id = other.id;
        name = other.name;

        return *this; // Return a reference to the modified object
    }

    // Other member functions and data members...
};

void testingChatGPTOperatorExample(){

    Lagerware1 item1(1, "Item 1");
    Lagerware1 item2(2, "Item 2");

    item1 = item2; // Using the copy assignment operator
}

class WareT{
private:
    char* bezeichnung;

public:

    void setBezeichnung(const char* neu){
        if(neu!=NULL) {
            delete(bezeichnung);
            bezeichnung = strdup(neu);
        }
    }

    const char* getBezeichnung() const{
        // the first one say that I am gonna return a const.
        // the second const says that I am not gonna change anything that is static...
        //https://www.youtube.com/watch?v=RC7uE_wl1Uc

        return bezeichnung;
    }

    WareT(const char* neu){
        this->bezeichnung = NULL;
        setBezeichnung(neu);
    }

    //Kopierkonstruktor
    WareT(const WareT& orig){
        setBezeichnung(orig.getBezeichnung());
    }

    WareT& operator= (const WareT& orig){
        setBezeichnung(orig.getBezeichnung());
        return *this;
    }

    virtual void info() const{
        //does my const theory hold?
        if(bezeichnung != NULL){
            cout<<"Bezeichnung: "<<getBezeichnung()<<endl;
        }
    }

    ~WareT(){
        delete(bezeichnung);
    }
};

class LagerwareT: public WareT{

private:
    double preis;
    int vorrat;

public:
    LagerwareT(const char* bezeichnung, const double& preis, const int& vorrat):
    WareT(bezeichnung){
        setPreis(preis);
        setVorrat(vorrat);
    }

    LagerwareT(const LagerwareT& orig): WareT(orig.getBezeichnung()){
        preis = orig.getPreis();
        vorrat = orig.getVorrat();
    }

    LagerwareT& operator= (const LagerwareT& orig){
        operator=(orig); //this is for the base class Ware.
        setPreis(orig.getPreis());
        setVorrat(orig.getVorrat());
        return *this;
    }

    void info() const override{
        WareT::info();
        cout<< "Preis: "<<preis<<endl<<"Vorrat: "<<vorrat<<endl;
    }

    void const setPreis(const double& neu){
        preis = neu;
    }

    double getPreis() const{
        return preis;
    }

    void const setVorrat(const int& neu){
        vorrat = neu;
    }

    int getVorrat() const{
        return vorrat;
    }
};

class RestpostenT: public LagerwareT{
private:
    double rabatt;
public:
    //Konstruktor //auch beachten die andere Klasse zu ersttellen, also Zeug mitgeben.
    RestpostenT(const char* bezeichnung, const double& preis, const int& vorrat, const double& rabatt):
    LagerwareT(bezeichnung, preis, vorrat){
        this->rabatt = rabatt;
    }

    //Kopierkonstruktor
    RestpostenT(const RestpostenT& orig):
    LagerwareT(orig.getBezeichnung(), orig.getPreis(), orig.getVorrat()){
        setRabatt(orig.getRabatt());
    }
    RestpostenT& operator=(const RestpostenT& orig){
        operator=(orig); //ich weiß wirklich nicht wieso man das braucht...
        setRabatt(orig.getRabatt());
        return *this;
    }

    //getter und setter. //beachte immer zwischen 0 und 100. beim setting
    const double& getRabatt() const{
        return rabatt;
    }

    void setRabatt(const double& rabatt){
        //conditions...
        if(0<=rabatt<=100)
            this->rabatt = rabatt;
    }

    //info implementation
    void info() const override{
        LagerwareT::info();
        cout<<"Rabatt: "<<getRabatt()<<endl;
    }
};

void testingKlausur2020SoT(){
    WareT w("hallo");
    //w.info();
    cout<<endl;

    WareT e("tra");
    w = e;
    //w.info();

    WareT *r = new RestpostenT("tree", 40, 60, 0.0);
    WareT *t = new RestpostenT("baum", 50, 70, 60.4);

    r->info();
}

class KnotenT{
    //getter and setter;

protected:
    KnotenT* links;
    KnotenT* rechts;
    KnotenT(KnotenT* links, KnotenT* rechts): rechts(rechts), links(links){}

public:
    //Kopierkonstruktor und operator

    //overloading << operator
    virtual ostream& print(ostream&) const = 0;

    friend ostream& operator<<(ostream& out, const KnotenT* knoten){
        knoten->print(out);
        return out;
    } //what the fuck! https://www.youtube.com/watch?v=BnMnozsSPmw

    //only numbers within
    virtual int calculate() = 0;
    //virtual std::ostream& print(std::ostream&) const = 0;

    KnotenT* getLinks() const{
        return this->links;
    }

    KnotenT* getRechts() const{
        return this->rechts;
    }
};

class WertT : public KnotenT{
    //getter and setter;
private:
    int wert;

public:

    ostream& print(ostream& out) const override{
        out<<wert;
        return out;
    };

    WertT(const int wert): KnotenT(NULL, NULL){
        if(0 <= wert <= 100){
            this->wert = wert;
        }
    }
    int calculate(){
        return wert;
    }
};


class PlusT: public KnotenT{
    //getter and setter

public:
    PlusT(KnotenT* links, KnotenT* rechts): KnotenT(links, rechts){}

    int calculate(){
        //later with the
        return links->calculate() + rechts->calculate();
    }

    ostream& print(ostream& out) const{
        out << "(" << links << "+" << rechts << ")";
        return out;
    }
};
void testingKnotenT(){

    KnotenT *k1 = new WertT(2);
    KnotenT *k2 = new WertT(3);
    KnotenT *k = new PlusT( k1, k2);
    KnotenT *g = new PlusT( k, k);
    KnotenT *r = new PlusT( g, k);

    cout << r << "=" << r->calculate();
}

class SeiteT{
private:
    string seiteninhalt;
public:
    SeiteT(string neu){
        this->seiteninhalt = neu;
    }
    SeiteT(): seiteninhalt(""){}

    //getters and setters
    string getSeiteninhalt() const{
        return seiteninhalt;
    }

    void print(){
        cout<<seiteninhalt;
    }
};

class BuchT{
private:
    char* title;
    vector<SeiteT*> seiten; //I wonder if this works too...
public:

    void seiteHinzufügen(SeiteT* seite){
        seiten.push_back(seite);
    }

    void setSeiten(const vector<SeiteT*> neu){
        this->seiten = neu;
    }

    const vector<SeiteT*> getSeiten()const{
        return seiten;
    };

    const char* getTitle() const{
        return title;
    }
    void setTitle(const char* neu){
        if(neu!= nullptr) {
            delete(title);
            title = strdup(neu);
        }
    }

    BuchT(const char* title, vector<SeiteT*> seiten): seiten(seiten){
        title = strdup(title);
    }
    ~BuchT(){
        delete(title);
        seiten.clear(); //do I need this?
    }

    //Kopierkonstruktor
    BuchT(const BuchT& orig){
        setTitle(orig.getTitle());
        setSeiten(orig.getSeiten());
    }

    //operator=
    BuchT& operator=(const BuchT& orig){
        setTitle(orig.getTitle());
        setSeiten(orig.getSeiten());
        return *this;
    }

    //info()
    virtual void info() const{
        cout<<"hahah";
    }

    //printTitel
    void printTitel() const{
        cout<<"Titel: "<<getTitle();
    }

    //printSeiten
    void printSeiten() const{
        int seitenanzahl=0;
        for(SeiteT* seite: seiten){
            cout<<"# "<<++seitenanzahl<<": "<<seite->getSeiteninhalt()<<endl;
        }
    }
};

class FachbuchT: public BuchT{
private:
    int n;

public:
    FachbuchT(const int n, char* title, vector<SeiteT*> seiten): n(n), BuchT(title, seiten){}

    friend ostream& operator<<(ostream& out, const BuchT& buch);

    FachbuchT& operator=(FachbuchT& orig){
        operator=(orig);
        n=orig.n;
        return *this;
    }
};

ostream& operator<<(ostream& out, const BuchT& buch){
    //buch.getSeiten()[0]->print();
    out<<buch.getTitle();
    return out;
}

int main() {
    //testingOperator();
    //testingChatGPTOperatorExample();
    //testingKnotenT();
    //cout<<"hello test";
    //cout<<endl;
    //testingKlausurSoSe20();

    //testing_pointer_change();
    //testing_w_and_p_function_arguments();
    //testing_eingabe();
    //testingEinfachVerketteListe();
    //zeichenketten();
    //weitere_datentypen();
    //testing_polymorphismus();
    //punkt_aufgabe();
    //bruch_aufgabe();
    //testing_Beispiel();
    //testingDestructors();
    //testingListDeclarationImplementationForVerketteteListe();
    //testingDefineDebug();
    //testConstructorPolymorphism();
    //testingDerivation();
    //testingVirtual();
    //testingOperator();
    //testingOperator2();
    //testingKlausurWiSe20();
    testingProbeKlausur20();
    //testingÜbung();

    return 0;
}
