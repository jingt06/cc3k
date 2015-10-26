#include "troll.h"
#include "helper.h"
#include <iostream>
using namespace std;
Troll::Troll(int n): Enemy(120+50*n,25+5*n,15+20*n,1+5*n,2+5*n) {}

const char Troll::getChar(){
	return 'T';
}
 std::string Troll:: getName(){
	return "Troll";
}
string Troll:: attack(player &p){
	string action="";
	int dmg=Atk*100/(p.getDef()+100);
	if(generate_int(0,100)>=p.getDR()){
	p.changeHP(-dmg);
	action=getName()+" deals "+IntToString(dmg)+" to PC and increase 10 Def\n";
	changeDef(10);
	}else{
		action=getName()+" misses\n";
	}
	return action;
}
Troll::~Troll(){}
