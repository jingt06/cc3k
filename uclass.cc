#include"uclass.h"
using namespace std;



ultimateClass::ultimateClass(bool magic,classes* c):classes(magic){
	base=c;
}
bool ultimateClass:: advance(){
	return true;
}
void ultimateClass:: coolDown(){
	uskill->coolDown();
	base->coolDown();
}
skill* ultimateClass::getcs1(){
	return base->getcs1();
}

skill* ultimateClass::getuskill(){
	return uskill;
}
skill* ultimateClass::getcs2(){
	return base->getcs2();
}
bool ultimateClass::isMagic(){
	return base->isMagic();
}
int ultimateClass::getMP(){
	return base->getMP();
}
bool ultimateClass::comsumeMP(int n){
	return base->comsumeMP(n);
}

ultimateClass::~ultimateClass(){
	delete uskill;
	if(base!=NULL) delete base;
}
