#include"helper.h"
#include"player.h"
#include"race.h"
#include"elves.h"
#include"classes.h"
using namespace std;

elves:: elves(char*** map):race(map){
	HP=140;
	MaxHP=140;
	Atk=30;
	Def=10;
	quickness=0;
	AtkRate=5;
	DefRate=5;
	bonusDodge=100;
			cout<<"#####"<<endl;
	RaceSkill=new ShadowMeld();
}
string elves:: getName(){
	string c="";
	if(playerClass!=NULL) c=playerClass->getName();
	c="Elves "+c;
	return c;
}
string elves:: useRaceSkill(){
	return RaceSkill->use(*this);
}
void elves::coolDown(){
		if(quickness>0){
		quickness--;
		if(quickness==0){
			dodgeRate=dodgeRate-bonusDodge;
		}
	}
	RaceSkill->coolDown();
	if(playerClass!=NULL){
		playerClass->coolDown();
	}
}


elves:: ~elves(){}
void elves:: setBonus(int n){
	bonusDodge=n;
}
void elves:: setBonusTime(int n){
	quickness=n;
}
void elves:: printScore(){
    cout<<"Score is "<<Gold; 
}
