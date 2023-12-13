#include <iostream>
#include <vector>

template<typename T>

class IndexedList {
public:
    virtual T& operator[](long) = 0;
    virtual ~IndexedList() = default;
    std::size_t size;
    virtual T* begin() = 0; // liefert Pointer auf erstes Element zurück
    virtual T* end() = 0;   // liefert Pointer hinter(!) letztem Element zurück
};

template<typename T>
class ArrayList : public IndexedList<T> {
private:
    T* list;
public:
    ArrayList(std::size_t size) {
        this->size = size;  // Größe in size speichern
        list = new T[size]; // und C-Array im Speicher anlegen
    }
    ~ArrayList() override {
        delete(list);   // C-Array wieder löschen
    }
    T& operator[](long i) override {
        return list[i]; // Indizierung kann man direkt so durchreichen
    }
    T* begin() override {
        return &list[0];    // Erstes Element gleich Beginn des Speicherbereichs
    }
    T* end() override {
        return &list[this->size];   // Index hinter letztem Element gleich Ende des Speicherbereichs
    }
};

template<typename T>
class VectorList : public IndexedList<T> {
private:
    std::vector<T> list;
public:
    VectorList(long size) : list(std::vector<T>(size)) {
        // Vector-Array im Speicher anlegen
    }
    T& operator[](long i) override {
        return list[i]; // Indizierung kann man direkt so durchreichen
    }
    T* begin() override {
        return &list[0];    // Erstes Element gleich Beginn des Speicherbereichs
    }
    T* end() override {
        return &list[this->size];   // Index hinter letztem Element gleich Ende des Speicherbereichs
    }
};

template<typename T> void fill_list(IndexedList<T> &list) {
    // Ginge auch mit foreach, aber ich brauche zur Berechnung
    // der Zahlen ein i. Daher klassische for-Schleife mit i
    // von 0 bis list.size
    for(std::size_t i=0; i<list.size; i++) {
        list[i] = (list.size-i)*10;
    }
}

template<typename T> void print_list(IndexedList<T> &list) {
    for(T item : list) {    // foreach möglich wegen begin() und end()
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<typename T> void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void bubble_sort(IndexedList<T> &list) {
    for(std::size_t n=0; n<list.size-1; n++) {
        for(std::size_t i=n+1; i<list.size; i++) {
            if (list[i] < list[n]) swap(list[i], list[n]);
        }
    }
}

template<typename T>
void selection_sort(IndexedList<T> &list) {
    for(std::size_t n=0; n<list.size; n++) {
        std::size_t smallest_index = 0;
        for(std::size_t i=n; i<list.size-1; i++) {
            if (list[i] < list[smallest_index]) smallest_index = i;
        }
        swap(list[n],list[smallest_index]);
    }
}

void testing() {
    // Definition of datastructure and algorithms
    ArrayList<int> list(10);
    // VectorList<int> list(10);
    std::function<void (IndexedList<int>&)> sort_method = bubble_sort<int>;
    //std::function<void (IndexedList<int>&)> sort_method = selection_sort<int>;

    fill_list(list);
    swap(list[3], list[7]);
    print_list(list);
    sort_method(list);
    print_list(list);
    //return 0;
}


