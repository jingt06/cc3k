#ifndef __PALADIN_H__
#define __PALADIN_H__
#include "uclass.h"
#include "classes.h"
class Paladin:public ultimateClass{
	public:
	Paladin(classes* c);
	std::string getName();
};

#endif
