#ifndef __PLAYER_H__
#define __PLAYER_H__
#include<string>
#include"floor.h"
#include"item.h"
#include"skill.h"
#include"classes.h"
#include "treasure.h"///////
class classes;
class skill;
class floor;
class item;
class mage;
class knight;
class warrior;
class player{
	protected:
	int HP,MaxHP,MaxHPincRate,dodgeRate,Atk,Def,r,c,lv,exp,Gold,AtkRate,DefRate,numItem;//coordinates
	int current;//current floor
	classes * playerClass;
	floor* flr[7];
	Item* inventory[6];
	int amor;
	int weapon;
	bool moveAvailable,won;
	bool input;
	char*** map;
	
	public:
	bool isWon();
	static int TemAtk,TemDef;
	classes* getClass();
	player(char*** map=NULL);
	int getMP();
	bool isMagic();
	void incExp(int n);
	void incGold(int n);
	void levelup();
	bool setClass(std::string cs);
	std::string move(std::string dir);
	std::string attack(std::string dir);
	void listInventory();
	virtual skill* getskill();
	void useItem(int i);
	bool dropItem(int i);
	virtual std:: string useRaceSkill();
	//std::string useClassSkill(int r,int c);
	void reset();
	void changeAtk(int n);
	void changeDef(int n);
	void changeDodge(int n);
	void changeHP(int n);
	void changeGold(int n);
	void changeHPRate(int n);
	void setR(int n);
	void setC(int n);
	int getMaxHP();
	int getR();
	int getC();
	int getLv();
	int getDR();
	virtual float getGold();
	int getAtk();
	int getDef();
	int getHP();
	std::string EnemyTurn(std::string action);
	bool isDead();
	std::string useCSkill1();
	std::string useCSkill2();
	std::string useUSkill();
	virtual void buyItem();
	void sellItem();
	void listCSkill();
	int getnumItem();
	//void useCSkill2();
	virtual void setBonus(int n);
	virtual void setBonusTime(int n);
	virtual std::string getName()=0;
	virtual void coolDown();
	virtual void printScore();
	bool getItem(Item* it);
	void display(std::string action="");
	void evolve(mage& p);
	void evolve(warrior& p);
	void evolve(knight& p);
	virtual ~player();
};
#endif
