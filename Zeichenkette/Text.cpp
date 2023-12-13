#include "Text.h"
#include <iostream>
#include <cstring>

Text::Text() {
	std::cout << "Instanz erstellt.\n";
	text = NULL;
}

Text::~Text() {
	std::cout << "Instanz zerstört.\n";
	delete(text);
}

void Text::set(char* neu) {
	if (neu != NULL) {
		delete(text);
		text = strdup(neu);
	}
}

//char* Text::get() {
//	return text;
//}

void Text::out() {
	std::cout << text << " (" << (void*)text << ")" << std::endl;
}

char* Text::copy() {
	return strdup(text);
}

unsigned int Text::length() {
	unsigned int i;
	while(text[i] != '\0') {
		i++;
	}
	return i;
}

char Text::at(unsigned int i) {
	if (text==NULL || i >= length()) {
		std::cout << "Index exisistiert nicht. HILFE! Tschüss\n";
		exit(0);
	}
	return text[i];
}

char Text::first() {
	return at(0);
}

int Text::find(char suche) {
	if (text == NULL) return -1;
	unsigned int i = 0;
	while(text[i] != suche && text[i] != '\0') {
		i++;
	}
	if (text[i] != suche) return -1;
	return i;
}



