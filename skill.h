#ifndef __SKILL_H__
#define __SKILL_H__
#include<iostream>
#include<string>
#include"player.h"
#include"floor.h"
class floor;
class player;
class skill{
	protected:
	std::string name;
	std::string description;
	int cooldown;
	int cooldownRate;
	int MP;
	public:
	skill();
	void coolDown();
	virtual std::string use(player& p,floor& f);
	virtual std::string use(player& p);
	friend std::ostream &operator<<(std::ostream &out, const skill &s);
	std::string getname();
};
std::ostream &operator<<(std::ostream &out, const skill &s);

#endif
