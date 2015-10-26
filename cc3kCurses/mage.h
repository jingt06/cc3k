#ifndef __MAGE_H__
#define __MAGE_H__
#include "classes.h"
#include "race.h"
class mage:public classes{
	protected:
	int MP;
	public:
	mage();
	std::string getName();
	bool comsumeMP(int n);
	void coolDown();
	int getMP();
	void evolve(player& p);
};


#endif
