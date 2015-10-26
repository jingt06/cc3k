#include "enemy.h"
#include "object.h"
#include "helper.h"
using namespace std;


Enemy::Enemy(int HP, int Atk, int Def,int Gold,int Exp) : Object(), HP(HP*100), Atk(Atk*100), Def(Def*100),Gold(Gold),Exp(Exp) {
freeze=0;}

int Enemy::getHP(){
	return HP;
}

int Enemy::getAtk(){
	return Atk;
}

int Enemy::getDef(){
	return Def;
}

int Enemy::getTreasure(){
	return Gold;
}


int Enemy:: getExp(){
	return Exp;
}

string Enemy::attack(player &p){
	string action="";
	int dmg=Atk*100/(p.getDef()+100);
	if(generate_int(0,100)>=p.getDR()){
	p.changeHP(-dmg);
		action=getName()+" deals "+IntToString(dmg)+" to PC\n";
	}else{
		action=getName()+" misses\n";
	}
	return action;
}


void Enemy:: changeDef(int n){
	Def=Def+n;
	if(Def<0) Def=0;
}
void Enemy:: changeAtk(int n){
	Atk=Atk+n;
	if(Atk<0) Atk=0;
}

void Enemy::damage(int amount){
	HP = HP - amount;
}

const char Enemy::getType(){
	return 'e';
}


void Enemy:: setFreeze(int n){
	freeze=n;
}
bool Enemy:: isFreeze(){
	if(freeze>0){
		freeze--;
		return true;
	}
	return false;
}

bool Enemy:: is_dead(){
	if(HP<=0) return true;
	else return false;
}

bool Enemy::getIsHostile(){return true;}

void Enemy::changeIsHostile(){}

Enemy::~Enemy(){}
