#include<string>
#include"skill.h"
#include"race.h"
#include"dwarf.h"
#include"classes.h"
#include"merchant.h"
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
void dwarf:: buyItem(){
	if (Merchant:: hostile){
	cout<<"the Compamy of Merchants are hostile to PC, they will never trade with any enemies!"<<endl;
	return;
	}
	if(numItem==6){
		cout<<"PC's inventory is full, cannot buy anymore"<<endl;
		return;
	}
	flr[current]->listGoods();
	cout<<"select which you want to buy, enter q to quit, every item cost 30"<<endl;
	char num;
	cin>>num;
	if(num=='q') return;
	if(num-'0'>=0&&num-'0'<=4){
		if(Gold<15){
			cout<<"Not enough money"<<endl;
			return;
		}
		Item* it=flr[current]->getGoods(num-'0');
		if(it==NULL){
			cout<<"Item does not exist, buy fails"<<endl;
			return;
		}
		getItem(it);
		cout<<"you cost 15 gold to bougnt "<<it->getName()<<endl;
		Gold=Gold-15;
		return;
	}else{
		cout<<"buy fails"<<endl;
	}
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
float dwarf:: getGold(){
	return (float)Gold*2;
}
void dwarf:: printScore(){
    cout<<"Score is "<<getGold(); 
}


