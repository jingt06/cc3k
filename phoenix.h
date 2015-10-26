#ifndef __PHOENIX_H__
#define __PHOENIX_H__
#include "enemy.h"

class Phoenix: public Enemy {
	public:
		Phoenix(int n);
		 std::string getName();
		const char getChar();
		std::string attack(player &p);
		~Phoenix();
};
#endif
