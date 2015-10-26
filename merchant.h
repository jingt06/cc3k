#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"
#include <string>

class Merchant: public Enemy {
	public:
		static bool hostile;
		Merchant(int n);
		 std::string getName();
		const char getChar();
		std::string attack(player &p);
		~Merchant();
};
#endif
