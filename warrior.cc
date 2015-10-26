#include"warrior.h"
#include<string>
warrior::warrior():classes(false){
	classSkill1=new Whirlwind();
	classSkill2=new DemoralizingShout();
}
std::string warrior::getName(){
	return "Warrior";
}
void warrior:: evolve(player& p){
	p.evolve(*this);
}
