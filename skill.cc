#include<string>
#include"player.h"
#include"skill.h"
using namespace std;

std::ostream &operator<<(std::ostream &out, const skill &s){
	out<<s.name<<": "<<s.description;
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
