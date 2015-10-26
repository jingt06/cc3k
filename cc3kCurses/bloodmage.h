#ifndef __BLOODMAGE_H__
#define __BLOODMAGE_H__
#include "uclass.h"
#include "classes.h"
class bloodMage:public ultimateClass{
	public:
	bloodMage(classes* c);
	std::string getName();
	bool comsumeMP(int n);
	int getMP();
};

#endif
