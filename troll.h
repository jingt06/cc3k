#ifndef __TROLL_H__
#define __TROLL_H__
#include "enemy.h"
#include <iostream>

class Troll: public Enemy {
	public:
		Troll(int n);
		 std::string getName();
		const char getChar();
		std::string attack(player &p);
		~Troll();
};

#endif
