#ifndef __ELVES_H__
#define __ELVES_H__
#include<string>
#include"skill.h"
#include"skills.h"
#include"race.h"
class elves:public race{
	public:
	int quickness;
	int bonusDodge;
	std::string getName();
	elves(char*** map=NULL);
	~elves();
	void setBonus(int n);
	void setBonusTime(int n);
	void coolDown();
	std::string useRaceSkill();
	void printScore();
};

#endif
