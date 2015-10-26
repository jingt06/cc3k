#include "potion.h"
#include "item.h"

using namespace std;

Potion::Potion() : isFromM(false){}

const char Potion::getType(){
	return 'P';
}

const char Potion::getChar(){
	return 'P';
}

const bool Potion::getisFromM(){
	return isFromM;
}

void Potion::setisFromM(bool change){
	isFromM = change;
}

Potion::~Potion(){}
