#include"bloodmage.h"
#include"skills.h"

bloodMage::bloodMage(classes* c):ultimateClass(true,c){
	uskill=new BloodMagic();
}

bool bloodMage::comsumeMP(int n){
	return base->comsumeMP(n);
}


std::string  bloodMage::getName(){
	return "BloodMage";
}
int bloodMage:: getMP(){
	return base->getMP();
}
