#include<string>
#include"skill.h"
#include"race.h"
#include"dwarf.h"
#include<ncurses.h>
#include"merchant.h"
#include"classes.h"
#include<cstring>
using namespace std;

dwarf:: ~dwarf(){}



dwarf:: dwarf(char*** map):race(map){
	HP=100;
	MaxHP=100;
	Atk=20;
	Def=30;
	AtkRate=5;
	DefRate=8;
	bonusDef=Def;
	stone=0;
	RaceSkill=new StoneForm();
}

void dwarf:: buyItem(){
	if (Merchant:: hostile){
	printw("the Compamy of Merchants are hostile to PC, they will never trade with any enemies!\n");
	return;
	}
	if(numItem==6){
		printw("PC's inventory is full, cannot buy anymore\n");
		return;
	}
	flr[current]->listGoods();
	printw("select which you want to buy, enter q to quit, every item cost 30\n");
	char num;
	cin>>num;
	if(num=='q') return;
	if(num-'0'>=0&&num-'0'<=4){
		if(Gold<15){
			printw("Not enough money\n");
			return;
		}
		Item* it=flr[current]->getGoods(num-'0');
		if(it==NULL){
			printw("Item does not exist, buy fails\n");
			return;
		}
		getItem(it);
		char *name=new char[it->getName().size()+1];
		name[it->getName().size()]=0;
		strcpy(name,it->getName().c_str());
		printw("you cost 15 gold to bougnt %s\n",name);
		Gold=Gold-15;
		return;
	}else{
		printw("buy fails\n");
	}
}

string dwarf:: getName(){
	string c="";
	if(playerClass!=NULL) c=playerClass->getName();
	c="Dwarf "+c;
	return c;
}
void dwarf:: setBonus(int n){
	bonusDef=n;
}
void dwarf:: setBonusTime(int n){
	stone=n;
}
void dwarf::coolDown(){
	if(stone>0){
		stone--;
	if(stone==0){
			Def=Def-bonusDef;
		}
	}
	RaceSkill->coolDown();
	if(playerClass!=NULL){
		playerClass->coolDown();
	}
}
string dwarf:: useRaceSkill(){
	return RaceSkill->use(*this);
}
void dwarf:: printScore(){
    printw("Score is %f",getGold()); 
}

float dwarf:: getGold(){
	return (float)Gold*2;
}


