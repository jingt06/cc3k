#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include "enemy.h"
#include <string>

class Goblin: public Enemy {
	public:
		Goblin(int n);
		std::string getName();
		const char getChar();
		~Goblin();
};

#endif
