#include<string>
#include<iostream>
#include"skill.h"
#include"race.h"
using namespace std;


race:: race(char*** map):player(map),RaceSkill(NULL){}
void race:: useSkill(int r,int c){
	//s->useOn(r,c);
}


skill* race:: getskill(){
	return RaceSkill;
}


race::~race(){
	if(RaceSkill!=NULL) delete RaceSkill;
}
