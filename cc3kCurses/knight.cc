#include"knight.h"
#include<string>
knight::knight():classes(false){
	classSkill1=new Slam();
	classSkill2=new SpiritualHealing();
	}
std::string knight::getName(){
	return "Knight";
}
void knight:: evolve(player& p){
	p.evolve(*this);
}
