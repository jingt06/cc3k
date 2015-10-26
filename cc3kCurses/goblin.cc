#include "goblin.h"
#include <string>
using namespace std;
Goblin::Goblin(int n): Enemy(70+15*n,5+3*n,10+5*n,1+1*n,3+3*n) {}

const char Goblin::getChar(){
	return 'g';
}

std::string Goblin:: getName(){
	return "Goblin";
}
Goblin::~Goblin(){}
