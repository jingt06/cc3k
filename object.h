#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <string>
class player;
class Treasure;
class Object{
	int r, c;
public:
	Object();
	void setCoords(int r, int c);
	int getRow();
	int getCol();
	virtual const char getType() = 0;
	virtual std::string getName() = 0;
	virtual const char getChar() = 0;
	virtual ~Object();
	virtual int getHP();
	virtual int getAtk();
	virtual int getDef();
	virtual void changeAtk(int n);
	virtual void changeDef(int n);
	virtual int getTreasure();
	virtual void setDragonHoard(Treasure *t);
	virtual Treasure * getDragonHoard();
	virtual void attack(player *p);
	virtual void damage(int amount);
	virtual bool is_dead();
	virtual int getExp();
	virtual void setFreeze(int n);
	virtual bool isFreeze();
};

#endif
