#include"cell.h"
using namespace std;
Cell::Cell(char ch):structure(ch),label(0),obj(NULL){}
void Cell:: reset(){
	obj=NULL;
}

int Cell:: getlabel(){
	return label;
}
void Cell:: setlabel(int n){
	label=n;
}
void Cell:: setObj(Object* obj){
	this->obj=obj;
}

Object* Cell:: getObj(){
	return obj;
}

char Cell::type(){
	if(obj==NULL){
		if(structure=='.'||structure=='#'||structure=='+'||structure=='%') return structure;
		else if(structure=='\\') return '\\';
		else return'x';
	}else{
		return obj->getType();
	}
}

std:: ostream& operator<<(std::ostream &out, const Cell &c){
	if(c.obj==NULL){
		cout<<c.structure;
	}else{
		cout<<c.obj->getChar();
	}
	return out;
}


void Cell:: setStruct(char ch){
	structure=ch;
}
