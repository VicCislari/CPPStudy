#include <iostream>
#include "Text.h"


Text* erstelle_instanz() {
	Text* pointer_auf_instanz = new Text;
	return pointer_auf_instanz;
}


int main() {
	Text* text = erstelle_instanz();

	text->set("Hallo Welt");
	text->out();

	char* kopie = text->copy();
	std::cout << kopie << " (" << (void*)kopie << ")" << std::endl;
	delete(kopie);

//	char* original = text->get();
//	std::cout << original << " (" << (void*)original << ")" << std::endl;
//	delete(original);

	std::cout << "Die Länge ist " << text->length() << std::endl;
	std::cout << "Zeichen am Index 1 ist " << text->at(1) << std::endl;
	std::cout << "Erste Zeichen lautet " << text->first() << std::endl;
	std::cout << "Zeichen W an Stelle " << text->find('W') << std::endl;
	std::cout << "Zeichen * an Stelle " << text->find('*') << std::endl;

	delete(text);
	return 0;
}
