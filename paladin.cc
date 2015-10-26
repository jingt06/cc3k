#include"paladin.h"
#include"skills.h"

Paladin::Paladin(classes* c):ultimateClass(false,c){
	uskill=new Blessing();
}


std::string  Paladin::getName(){
	return "Paladin";
}
