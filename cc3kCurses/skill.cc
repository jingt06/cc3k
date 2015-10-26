#include<ncurses.h>
#include<iostream>
#include<string>
#include<cstring>
#include"player.h"
#include"skill.h"
using namespace std;

std::ostream &operator<<(std::ostream &out, const skill &s){
	char *name=new char[s.name.size()+1];
	name[s.name.size()]=0;
	strcpy(name,s.name.c_str());
	char *description=new char[s.description.size()+1];
	description[s.description.size()]=0;
	strcpy(description,s.description.c_str());
	printw("%s: %s",name,description);
	delete name;
	delete description;
	return out;
}
std::string skill:: use(player& p){
	return "";
}
string skill:: getname(){
	return name;
}
void skill:: coolDown(){
	if(cooldown>0)cooldown--;
}
std::string skill:: use(player& p,floor& f){
	return "";
}

std::string use(player& p){
	return "";
}
skill::skill():name(""),description(""),MP(0){};
