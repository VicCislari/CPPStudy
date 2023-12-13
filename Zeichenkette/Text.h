#ifndef TEXT_H_
#define TEXT_H_

class Text {
private:
	char* text;
public:
	Text();
	~Text();
	void set(char*);
	//	char* get();	Keine gute Idee dies zu programmieren!
	void out();
	char* copy();
	unsigned int length();
	char at(unsigned int);
	char first();
	int find(char);
};

#endif /* TEXT_H_ */
