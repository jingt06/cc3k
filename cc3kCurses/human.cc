#include<string>
#include"skill.h"
#include"race.h"
#include"human.h"
#include"classes.h"
#include<ncurses.h>
using namespace std;
human:: ~human(){}
void human:: setBonus(int n){
}
void human:: setBonusTime(int n){
}
void human::coolDown(){
	RaceSkill->coolDown();
	if(playerClass!=NULL){
		playerClass->coolDown();
	}
}
human:: human(char*** map):race(map){
	HP=100000;
	MaxHP=100000;
	Atk=20000;
	Def=1000;
	AtkRate=5;
	DefRate=5;
	RaceSkill=new HumanSpirit();
}

string human::  getName(){
	string c="";
	if(playerClass!=NULL) c=playerClass->getName();
	c="Human "+c;
	return c;
}
string human:: useRaceSkill(){
	return RaceSkill->use(*this);
}

void human:: printScore(){
    printw("Score is %d",Gold*3/2); 
}
