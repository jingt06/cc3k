#ifndef __A_H__
#define __A_H__
#include <string>
#include "potion.h"
//class Potion;
class A: public Potion {
public:
	A();
	void setAmount(int i);
	std::string getName();
	void useItem(player *p);
	~A();
};
#endif