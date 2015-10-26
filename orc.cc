#include<string>
#include"skill.h"
#include"race.h"
#include"classes.h"
#include"orc.h"
#include"merchant.h"
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


void orc:: setBonus(int n){
	bonusAtk=n;
}
void orc:: setBonusTime(int n){
	fury=n;
}

void orc:: printScore(){
    cout<<"Score is "<<getGold(); 
}
float orc:: getGold(){
	return (float)Gold/2;
}
void orc:: buyItem(){
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
		if(Gold<60){
			cout<<"Not enough money"<<endl;
			return;
		}
		Item* it=flr[current]->getGoods(num-'0');
		if(it==NULL){
			cout<<"Item does not exist, buy fails"<<endl;
			return;
		}
		getItem(it);
		cout<<"you cost 60 gold to bougnt "<<it->getName()<<endl;
		Gold=Gold-60;
		return;
	}else{
		cout<<"buy fails"<<endl;
	}
}
