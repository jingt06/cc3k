#ifndef __SPIRITHEALER_H__
#define __SPIRITHEALER_H__
#include "uclass.h"
#include "classes.h"
class spiritHealer:public ultimateClass{
	public:
	spiritHealer(classes* c);
	std::string getName();
	bool comsumeMP(int n);
	int getMP();
};

#endif
