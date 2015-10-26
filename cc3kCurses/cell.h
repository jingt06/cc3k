#ifndef __CELL_H__
#define __CELL_H__
#include"object.h"
#include<iostream>
class Cell{
	char structure;
	Object* obj;
	int label;
	public:
	Cell(char ch=' ');
	void reset();
	Object* getObj();
	void setObj(Object* obj);
	char type();
	void setStruct(char ch);
	int getlabel();
	void setlabel(int n);
	friend std:: ostream& operator<<(std::ostream &out, const Cell &c);
};
std:: ostream& operator<<(std::ostream &out, const Cell &c);

#endif
