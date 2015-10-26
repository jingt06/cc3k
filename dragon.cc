#include "dragon.h"

Dragon::Dragon(int n): Enemy(150+50*n,20+10*n,20+10*n,0+15*n,5+5*n*n),t(NULL),isHostile(false) {}

const char Dragon::getChar(){
	return 'D';
}

std::string Dragon:: getName(){
	return "Dragon";
}

void Dragon::setDragonHoard(Treasure *t){
	this->t = t;
}

Treasure * Dragon::getDragonHoard(){
	return t;
}
bool Dragon::getIsHostile(){
	return isHostile;
}

void Dragon::changeIsHostile(){
	isHostile=!isHostile;
}
Dragon::~Dragon(){}
