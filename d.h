#ifndef __D_H__
#define __D_H__
#include <string>
#include "potion.h"
//class Potion;
class D: public Potion {
public:
	D();
	void setAmount(int i);
	std::string getName();
	void useItem(player *p);
	~D();
};
#endif