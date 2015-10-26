#include "map.h"
#include "floor.h"
#include "helper.h"
#include"enemy.h"
#include"dragon.h"
#include"goblin.h"
#include"merchant.h"
#include"vampire.h"
#include"rgm.h"
#include"troll.h"
#include"item.h"
#include"h.h"
#include"a.h"
#include"d.h"
#include"werewolf.h"
#include"phoenix.h"
#include"boss.h"
#include "treasure.h"///////
#include "dragon.h"
#include "rune.h"
#include "runes.h"
#include"ncurses.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
floor::floor(player* p, const int& level,bool ran,char ** maps):maxEnemy(20), maxItem(10), maxWidth(80), maxHeight(25),B(NULL), p(p), level(level), numEnemy(0), numItem(0),random(ran),nummercdead(0),numdragon(0),numTreasure(0){
	if(maps!=NULL) random=false;
	for(int i = 0; i < 20; i++){
		floorEnemy[i] = NULL;
	}
	for(int i = 0; i < 5; i++){
		merchantGoods[i] = NULL;
	}
	for(int i = 0; i < 10; i++){
		floorItem[i] = NULL;
	}
	for(int i = 0; i < 10; i++){
		floorTreasure[i] = NULL;
	}
	for(int i = 0; i < 20; i++){
		merchantHoard[i] = NULL;
	}
	for(int i = 0; i < 10; i++){
		dragon[i] = NULL;
	}
	theWorld = new Cell * [maxHeight];
	for(int i = 0; i < maxHeight; i++){
		theWorld[i] = new Cell [maxWidth];
	}
	if(maps!=NULL){
		for(int i = 0; i < maxHeight; i++){
			for(int j = 0; j < maxWidth; j++){
				if(maps[i][j]<'0'||maps[i][j]>'9'){
					theWorld[i][j] = Cell(maps[i][j]);
				}else if(maps[i][j]<='5'){
					theWorld[i][j] = Cell('.');
					addItem(maps[i][j]-'0',i,j);
				}else if(maps[i][j]>='6'){
					theWorld[i][j] = Cell('.');
					addTreasure(maps[i][j]-'0',i,j);
				}
			}
		}
	}else if(ran){
	char** mp=RanGenMap(6);
		for(int i = 0; i < maxHeight; i++){
			for(int j = 0; j < maxWidth; j++){
				theWorld[i][j] = Cell(mp[i][j]);
			}
		}
		for (int i=0; i<maxHeight; i ++)
		{
			delete [] mp[i];
		}
		delete [] mp;
	}else{
		for(int i = 0; i < maxHeight; i++){
			for(int j = 0; j < maxWidth; j++){
				theWorld[i][j] = Cell(gmap[i][j]);
			}
		}
	}
	if(ran) B= &(Boss::bosses[level]);
	int NumRoom=label();
	int chamber=generate_int(1,NumRoom);
	int playerChamber=chamber;
	int row=generate_int(1,24);
	int col=generate_int(1,78);
	while(check(row,col)!='.'||theWorld[row][col].getlabel()!=chamber){
		row=generate_int(1,24);
		col=generate_int(1,78);
	}
	p->setR(row);
	p->setC(col);
	chamber=generate_int(1,NumRoom);
	while(chamber==playerChamber){
		chamber=generate_int(1,NumRoom);
	}
	
	row=generate_int(1,24);
	col=generate_int(1,78);
	while(check(row,col)!='.'||theWorld[row][col].getlabel()!=chamber){
		row=generate_int(1,24);
		col=generate_int(1,78);
	}
	if(ran){
		theWorld[row][col].setObj(B);
		B->setCoords(row,col);
	}
	while(check(row,col)!='.'||theWorld[row][col].getlabel()!=chamber){
			row=generate_int(1,24);	
			col=generate_int(1,78);
		}
	if(!ran)theWorld[row][col].setStruct('/');
	if(level!=0){
		while(check(row,col)!='.'){
			row=generate_int(1,24);	
			col=generate_int(1,78);
		}
		theWorld[row][col].setStruct('%');
	}
	if (maps==NULL)generateItem(level,NumRoom);
	if (maps==NULL)generateTreasure(level,NumRoom);
	generateEnemy(level,NumRoom);
	generateGoods();
}
string floor::getItem(int r, int c, char ch){
	if(ch == 'P'||ch == 'R'){
		for(int i = 0; i < numItem; i++){
			if((floorItem[i]->getRow() == r)&&(floorItem[i]->getCol() == c)){
				p->getItem(floorItem[i]);
				if(ch=='R'){
					floorItem[i]->UseRune(*p);
				}
				theWorld[r][c].reset();
			
				return "picks "+floorItem[i]->getName();
			}
		}
		return "inventory is full, cannot pick up";
	} else if(ch == 'G'){
		string s;
		int i = 0;
		for(; i < numTreasure; i++){
			
			if((floorTreasure[i]->getRow() == r)&&(floorTreasure[i]->getCol() == c)&&(floorTreasure[i]->getPickState() == true)){
				floorTreasure[i]->useItem(p);
				s = floorTreasure[i]->getName();
				theWorld[r][c].reset();
				break;
			} else if((floorTreasure[i]->getRow() == r)&&(floorTreasure[i]->getCol() == c)&&(floorTreasure[i]->getPickState() == false)){
				break;
			}
		}
		if(floorTreasure[i]->getPickState() == true)return "picks " + s;
		else {return "cannot pick up dragonhoard, should kill dragon first.";}
	} else {
		string s;
		for(int i = 0; i < 20; i++){
			if((merchantHoard[i]->getRow() == r)&&(merchantHoard[i]->getCol() == c)){
				merchantHoard[i]->useItem(p);
				s = merchantHoard[i]->getName();
				theWorld[r][c].reset();
				break;
			}
		}
		return "picks " + s;
	}
}

void floor:: addItem(int n,int r,int c){
	Item* it=NULL;
	if(n==0){
		it=new H();
		it->setAmount(1);
	}else if(n==1){
		it=new A();
		it->setAmount(1);
	}else if(n==2){
		it=new D();
		it->setAmount(1);
	}else if(n==3){
		it=new H();
		it->setAmount(-1);
	}else if(n==4){
		it=new A();
		it->setAmount(-1);
	}else if(n==5){
		it=new D();
		it->setAmount(-1);
	}
	it->setCoords(r,c);
	floorItem[numItem]=it;
	theWorld[r][c].setObj(it);
	numItem++;
}

void floor::addTreasure(int n,int r,int c){
	if(n==8) return;
	Treasure* t=new Treasure();
	if(n==6){
		t->setAmount(1);
	}else if(n==7){
		t->setAmount(2);
	}else if(n==8){
		t->setAmount(4);
	}else if(n==9){
		t->setAmount(6);
		dragon[numdragon] = new Dragon(level);
		t->setDragon(dragon[numdragon]);
		int nr = r,nc = c;
		if(check(r,c-1) == '.'){
			nc = c-1;
		}else if(check(r,c+1) == '.'){
			nc = c+1;
		}else if(check(r-1,c) == '.'){
			nr = r-1;
		}else if(check(r+1,c) == '.'){
			nr = r+1;
		}
		dragon[numdragon]->setCoords(nr,nc);
		dragon[numdragon]->setDragonHoard(floorTreasure[numTreasure]);
		theWorld[nr][nc].setObj(dragon[numdragon]);
		numdragon++;
	}
	t->setCoords(r,c);
	floorTreasure[numTreasure]=t;
	theWorld[r][c].setObj(t);
	numTreasure++;
}


void floor::label(int i,int j,int c){
	theWorld[i][j].setlabel(c);
	if(i-1>=0){
		if(theWorld[i-1][j].type()=='.'&&theWorld[i-1][j].getlabel()==0) label(i-1,j,c);
	}
	if(j-1>=0){
		if(theWorld[i][j-1].type()=='.'&&theWorld[i][j-1].getlabel()==0) label(i,j-1,c);
	}
	if(i+1<25){
		if(theWorld[i+1][j].type()=='.'&&theWorld[i+1][j].getlabel()==0) label(i+1,j,c);
	}
	if(j+1<80){
		if(theWorld[i][j+1].type()=='.'&&theWorld[i][j+1].getlabel()==0) label(i,j+1,c);
	}
}

int floor::label(){
	int count=0;
	for(int i=0;i<25;i++){
		for (int j = 0; j < 80; j += 1){
			if(theWorld[i][j].type()=='.'&&theWorld[i][j].getlabel()==0){
				count++;
				label(i,j,count);
			}
		}
	}
	return count;
}

void floor::notify(int prevr,int prevc,int r,int c){
	theWorld[r][c].setObj(theWorld[prevr][prevc].getObj());
	if(prevr!=r||prevc!=c)theWorld[prevr][prevc].reset();
}

void floor::display(string action){
	for(int i=0;i<maxHeight;i++){
		for(int j=0;j<maxWidth;j++){
			if(i==p->getR()&&j==p->getC()) printw("@");
			else cout<<theWorld[i][j];
		}
		printw("\n");
	}
	char *name=new char[p->getName().size()+1];
	name[p->getName().size()]=0;
	strcpy(name,p->getName().c_str());
	printw("%s level: %d  Gold: %.1f                              floor: %d\n",name,p->getLv(),p->getGold(),level);
	delete name;
printw("HP: %d/%d",p->getHP(),p->getMaxHP());
	if(p->isMagic()) printw("  MP: %d",p->getMP());
	printw("\n");
	printw("Atk: %d Def: %d\n",p->getAtk(),p->getDef());
	printw("DodgeRate: ");
	if(p->getDR()>100){
		printw("100\n");
	}else{
		printw("%d\n",p->getDR());
	}
	char *str=new char[action.size()+1];
	str[action.size()]=0;
	strcpy(str,action.c_str());
	printw("Action: %s",str);
}

void floor:: resetCell(int r,int c){
	theWorld[r][c].reset();
}

char floor::check(int r, int c){
	return theWorld[r][c].type();
}

void floor::generateEnemy(int level,int n){
	int r=0;
	int c=0;
	int chamber=0;
	for(int i=0;i<maxEnemy;i++){
		int rand=generate_int(1,18);
			chamber=generate_int(1,n);
			r=generate_int(1,24);
			c=generate_int(1,78);
			while(check(r,c)!='.'||theWorld[r][c].getlabel()!=chamber){
				r=generate_int(1,24);
				c=generate_int(1,78);
			}
		if(rand<=4){
			floorEnemy[i]=new Werewolf(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}else if(rand<=7){
			floorEnemy[i]=new Vampire(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}else if(rand<=12){
			floorEnemy[i]=new Goblin(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}else if(rand<=14){
			floorEnemy[i]=new Troll(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}else if(rand<=16){
			floorEnemy[i]=new Phoenix(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}else if(rand<=18){
			floorEnemy[i]=new Merchant(level);
			floorEnemy[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorEnemy[i]);
		}
		numEnemy++;
	}
}


std:: string floor:: attack(int r,int c){
	if(theWorld[r][c].getObj()->getChar()=='m') Merchant::hostile=true;
	int dmg=p->getAtk()*100/(100+theWorld[r][c].getObj()->getDef());
	theWorld[r][c].getObj()->damage(dmg);
	string action="player deals "+ IntToString(dmg);
	int restHP=theWorld[r][c].getObj()->getHP();
	action=action+" to "+theWorld[r][c].getObj()->getName()+"("+IntToString(restHP)+")"+"\n"; 
	if(theWorld[r][c].getObj()->is_dead()) {
		int gold=theWorld[r][c].getObj()->getTreasure();
		int exp=theWorld[r][c].getObj()->getExp();
		p->incGold(gold);
		p->incExp(exp);
		action=action+"you kills "+theWorld[r][c].getObj()->getName()+"\n";
		action=action+"you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n";
		if(theWorld[r][c].getObj()->getChar() =='d'){
			theWorld[r][c].getObj()->getDragonHoard()->changePickState();
		}
		if(theWorld[r][c].getObj()->getChar() !='m'){
			theWorld[r][c].reset();
		} else if(theWorld[r][c].getObj()->getChar() =='m'){
			merchantHoard[nummercdead] = new Treasure();
			merchantHoard[nummercdead]->setAmount(4);
			merchantHoard[nummercdead]->setCoords(r,c);
			//theWorld[r][c].reset();
			theWorld[r][c].setObj(merchantHoard[nummercdead]);
			nummercdead++;
		}
	}
	return action;
}


void floor::generateGoods(){
	Item * it=NULL;
	for (int i=0; i<5; i ++)
	{
		int rand=generate_int(0,20);
		if(rand<=5){
			it=new H();
			it->setAmount(1);
		}else if(rand<=11){
			it=new A();
			it->setAmount(1);
		}else if(rand<=17){
			it=new D();
			it->setAmount(1);
		}else if(rand<=18){
			it=new StrengthRune();
		}else if(rand<=19){
			it=new QuicknessRune();
		}else if(rand<=20){
			it=new HardnessRune();
		}
		it->setisFromM(true);
		merchantGoods[i]=it;
		numGoods++;
	}
}

void floor::listGoods(){
	int i=0;
	while(i<numGoods&&merchantGoods[i]!=NULL){
		char *name=new char[merchantGoods[i]->getName().size()+1];
		name[p->getName().size()]=0;
		strcpy(name,merchantGoods[i]->getName().c_str());
		printw("item %d: %s\n", i,name);
		delete name;
		i++;
	}
}

void floor::generateItem(int level,int n){
	int r=0;
	int c=0;
	int chamber=0;
	for(int i=0;i<maxItem;i++){
		int rand=0;
		if(!random) rand=generate_int(1,150);
		if(random) rand=generate_int(1,200);
		chamber=generate_int(1,n);
		r=generate_int(1,24);
		c=generate_int(1,78);
		while(check(r,c)!='.'||theWorld[r][c].getlabel()!=chamber){
			r=generate_int(1,24);
			c=generate_int(1,78);
		}
		if(rand<=50){
			floorItem[i]=new H();
			floorItem[i]->setAmount(0);
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=100){
			floorItem[i]=new A();
			floorItem[i]->setAmount(0);
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=150){
			floorItem[i]=new D();
			floorItem[i]->setCoords(r,c);
			floorItem[i]->setAmount(0);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=160){
			floorItem[i]=new StrengthRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=170){
			floorItem[i]=new QuicknessRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=180){
			floorItem[i]=new HardnessRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=188){
			floorItem[i]=new HealthRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=196){
			floorItem[i]=new PowerRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}else if(rand<=200){
			floorItem[i]=new GodRune();
			floorItem[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorItem[i]);
		}
		numItem++;
	}
}

void floor::generateTreasure(int level,int n){ ///////
	int r=0;
	int c=0;
	int chamber=0;
	for(int i=0;i<10;i++){
		chamber=generate_int(1,n);
		r=generate_int(1,24);
		c=generate_int(1,78);
		while(check(r,c)!='.'||theWorld[r][c].getlabel()!=chamber){
			r=generate_int(1,24);
			c=generate_int(1,78);
		}
		floorTreasure[i]=new Treasure();
		floorTreasure[i]->setAmount(0);
		if(floorTreasure[i]->getAmount() != 6){
			floorTreasure[i]->setCoords(r,c);
			theWorld[r][c].setObj(floorTreasure[i]);
		} else if(floorTreasure[i]->getAmount() == 6){
			while((check(r,c)!='.'||theWorld[r][c].getlabel()!=chamber)||
				(!(check(r+1,c)=='.'|| check(r-1,c)=='.'||  check(r,c+1)=='.' || check(r,c-1)=='.'))) {
				r=generate_int(1,24);
				c=generate_int(1,78);
			}
			floorTreasure[i]->setCoords(r,c);
			floorTreasure[i]->changePickState();
			theWorld[r][c].setObj(floorTreasure[i]);

			dragon[numdragon] = new Dragon(level);
			floorTreasure[i]->setDragon(dragon[numdragon]);
			int nr = r,nc = c;
			if(check(r,c-1) == '.'){
				nc = c-1;
			}else if(check(r,c+1) == '.'){
				nc = c+1;
			}else if(check(r-1,c) == '.'){
				nr = r-1;
			}else if(check(r+1,c) == '.'){
				nr = r+1;
			}
			dragon[numdragon]->setCoords(nr,nc);
			dragon[numdragon]->setDragonHoard(floorTreasure[i]);

			theWorld[nr][nc].setObj(dragon[numdragon]);
			numdragon++;
		}
		numTreasure++;
	}
}


Item* floor::getGoods(int i){
	if(i>=0&&i<numGoods){
		numGoods--;
		Item* it=merchantGoods[numGoods];
		merchantGoods[numGoods]=merchantGoods[i];
		merchantGoods[i]=it;
		return merchantGoods[numGoods];
	}
	return NULL;
}

Object* floor:: getObj(int r,int c){
	return theWorld[r][c].getObj();
}

string floor:: EnemyTurn(string action){	
	int ER,EC;
	int count=0;
	int PR=p->getR();
	int PC=p->getC();
	for(int i=0;i<20;i++){
		if(floorEnemy[i]->isFreeze()){continue;}
		if(floorEnemy[i]->is_dead()){ continue;}
		ER=floorEnemy[i]->getRow();
		EC=floorEnemy[i]->getCol();
		int PR=p->getR();
		int PC=p->getC();
		if(NextTo(ER,EC,PR,PC,1)){
			action=action+floorEnemy[i]->attack(*p);
		}else if(random&&NextTo(ER,EC,PR,PC,20)){
			if(!(check(ER+1,EC)=='.'|| check(ER-1,EC)=='.'||  check(ER,EC+1)=='.' || check(ER,EC-1)=='.')) continue;
			int move;
			count=0;
			int dr=absl(ER-PR);
			int dc=absl(EC-PC);
			while(true){
				count++;
				ER=floorEnemy[i]->getRow();
				EC=floorEnemy[i]->getCol();
				move=generate_int(0,3);
				if(move==0) ER++;
				else if(move==1) ER--;
				else if(move==2) EC++;
				else EC--;
				if((check(ER,EC)=='.'&&(absl(ER-PR)<dr||absl(EC-PC)<dc))||(check(ER,EC)=='.'&&count>10)){
					notify(floorEnemy[i]->getRow(),floorEnemy[i]->getCol(),ER,EC);
					floorEnemy[i]->setCoords(ER, EC);
					break;
				}
			}
		
		}else{
			if(check(ER+1,EC)=='.'|| check(ER-1,EC)=='.'||  check(ER,EC+1)=='.' || check(ER,EC-1)=='.'){
				int move;
				while(true){
					ER=floorEnemy[i]->getRow();
					EC=floorEnemy[i]->getCol();
					move=generate_int(0,3);
					if(move==0) ER++;
					else if(move==1) ER--;
					else if(move==2) EC++;
					else EC--;
					if(check(ER,EC)=='.'){
						notify(floorEnemy[i]->getRow(),floorEnemy[i]->getCol(),ER,EC);
						floorEnemy[i]->setCoords(ER, EC);
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < numTreasure; i++){
		if(floorTreasure[i]->getName() == "dragon hoard"){
			ER=floorTreasure[i]->getRow();
			EC=floorTreasure[i]->getCol();
			if(NextTo(ER,EC,PR,PC,1)){
				if(floorTreasure[i]->getDragon()->getIsHostile() == false){
					floorTreasure[i]->getDragon()->changeIsHostile();
				}
			} else {
				if(floorTreasure[i]->getDragon()->getIsHostile() == true){
					floorTreasure[i]->getDragon()->changeIsHostile();
				}
			}
		}
	}

	for(int i=0;i<numdragon;i++) {
		if(dragon[i]->isFreeze()){continue;}
		if(dragon[i]->is_dead()){ continue;}
		ER=dragon[i]->getRow();
		EC=dragon[i]->getCol();
		int PR=p->getR();
		int PC=p->getC();
		if(NextTo(ER,EC,PR,PC,1)&&dragon[i]->getIsHostile()==true){
			action=action+dragon[i]->attack(*p);
		}/*else if(dragon[i]->getIsHostile()==true&&NextTo(ER,EC,PR,PC,50)){
			if(!(check(ER+1,EC)=='.'|| check(ER-1,EC)=='.'||  check(ER,EC+1)=='.' || check(ER,EC-1)=='.')) continue;
			int move;
			count=0;
			int dr=absl(ER-PR);
			int dc=absl(EC-PC);
			while(true){
				count++;
				ER=dragon[i]->getRow();
				EC=dragon[i]->getCol();
				move=generate_int(0,3);
				if(move==0) ER++;
				else if(move==1) ER--;
				else if(move==2) EC++;
				else EC--;
				if((check(ER,EC)=='.'&&(absl(ER-PR)<dr||absl(EC-PC)<dc))||(check(ER,EC)=='.'&&count>10)){
					notify(dragon[i]->getRow(),dragon[i]->getCol(),ER,EC);
					dragon[i]->setCoords(ER, EC);
					break;
				}
			}
		
		}*//* else {
			if(check(ER+1,EC)=='.'|| check(ER-1,EC)=='.'||  check(ER,EC+1)=='.' || check(ER,EC-1)=='.'){
				int move;
				while(true){
					ER=dragon[i]->getRow();
					EC=dragon[i]->getCol();
					move=generate_int(0,3);
					if(move==0) ER++;
					else if(move==1) ER--;
					else if(move==2) EC++;
					else EC--;
					if(check(ER,EC)=='.'){
						notify(dragon[i]->getRow(),dragon[i]->getCol(),ER,EC);
						dragon[i]->setCoords(ER, EC);
						break;
					}
				}
			}
		}*/
	}

	if(random){
	ER=B->getRow();
	EC=B->getCol();
	if(B->is_dead()){
		theWorld[ER][EC].setStruct('/');
		action=action+B->getName()+" is dead, the stair to the upper floor reveals";
		return action;
	}else if(NextTo(ER,EC,PR,PC,2)){
		action=action+B->attack(*p);
	}else if(random&&NextTo(ER,EC,PR,PC,30)){
			if(!(check(ER+1,EC)=='.'|| check(ER-1,EC)=='.'||  check(ER,EC+1)=='.' || check(ER,EC-1)=='.')) return action;
			int move;
			count=0;
			int dr=absl(ER-PR);
			int dc=absl(EC-PC);
			while(true){
				count++;
				ER=B->getRow();
				EC=B->getCol();
				move=generate_int(0,3);
				if(move==0) ER++;
				else if(move==1) ER--;
				else if(move==2) EC++;
				else EC--;
				if((check(ER,EC)=='.'&&(absl(ER-PR)<dr||absl(EC-PC)<dc))||(check(ER,EC)=='.'&&count>10)){
					notify(B->getRow(),B->getCol(),ER,EC);
					B->setCoords(ER, EC);
					break;
				}
			}
		}
		}
	return action;
}

floor::~floor(){
	for (int i=0; i<numEnemy; i ++)
	{
		delete floorEnemy[i];
	}
	for (int i=0; i<numItem; i ++)
	{
		delete floorItem[i];
	}
	for (int i=0; i<numTreasure; i ++)
	{
		delete floorTreasure[i];
	}
	for (int i=0; i<numdragon; i ++)
	{
		delete dragon[i];
	}
	for (int i=0; i<25; i ++)
	{
		delete [] theWorld[i];
	}
	delete [] theWorld;
	for (int i=0; i<5; i ++)
	{
		delete merchantGoods[i];
	}

}








