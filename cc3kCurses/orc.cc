#include<string>
#include"skill.h"
#include"race.h"
#include"classes.h"
#include"orc.h"
#include"merchant.h"
#include<ncurses.h>
#include<cstring>
using namespace std;
orc:: orc(char*** map):race(map){
	RaceSkill=new BloodFury();
	fury=0;
	HP=180;
	MaxHP=180;
	Atk=30;
	Def=25;
	AtkRate=8;
	DefRate=5;
	int bonusAtk=Atk/3;
}

orc:: ~orc(){}

string orc:: getName(){
	string c="";
	if(playerClass!=NULL) c=playerClass->getName();
	c="Orc "+c;
	return c;
}

void orc::coolDown(){
	if(fury>0){
		fury--;
		if(fury==0){
			Atk=Atk-bonusAtk;
		}
	}
	RaceSkill->coolDown();
	if(playerClass!=NULL){
		playerClass->coolDown();
	}
}
string orc:: useRaceSkill(){
	return RaceSkill->use(*this);
}

void orc:: buyItem(){
	if (Merchant:: hostile){
	printw("the Compamy of Merchants are hostile to PC, they will never trade with any enemies!\n");
	return;
	}
	if(numItem==6){
		printw("PC's inventory is full, cannot buy anymore\n");
		return;
	}
	flr[current]->listGoods();
	printw("select which you want to buy, enter q to quit, every item cost 30\n");;
	char num;
	cin>>num;
	if(num=='q') return;
	if(num-'0'>=0&&num-'0'<=4){
		if(Gold<60){
			printw("Not enough money\n");;
			return;
		}
		Item* it=flr[current]->getGoods(num-'0');
		if(it==NULL){
			printw("Item does not exist, buy fails\n");;
			return;
		}
		getItem(it);
		char *name=new char[it->getName().size()+1];
		name[it->getName().size()]=0;
		strcpy(name,it->getName().c_str());
		printw("you cost 60 gold to bougnt %s\n",name);
		Gold=Gold-60;
		return;
	}else{
		printw("buy fails\n");
	}
}

float orc:: getGold(){
	return (float) Gold/2;
}


void orc:: setBonus(int n){
	bonusAtk=n;
}
void orc:: setBonusTime(int n){
	fury=n;
}

void orc:: printScore(){
    printw("Score is %f",getGold());  
}
