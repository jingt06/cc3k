#include "item.h"
#include "object.h"
#include "player.h"
using namespace std;

Item::Item(): Object(), amount(0){}

int Item::getAmount(){
	return amount;
}

bool Item::getPickState(){return true;}

void Item::changePickState(){}

void Item::UseRune(player& p){}
void Item::DropRune(player& p){}

const bool Item::getisFromM(){return false;}
void Item::setisFromM(bool change){}

Item::~Item(){}
