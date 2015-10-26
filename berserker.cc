#include"berserker.h"
#include"skills.h"

Berserker::Berserker(classes* c):ultimateClass(false,c){
	uskill=new Flatten();
}


std::string  Berserker::getName(){
	return "Berserker";
}
