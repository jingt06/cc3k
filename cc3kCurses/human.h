#ifndef __HUMAN_H__
#define __HUMAN_H__
#include<string>
#include"skill.h"
#include"skills.h"
#include"race.h"
class human:public race{
	public:
	std::string getName();
	human(char*** map=NULL);
	~human();
	void setBonus(int n);
	void setBonusTime(int n);
	void coolDown();
	std::string useRaceSkill();
	void printScore();
};

#endif
