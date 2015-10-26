#include "enemy.h"
#include "object.h"
#include "helper.h"
#include "boss.h"
using namespace std;
Boss::Boss(int HP, int Atk, int Def,int Gold,int Exp,std::string name):Enemy(HP,Atk,Def,Gold,Exp){
	freeze=0;
	this->name=name;
}
void Boss:: setFreeze(int n){}
std::string Boss::getName(){
	return name;
}
const char Boss::getChar(){
	return 'B';
}

string Boss::attack(player &p){
	string action="";
	int dmg=Atk*100/(p.getDef()/2+100);
	if(generate_int(0,100)>=(p.getDR())/2){
	p.changeHP(-dmg);
		action=getName()+" deals "+IntToString(dmg)+" to PC\n";
	}else{
		action=getName()+" misses\n";
	}
	return action;
}

