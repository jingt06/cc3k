#ifndef __CLASSES_H__
#define __CLASSES_H__
#include "player.h"
#include "skill.h"
class player;
class skill;
class classes{
	protected:
	bool magic;
	skill* classSkill1;
	skill* classSkill2;
	public:
	virtual bool advance();
	virtual void coolDown();
	virtual skill* getcs1();
	virtual skill* getcs2();
	virtual skill* getuskill();
	classes(bool magic);
	bool isMagic();
	virtual std::string getName()=0;
	virtual int getMP();
	virtual bool comsumeMP(int n);
	virtual void evolve(player& p);
	virtual ~classes();
};

#endif
