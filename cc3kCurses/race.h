#ifndef __RACE_H__
#define __RACE_H__
#include<string>
#include"skill.h"
#include"skills.h"
#include"player.h"
class skill;
class race:public player{
	protected:
	skill* RaceSkill;
	public:
	race(char*** map=NULL);
	skill* getskill();
	void useSkill(int r,int c);
	virtual ~race();
};





#endif
