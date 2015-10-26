#include "object.h"
#include "player.h"
#include <string>

Object::Object():r(0),c(0){}

void Object::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Object::getRow(){
	return r;
}

int Object::getCol(){
	return c;
}

Object::~Object(){}
void Object:: changeDef(int n){}
void Object:: changeAtk(int n){}
int Object::getHP(){return 0;}
int Object::getAtk(){return 0;}
int Object::getDef(){return 0;}
int Object::getTreasure(){return 0;}
void Object::setDragonHoard(Treasure *t){}

Treasure * Object::getDragonHoard(){return NULL;}
void Object::attack(player *p){}
void Object::damage(int amount){}
bool Object::is_dead(){return true;}
int Object:: getExp(){return 10;}
void Object:: setFreeze(int n){}
bool Object::isFreeze(){return false;}
