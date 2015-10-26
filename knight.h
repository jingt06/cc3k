#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "classes.h"
#include "race.h"
class knight:public classes{
	protected:
	public:
	knight();
	std::string getName();
	void evolve(player& p);
};


#endif
