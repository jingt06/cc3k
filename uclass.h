#ifndef __UCLASS_H__
#define __UCLASS_H__
#include "skill.h"
#include "classes.h"
class ultimateClass:public classes{
	public:
	classes* base;
	skill* uskill;
	public:
	ultimateClass(bool magic,classes* c);
	void coolDown();
	bool advance();
	skill* getuskill();
	skill* getcs1();
	skill* getcs2();
	bool isMagic();
	int getMP();
	bool comsumeMP(int n);
	~ultimateClass();
};



#endif
