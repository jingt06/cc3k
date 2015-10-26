#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "object.h"
#include "player.h"

class player;
class Treasure;
class Enemy: public Object{
protected:
	int HP, Atk, Def,Gold,Exp,freeze;
public:
	Enemy(int HP = 0, int Atk = 0, int Def = 0,int Gold=0,int Exp=0);
	int getHP();
	int getAtk();
	int getDef();
	int getTreasure();
	int getExp();
	virtual std::string attack(player &p);
	void changeDef(int n);
	void changeAtk(int n);
	void damage(int amount);
	bool is_dead();
	const char getType();
	virtual void setFreeze(int n);
	bool isFreeze();
	virtual bool getIsHostile();
	virtual void changeIsHostile();
	virtual ~Enemy();
};

#endif
