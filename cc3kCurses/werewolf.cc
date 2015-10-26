#include "werewolf.h"

Werewolf::Werewolf(int n): Enemy(120,30+20*n,5+5*n,1+5*n,3+5*n) {}

const char Werewolf::getChar(){
	return 'w';
}
 std::string Werewolf:: getName(){
	return "Werewolf";
}

Werewolf::~Werewolf(){}
