#include"classes.h"
#include "skill.h"
using namespace std;
classes:: classes(bool magic):magic(magic),classSkill1(NULL),classSkill2(NULL){}
bool classes::isMagic(){	return magic;}
classes::~classes(){
	delete classSkill1;
	delete classSkill2;
}
int classes:: getMP(){ return 0;}
bool classes:: comsumeMP(int n){ return false;}
void classes:: coolDown(){
	if(classSkill1!=NULL){
		classSkill1->coolDown();
	}
	if(classSkill2!=NULL){
		classSkill2->coolDown();
	}
}

bool classes:: advance(){
	return false;
}
skill* classes::getuskill(){
	return NULL;
}
skill* classes:: getcs1(){
	return classSkill1;
}
skill* classes::getcs2(){
	return classSkill2;
}

void classes::evolve(player& p){}
