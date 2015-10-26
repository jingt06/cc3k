#ifndef __DWARF_H__
#define __DWARF_H__
#include<string>
#include"skill.h"
#include"skills.h"
#include"race.h"
class dwarf:public race{
	public:
	int stone;
	int bonusDef;
	std::string getName();
	dwarf(char*** map=NULL);
	~dwarf();
	void setBonus(int n);
	void setBonusTime(int n);
	void coolDown();
	std::string useRaceSkill();
	void printScore();
	void buyItem();
	float getGold();
};
#endif
