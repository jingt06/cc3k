#include"mage.h"
#include<string>
using namespace std;
mage::mage():classes(true),MP(100){
	classSkill1=new FrostNova();
	classSkill2=new FireBlast();
}
std::string mage::getName(){
	return "Mage";
}
bool mage:: comsumeMP(int n){
	if(MP>=n){
		MP=MP-n;
		return true;
	}
	else return false;
}
void mage:: coolDown(){
	if(classSkill1!=NULL){
		classSkill1->coolDown();
	}
	if(classSkill2!=NULL){
		classSkill2->coolDown();
	}
	if(MP<100) MP++;
}

int mage:: getMP(){
	return MP;
}

void mage:: evolve(player& p){
	p.evolve(*this);
}
