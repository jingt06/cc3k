#include <string>
#include "d.h"
#include "potion.h"
#include "player.h"
#include "helper.h"


using namespace std;

D::D(){}

void D::setAmount(int i){
	while(amount == 0){
		if(i==0) amount =generate_int(-1,1)*5;
		else if(i>0) amount=5;
		else amount=-5;
	}
}

string D::getName(){
	string s;
	if(amount < 0){
		s = "Wound";
	} else {
		s = "Boost";
	}
	if(isFromM == false){
		return "Unknown Potion";
	} else {
		return s + " Def";
	}
}


void D::useItem(player *p){
	Potion::setisFromM(true);
	if(-amount>p->getDef()) amount=-(p->getDef());
	if(amount < 0 && p->getName()[0] == 'E'){
		amount = -amount;
	} 
	p->changeDef(amount);
	player::TemDef=player::TemDef+amount;

}


D::~D(){}
