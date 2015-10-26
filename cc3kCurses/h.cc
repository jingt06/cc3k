#include <string>
#include "h.h"
#include "potion.h"
#include "player.h"
#include "helper.h" 

using namespace std;

//class player;

H::H(){}

void H::setAmount(int i){
	while(amount == 0){
		if(i==0) amount =generate_int(-10,10);
		else if(i>0) amount =generate_int(0,10);
		else amount =generate_int(-10,0);
	}
}

string H::getName(){
	string h;
	if(amount < 0){
		h = "Poison";
	} else {
		h = "Restore";
	}
	if(isFromM == false){
		return "Unknown Potion";
	} else {
		return h + " health";
	}
}

void H::useItem(player *p){
	Potion::setisFromM(true);
	if(-amount>p->getHP()) amount=-(p->getHP());
	if(amount < 0 && p->getName()[0] == 'E'){
		amount = -amount;
	}
	p->changeHP(amount);
	if(p->isDead()) p->changeHP(-(p->getHP())+1);
}


H::~H(){}
