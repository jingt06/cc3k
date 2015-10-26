#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include "classes.h"
#include "race.h"
class warrior:public classes{
	protected:
	public:
	warrior();
	std::string getName();
	void evolve(player& p);
};


#endif
