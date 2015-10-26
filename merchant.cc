#include "helper.h"
#include "merchant.h"
#include "global.h"
#include <iostream>
#include <string>
using namespace std;

bool Merchant:: hostile=false;
Merchant::Merchant(int n): Enemy(30+50*n,70+50*n,5+20*n,0+10*n,3+5*n) {}

const char Merchant::getChar(){
	return 'M';
}

 std::string Merchant:: getName(){
	return "Merchant";
}	

string Merchant:: attack(player &p){
	string action="";
	if(hostile){
	int dmg=Atk*100/(p.getDef()+100);
	if(generate_int(0,100)>=p.getDR()){
	p.changeHP(-dmg);
	action=getName()+" deals "+IntToString(dmg)+" to PC\n";
	}else{
		return getName()+" misses\n";
	}
	}else{
		if(bonus)return "Merchant welcoms PC \nenter sell to sell item , enter buy to buy items at any time\n";
		else "Merchant welcoms PC \n";
		}
	return action;
}
Merchant::~Merchant(){}
