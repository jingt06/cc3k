#include"ranger.h"
#include"skills.h"

Ranger::Ranger(classes* c):ultimateClass(false,c){
	uskill=new WoundingArrow();
}


std::string  Ranger::getName(){
	return "Ranger";
}
