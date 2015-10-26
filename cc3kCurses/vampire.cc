#include "vampire.h"
#include "helper.h"
#include <iostream>
using namespace std;

Vampire::Vampire(int n): Enemy(50+20*n,25+15*n,25,1+3*n,3+5*n) {}

const char Vampire::getChar(){
	return 'v';
}
 std::string Vampire:: getName(){
	return "Vampire";
}
string Vampire:: attack(player &p){
	string action="";
	int dmg=Atk*100/(p.getDef()+100);
	if(generate_int(0,100)>=p.getDR()){
	p.changeHP(-dmg);
	damage((-dmg/3));
	action=getName()+" deals "+IntToString(dmg)+" to PC and recover "+IntToString(dmg/3)+" HP \n";
	}else{
	action="Vampire misses\n";
	}
	return action;
}
Vampire::~Vampire(){}
