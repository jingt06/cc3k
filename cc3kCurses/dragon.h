#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"

class Dragon: public Enemy {
	Treasure *t;
	bool isHostile;
	public:
		Dragon(int n);
		std::string getName();
		const char getChar();
		void setDragonHoard(Treasure *t);
		Treasure * getDragonHoard();
		bool getIsHostile();
		void changeIsHostile();
		~Dragon();
};
#endif
