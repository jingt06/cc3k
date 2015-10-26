#ifndef __ORC_H__
#define __ORC_H__
#include<string>
#include"skill.h"
#include"skills.h"
#include"race.h"
class orc:public race{
	public:
	int fury;
	int bonusAtk;
	std::string getName();
	std::string useRaceSkill();
	void coolDown();
	void setBonus(int n);
	void setBonusTime(int n);
	orc(char*** map=NULL);
	void printScore();
	void buyItem();
	float getGold();
	~orc();
};
#endif
