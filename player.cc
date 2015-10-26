#include "map.h"
#include"player.h"
#include"skill.h"
#include"helper.h"
#include"mage.h"
#include"spirithealer.h"
#include"bloodmage.h"
#include"ranger.h"
#include"deathknight.h"
#include"merchant.h"
#include"paladin.h"
#include"berserker.h"
#include"print.h"
#include"classes.h"
#include"warrior.h"
#include"knight.h"
#include "treasure.h"
#include "global.h"
#include<iostream>
#include<string>

using namespace std;


string player::getName(){ return ""; }


int player::TemAtk=0;
int player::TemDef=0;
player:: player(char*** map):playerClass(NULL),current(0),dodgeRate(50),amor(0),weapon(0),lv(1),exp(0),r(5),c(5),Gold(0),AtkRate(5),DefRate(5),map(map),MaxHPincRate(15){
	if(map==NULL) input=false;
	else input=true;
	TemAtk=0;
	TemDef=0;
	won=false;
	if(input){
	flr[0]=new floor(this,0,input,map[current]);
	}else{ 
	flr[0]=new floor(this,0,input);
	}
	for(int i=1;i<maxfloor;i++){
		flr[i]=NULL;
	}
//inventory NULL
}

bool player:: isMagic(){
	if(playerClass==NULL)return false;
	else return playerClass->isMagic();
}

bool player:: setClass(string cs){
	if(cs=="M"){
		playerClass=new mage();
		dodgeRate=20;
		HP=HP+50;
		MaxHP=MaxHP+50;
		Atk=Atk+10;
		Def=Def+5;
		changeHPRate(10);
		return true;
	}else if(cs=="W"){
		playerClass=new warrior();
		HP=HP+70;
		MaxHP=MaxHP+70;
		Def=Def+5;
		Atk=Atk+5;
		changeHPRate(15);
		return true;
	}else if(cs=="K"){
		playerClass=new knight();
		dodgeRate=35;
		HP=HP+100;
		MaxHP=MaxHP+100;
		Def=Def+10;
		Atk=Atk+5;
		changeHPRate(20);
		return true;
	}
	return false;
}
string player::move(string dir){
	char ch;
	string action="";
	string object="";
	string direction="";
	int prevr=r;
	int prevc=c;
	if(dir=="no"){
		r--;
		direction="North";
	}else if(dir=="so"){
		r++;
		direction="South";
	}else if(dir=="ea"){
		c++;
		direction="East";
	}else if(dir=="we"){
		c--;
		direction="West";
	}else if(dir=="ne"){
		c++;
		r--;
		direction="NorthEast";
	}else if(dir=="nw"){
		c--;
		r--;
		direction="NorthWest";
	}else if(dir=="se"){
		r++;
		c++;
		direction="SouthEast";
	}else if(dir=="sw"){
		r++;
		c--;
		direction="SouthWest";
	}else{}
	
	ch=flr[current]->check(r,c);
	if(ch=='.'||ch=='#'||ch=='+'){
		string see="";
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(i!=0||j!=0){
				ch=flr[current]->check(r+i,c+j);
				if(ch=='P') see=see+" PC sees a unknown potion";
				if(ch=='R') see=see+" PC sees a Rune";
				if(ch=='G'||c=='M') see=see+" PC sees gold";
				}
			}
		}
		action="PC moves "+direction+see;
		return action+"\n";
	}else if((ch=='P')||(ch=='G')||(ch=='M')||(ch=='R')){
		if(!bonus&& ch=='P'){
		 	r=prevr;
		 	c=prevc;
			return "something is in front of you, cannot move\n";
		 }
		 if(((ch=='P')||(ch=='R'))&&numItem==6){
		 	return "Inventory is full, cannot pick anymore";
		 }
		if(getnumItem()<=6) action=flr[current]->getItem(r,c,ch);
		else return "inventory full, cannot pick anymore";
		if((ch == 'G')&&(action != "cannot pick up dragonhoard, should kill dragon first.")){
			flr[current]->notify(prevr,prevc,r,c);
		} else if((ch == 'G')&&(action == "cannot pick up dragonhoard, should kill dragon first.")){
			r=prevr;
			c=prevc;
		}
		return action+"\n";
	}else if (ch=='\\'){
		if(current!=maxfloor-1){
		    current++;
	   	 	if(flr[current]==NULL) flr[current]=new floor(this,current,true);
			int row=generate_int(1,24);
			int col=generate_int(1,78);
			while(flr[current]->check(row,col)!='.'){
				row=generate_int(1,24);
				col=generate_int(1,78);
			}
			setR(row);
			setC(col);
	    	action="reachs "+ IntToString(current) +(std::string(" floor"));
	    	Atk=Atk-TemAtk;
	    	TemAtk=0;
	    	Def=Def-TemDef;
	    	TemDef=0;
	    	return action+"\n";
	    }
	    if(current==maxfloor-1) won=true;
	}else if(ch=='%'){
		current--;
		action="reachs "+ IntToString(current) +(std::string(" floor"));
		int row=generate_int(1,24);
		int col=generate_int(1,78);
		while(flr[current]->check(row,col)!='.'){
			row=generate_int(1,24);
			col=generate_int(1,78);
		}
		setR(row);
		setC(col);
		return action+"\n";
	}else{
		action="cannot moves "+direction;
		r=prevr;
		c=prevc;
		return action+"\n";
	}
	return "";
}


std::string player:: use(std::string dir){
	char ch;
	string action="";
	int enR=r;
	int enC=c;
	if(dir=="no"){
		enR--;
	}else if(dir=="so"){
		enR++;
	}else if(dir=="ea"){
		enC++;
	}else if(dir=="we"){
		enC--;
	}else if(dir=="ne"){
		enC++;
		enR--;
	}else if(dir=="nw"){
		enC--;
		enR--;
	}else if(dir=="se"){
		enR++;
		enC++;
	}else if(dir=="sw"){
		enR++;
		enC--;
	}else{
		return "cannot recgonice direction, please use (so/no/ea/we/nw/sw/se/ne)\n";
	}
	ch=flr[current]->check(enR,enC);
	if(ch=='P'){
		action=flr[current]->getItem(enR,enC,ch);
		useItem(0);
		return action;
	}else{
		return "not portion, cannot use\b";
	}
}
string player::attack(string dir){
	char ch;
	string action="";
	int enR=r;
	int enC=c;
	if(dir=="no"){
		enR--;
	}else if(dir=="so"){
		enR++;
	}else if(dir=="ea"){
		enC++;
	}else if(dir=="we"){
		enC--;
	}else if(dir=="ne"){
		enC++;
		enR--;
	}else if(dir=="nw"){
		enC--;
		enR--;
	}else if(dir=="se"){
		enR++;
		enC++;
	}else if(dir=="sw"){
		enR++;
		enC--;
	}else{
		action="cannot recgonice direction, please use (so/no/ea/we/nw/sw/se/ne)\n";
		return action;
	}
	if(flr[current]->check(enR,enC)=='e'){
		action=flr[current]->attack(enR,enC);
	}else{
		action="not enemy, cannot attack\n";
	}
	return action;
}

string player::useUSkill(){
	string action="";
	if(playerClass!=NULL){
	if(playerClass->advance()){
		action=playerClass->getuskill()->use(*this,*(flr[current]));
		return action;
	}
	}
	return "no ultimate skill availble";
}

string player::useCSkill1(){
	string action="";
	if(playerClass!=NULL){
	if(playerClass->getcs1()!=NULL){
		action=playerClass->getcs1()->use(*this,*(flr[current]));
		return action;
	}
	}
	return "no class skill availble";
}
string player::useCSkill2(){
	string action="";
	if(playerClass!=NULL){
	if(playerClass->getcs2()!=NULL){
		action=playerClass->getcs2()->use(*this,*(flr[current]));
		return action;
	}
	}
	return "no class skill availble";
}
//string player:: useClassSkill(int r,int c){
//		string action="";
//		//action=playerClass->useSkill(r,c);
//		return action;
//}


player ::~player(){
	delete playerClass;
	for(int i=0;i<7&&flr[i]!=NULL;i++){
		delete flr[i];
	}
}

void player::changeHPRate(int n){
    MaxHPincRate=n;
}
void player:: changeAtk(int n){
	Atk=Atk+n;
}
void player:: changeDef(int n){
	Def=Def+n;
}
void player:: changeDodge(int n){
	dodgeRate=dodgeRate+n;
}
void player:: changeHP(int n){
	HP=HP+n;
	if(HP>MaxHP) HP=MaxHP;
}


void player::incExp(int n){
	if(bonus)exp=exp+n;
	while(exp>lv*lv){
		exp=exp-lv*lv;
		cout<<"=========================!!!!!!!!!!!!!!!!!!========================="<<endl;
		cout<<"=========================!!!!!LEVEL UP!!!!!========================="<<endl;
		cout<<"=========================!!!!!!!!!!!!!!!!!!========================="<<endl;
		levelup();
	}
}

void player:: incGold(int n){
	Gold=Gold+n;
}
void player:: levelup(){
	lv++;
	changeAtk(AtkRate);
	changeDef(DefRate);
    MaxHP=MaxHP+(lv-1)*MaxHPincRate;
    changeHP(2*lv*MaxHPincRate);
	if(lv==5){
		printClassOption();
		string cs;
		cin>>cs;
		while(!setClass(cs)){
			cin>>cs;
		}
	}
	if(lv==10){
		cout<<"Congratulation!! you can evlove to advanced classes"<<endl;
		playerClass->evolve(*this);
	}
}

void player:: listInventory(){
	int i=0;
	if(numItem==0){
		cout<<"no item in inventory"<<endl;
		return;
	}
	while(i<6&&inventory[i]!=NULL){
		cout<<"item " + IntToString(i) + ": " + inventory[i]->getName()<<endl;
		i++;
	}
}
bool player:: getItem(Item* it){
	if(numItem==6) return false;
	else{
		inventory[numItem]=it;
		numItem++;
		return true;
	}
}


int player:: getMP(){
	if(playerClass==NULL) return 0;
	else return playerClass->getMP();
}
int player::getnumItem(){
	return numItem;
}

int player:: getR(){
	return r;
}
int player:: getC(){
	return c;
}
int player:: getLv(){
	return lv;
}
float player:: getGold(){
	return Gold;
}
int player:: getAtk(){
	return Atk;
}
int player:: getDef(){
	return Def;
}
int player:: getHP(){
	return HP;
}
int player:: getMaxHP(){
	return MaxHP;
}
int player:: getDR(){
	return dodgeRate;
}
void player::display(string action){
	flr[current]->display(action);
}

string player::useRaceSkill(){ return ""; }
void player:: setBonus(int n){}
void player:: setBonusTime(int n){}
void player:: coolDown(){}


void player:: setR(int n){
	r=n;
}
void player:: setC(int n){
	c=n;
}


string player::EnemyTurn(string action){
	return flr[current]->EnemyTurn(action);
}

skill* player::getskill(){ return NULL;}

void player:: listCSkill(){
	if(playerClass!=NULL){
		cout<<"key[us2]: "<<*(playerClass->getcs1())<<endl;
		cout<<"key[us3]: "<<*(playerClass->getcs2())<<endl;
		if(playerClass->advance()){
            cout<<"key[usu]: "<<*(playerClass->getuskill())<<endl;
        }
	}
}


bool player::isDead(){return HP<=0;}
classes* player:: getClass(){
	return playerClass;
}

void player:: evolve(mage& p){
	cout<<"BM for Blood Mage"<<endl;
	cout<<"SP for spirit Healer"<<endl;
	string cmd;
	while(cmd!="BM"&&cmd!="SP"){
		cin>>cmd;
	}
	if(cmd=="BM") playerClass=new bloodMage(playerClass);
	if(cmd=="SP") playerClass=new spiritHealer(playerClass);
}

void player:: evolve(warrior& p){
	cout<<"R for Ranger"<<endl;
	cout<<"B for Berserker"<<endl;
	string cmd;
	while(cmd!="R"&&cmd!="B"){
		cin>>cmd;
	}
	if(cmd=="R") playerClass=new Ranger(playerClass);
	if(cmd=="B") playerClass=new Berserker(playerClass);
}
void player:: evolve(knight& p){
	cout<<"DK for Death Knight"<<endl;
	cout<<"P for Paladin"<<endl;
	string cmd;
	while(cmd!="DK"&&cmd!="P"){
		cin>>cmd;
	}
	if(cmd=="DK") playerClass=new DeathKnight(playerClass);
	if(cmd=="P") playerClass=new Paladin(playerClass);
}

void player:: useItem(int i){
	if(i >= numItem){
		cout <<"no item at " <<IntToString(i)<<endl;
	} else if(inventory[i]==NULL){
		//string action;
		if(bonus)cout <<"no item at " <<IntToString(i)<<endl;
		//action = "no item at " + IntToString(i);
		//flr[current]->display(action);
	} else if(inventory[i]->getType()=='R'){
		//string action;
		//action = "You cannot use a Rune";
		//flr[current]->display(action);
		if(bonus) cout <<"You cannot use a Rune"<<endl;
	}else if(i>=0&&i<6&&inventory[i]!=NULL){
		//string action;
		inventory[i]->useItem(this);
		//action="PC uses " + inventory[i]->getName();
		if(bonus) cout<<"PC uses " <<	inventory[i]->getName()<<endl;
		//flr[current]->display(action);
		for(int j=i;j<5;j++){
			inventory[j]=inventory[j+1];
		}
		inventory[5]=NULL;
		numItem--;
	}
}
bool player:: dropItem(int i){
	if(i >= numItem||i<0){
		string action;
		cout<< "no item at " <<i<<endl;
		return false;
	} else if(i>=0&&i<6&&inventory[i]!=NULL){
		if(inventory[i]->getType()=='R'){
			inventory[i]->DropRune(*this);
		}
		cout<<"PC drops "<<inventory[i]->getName()<<endl;
		delete inventory[i];
		for(int j=i;j<5;j++){
			inventory[j]=inventory[j+1];
		}
		inventory[5]=NULL;
		numItem--;
		return true;
	}
	return false;
}


void player:: buyItem(){
	if (Merchant:: hostile){
	cout<<"the Compamy of Merchants are hostile to PC, they will never trade with any enemies!"<<endl;
	return;
	}
	if(numItem==6){
		cout<<"PC's inventory is full, cannot buy anymore"<<endl;
		return;
	}
	flr[current]->listGoods();
	cout<<"select which you want to buy, enter q to quit, every item cost 30 gold"<<endl;
	char num;
	cin>>num;
	if(num=='q') return;
	if(num-'0'>=0&&num-'0'<=4){
		if(Gold<30){
			cout<<"Not enough money"<<endl;
			return;
		}
		Item* it=flr[current]->getGoods(num-'0');
		if(it==NULL){
			cout<<"Item does not exist, buy fails"<<endl;
			return;
		}
		getItem(it);
		cout<<"you cost 30 gold to bougnt "<<it->getName()<<endl;
		Gold=Gold-30;
		return;
	}else{
		cout<<"buy fails"<<endl;
	}
}
void player::sellItem(){
	if (Merchant:: hostile){
	 cout<<"the Compamy of Merchants are hostile to PC, they will never trade with any enemies!"<<endl;
	 return;
	 }
	listInventory();
	cout<<"select which you want to sell, enter q to quit, every item is worth 10 gold"<<endl;
	char num;
	cin>>num;
	if(num=='q') return;
	if(num-'0'>=0&&num-'0'<=numItem){
		dropItem(num-'0');
		cout<<"you get 10 Gold"<<endl;
		Gold=Gold+10;
		return;
	}else{
		cout<<"sell fails"<<endl;
	}
	
}

void player:: printScore(){
    cout<<"Score is "<<getGold(); 
}

void player::changeGold(int n){
	Gold = Gold + n;
}
bool player::isWon(){
    return won;
}

