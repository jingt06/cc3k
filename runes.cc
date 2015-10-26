#include "runes.h"
#include <string>


StrengthRune::StrengthRune(){}
std::string StrengthRune::getName(){
	return "Strength Rune (slightly increase ATK)";
}
void StrengthRune::UseRune(player& p){
	p.changeAtk(10);
}
void StrengthRune::DropRune(player& p){
	p.changeAtk(-10);
}

QuicknessRune::QuicknessRune(){}
std::string QuicknessRune::getName(){
	return "Quickness Rune (slightly increase Dodge Rage";
}
void QuicknessRune::UseRune(player& p){
	p.changeDodge(5);
}
void QuicknessRune::DropRune(player& p){
	p.changeDodge(-5);
}

HardnessRune::HardnessRune(){}
std::string HardnessRune::getName(){
	return "Hardness Rune (slightly increase DEF)";
}
void HardnessRune::UseRune(player& p){
	p.changeDef(10);
}
void HardnessRune::DropRune(player& p){
	p.changeDef(-10);
}

HealthRune::HealthRune(){}
std::string HealthRune::getName(){
	return "Health Rune (slightly increase HP)";
}
void HealthRune::UseRune(player& p){
	p.changeHP(200);
}
void HealthRune::DropRune(player& p){
	p.changeHP(-200);
}

PowerRune::PowerRune(){}
std::string PowerRune::getName(){
	return "Power Rune (slightly increase ATK/DEF/DodgeRates)";
}
void PowerRune::UseRune(player& p){
	p.changeDodge(2);
	p.changeAtk(7);
	p.changeDef(7);
}
void PowerRune::DropRune(player& p){
	p.changeDodge(-2);
	p.changeAtk(-7);
	p.changeDef(-7);
}

GodRune::GodRune(){}
std::string GodRune::getName(){
	return "God Rune (increase ATK/DEF/DodgeRates)";
}
void GodRune::UseRune(player& p){
	p.changeDodge(5);
	p.changeAtk(12);
	p.changeDef(12);
}
void GodRune::DropRune(player& p){
	p.changeDodge(-5);
	p.changeAtk(-12);
	p.changeDef(-12);
}



