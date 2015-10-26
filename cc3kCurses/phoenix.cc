#include "phoenix.h"
#include "helper.h"
#include <iostream>
using namespace std;

Phoenix::Phoenix(int n): Enemy(50,35+30*n,20+5*n,1,5+15*n) {}

const char Phoenix::getChar(){
	return 'x';
}

 std::string Phoenix:: getName(){
	return "Phoenix";
}
string Phoenix:: attack(player &p){
	string action="";
	int dmg=Atk*100/(p.getDef()+100);
	if(generate_int(0,100)>=p.getDR()){
	p.changeHP(-dmg);
	action=getName()+" deals "+IntToString(dmg)+" to PC and increase 15 Atk\n";
	changeAtk(15);
	}else{
		action=getName()+" misses\n";
	}
	return action;
}
Phoenix::~Phoenix(){}
