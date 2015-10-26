#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include "enemy.h"

class Vampire: public Enemy {
	public:
		Vampire(int n);
		 std::string getName();
		const char getChar();
		std::string attack(player &p);
		~Vampire();
};
#endif
