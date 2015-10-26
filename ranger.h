#ifndef __RANGER_H__
#define __RANGER_H__
#include "uclass.h"
#include "classes.h"
class Ranger:public ultimateClass{
	public:
	Ranger(classes* c);
	std::string getName();
};

#endif
