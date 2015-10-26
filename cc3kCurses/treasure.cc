#include "treasure.h"
#include "helper.h"
#include "player.h"
#include "dragon.h"

using namespace std;

Treasure::Treasure():PickState(true) {}

void Treasure::setAmount(int i){
	if(i == 0){
		int t=generate_int(1,8);
		if(t <= 5){
			amount = 1;
		} else if(t == 8){
			amount = 6;
		} else {
			amount = 2;
		}
	} else{
		amount = i;
	}
}
const char Treasure::getType(){
	if(getName() == "merchant hoard"){return 'M';}
	return 'G';
}
string Treasure::getName(){
	if(amount == 1){
		return "normal";
	} else if(amount == 2){
		return "small hoard";
	} else if(amount == 4){
		return "merchant hoard";
	} else if(amount == 6){
		return "dragon hoard";
	} else {
		return "";
	}
}

const char Treasure::getChar(){
	return 'G';
}

void Treasure::useItem(player *p){
	p->changeGold(amount);
}

bool Treasure::getPickState(){
	return PickState;
}

void Treasure::changePickState(){
	if(PickState == false){
		PickState = true;
	} else {
		PickState = false;
	}
}
void Treasure::setDragon(Dragon * dragon){
	this->dragon = dragon;
}
Dragon* Treasure::getDragon(){
	return dragon;
}
Treasure::~Treasure(){}
