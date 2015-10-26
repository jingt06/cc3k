#ifndef __H_H__
#define __H_H__
#include <string>
#include "potion.h"
//class Potion;
class H: public Potion {
public:
	H();
	void setAmount(int i);
	std::string getName();
	void useItem(player *p);
	~H();
};
#endif