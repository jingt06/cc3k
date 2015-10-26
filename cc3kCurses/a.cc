#include <string>
#include "a.h"
#include "potion.h"
#include "player.h"
#include "helper.h"


using namespace std;

A::A(){}

void A::setAmount(int i){
	while(amount == 0){
		if(i==0) amount =generate_int(-1,1)*5;
		else if(i>0) amount=5;
		else amount=-5;
	}
}

string A::getName(){
	string s;
	if(amount < 0){
		s = "Wound";
	} else {
		s = "Boost";
	}
	if(isFromM == false){
		return "Unknown Potion";
	} else {
		return s + " Atk";
	}
}

void A::useItem(player *p){
	Potion::setisFromM(true);
	if(-amount>p->getAtk()) amount=-(p->getAtk());
	if(amount < 0 && p->getName()[0] == 'E'){
		amount = -amount;
	}
	p->changeAtk(amount);
	player::TemAtk=player::TemAtk+amount;
}


A::~A(){}
