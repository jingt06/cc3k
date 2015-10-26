#ifndef __BOSS_H__
#define __BOSS_H__
#include"enemy.h"
class Boss: public Enemy{
	protected:
	std::string name;
	public:
	static Boss bosses[7];
	Boss(int HP = 0, int Atk = 0, int Def = 0,int Gold=0,int Exp=0,std::string name="");
	void setFreeze(int n);
	std::string getName();
	const char getChar();
	std:: string attack(player &p);
};

#endif
