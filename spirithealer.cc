#include"spirithealer.h"
#include"skills.h"

spiritHealer::spiritHealer(classes* c):ultimateClass(true,c){
	uskill=new Vitality();
}
bool spiritHealer::comsumeMP(int n){
	return base->comsumeMP(n);
}

std::string  spiritHealer::getName(){
	return "Spirit Healer";
}

int spiritHealer:: getMP(){
	return base->getMP();
}
