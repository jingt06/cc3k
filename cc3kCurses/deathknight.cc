#include"deathknight.h"
#include"skills.h"

DeathKnight::DeathKnight(classes* c):ultimateClass(false,c){
	uskill=new DeathCurse();
}


std::string  DeathKnight::getName(){
	return "Death Knight";
}
