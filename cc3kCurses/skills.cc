#include"skills.h"
#include"player.h"
#include"helper.h"
#include<string>
#include<iostream>
#include<stdio.h>
#include<ncurses.h>
using namespace std;
BloodFury::BloodFury(){
	name="BloodFury";
	description="Orcs can fly int a rage that incrase attck power for a short time, 20 roounds to cooldown";
	cooldown=0;
	cooldownRate=20;
}

string BloodFury::use(player& p){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";	
	p.setBonus(p.getAtk()/3);
	p.changeAtk(p.getAtk()/3);
	p.setBonusTime(10);
	cooldown=cooldownRate;
	return "BloodyFury!!";
}


ShadowMeld:: ShadowMeld(){
	name="ShadowMeld";
	description="The nimble elves can completely avoid being hit by attacks in a short time, 12 roounds to cooldown";
	cooldown=0;
	cooldownRate=12;
}

string ShadowMeld::use(player& p){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	p.setBonus(100);
	p.changeDodge(100);
	p.setBonusTime(4);
	cooldown=cooldownRate;
	return "ShadowMeld!!";
}


StoneForm::StoneForm(){
	name="StoneForm";
	description="Dwarves can temporarily turn to living stone, doubles their armor, 15 rounds to cooldown";
	cooldown=0;
	cooldownRate=15;
}

string StoneForm::use(player& p){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	p.setBonus(p.getDef());
	p.changeDef(p.getDef());
	p.setBonusTime(5);
	cooldown=cooldownRate;
	return "StoneForm!!";
}


HumanSpirit::HumanSpirit(){
	name="HumanSpirit";
	description="Human's spriit let them heal themselves, 15 rounds to cooldown";
	cooldown=0;
	cooldownRate=15;
}

string HumanSpirit::use(player& p){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	p.changeHP(p.getHP()/5);
	cooldown=cooldownRate;
	return "HumanSpirit!!";
}

Whirlwind::Whirlwind(){
	name="Whirlwind";
	description="In a whirlwind of steel you attack all enemies within 8 yards,10 rounds to cooldown";
	cooldownRate=10;
	cooldown=0;
}

string Whirlwind::use(player& p,floor& f){
	if(cooldown>0){
	string action=IntToString(cooldown)+ " turns to Cool Down";
	return action;
	}
	cooldown=cooldownRate;
	string action="PC uses Whirlwind\n";
	int pr=p.getR();
	int pc=p.getC();
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					int dmg=generate_int(70,150)*p.getAtk()/100;
					f.getObj(pr+i,pc+j)->damage(dmg);
					action=action+"Whirlwindw deals "+IntToString(dmg)+" to "+f.getObj(pr+i,pc+j)->getName()+"\n";
					if(f.getObj(pr+i,pc+j)->is_dead()){
					int gold=f.getObj(pr+i,pc+j)->getTreasure();
					int exp=f.getObj(pr+i,pc+j)->getExp();
					p.incGold(gold);
					p.incExp(exp);
					action=action+" you kills "+f.getObj(pr+i,pc+j)->getName();
					action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
		f.resetCell(pr+i,pc+j);
	}
				}
			}
		}
	}
	return action;
}

DemoralizingShout::DemoralizingShout(){
	name="Demoralizing Shout";
	description="Demoralizes all enemies within 2 blocks, reducing the their attact damage";
	cooldownRate=15;
	cooldown=0;
}

std::string DemoralizingShout:: use(player&p,floor&f){
	if(cooldown>0){
	string action=IntToString(cooldown)+ " turns to Cool Down";
	return action;
	}
	cooldown=cooldownRate;
	string action="PC uses Demoralizing Shout\n";
	int pr=p.getR();
	int pc=p.getC();
	for(int i=-2;i<=2;i++){
		for(int j=-2;j<=2;j++){
			if(pr+i>=0&&pr+i<=24&&pc+j>=0&&pc+j<=79){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					int ld=20;
					f.getObj(pr+i,pc+j)->changeAtk(-20);
					action=action+"Demoralizing Shout decrease 20 attack from "+f.getObj(pr+i,pc+j)->getName()+"\n";
					if(f.getObj(pr+i,pc+j)->is_dead()){
						int gold=f.getObj(pr+i,pc+j)->getTreasure();
						int exp=f.getObj(pr+i,pc+j)->getExp();
						p.incGold(gold);
						p.incExp(exp);
						action=action+" you kills "+f.getObj(pr+i,pc+j)->getName();
						action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp); 
		f.resetCell(pr+i,pc+j);
	}
				}
			}
			}
		}
	}
	return action;
}


FrostNova::FrostNova(){
	name="Frost Nova";
	description="Blasts enemies within 2 blocks of the caster for X Frost damage and freezes them in place for up to 2-5 turns ";
	cooldownRate=15;
	cooldown=0;
	MP=20;
}
std::string FrostNova:: use(player&p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	string action;
	if(p.getClass()->comsumeMP(MP)){
	cooldown=cooldownRate;
	action="PC uses Frost Nova\n";
	int pr=p.getR();
	int pc=p.getC();
	for(int i=-2;i<=2;i++){
		for(int j=-2;j<=2;j++){
			if(pr+i>=0&&pr+i<=24&&pc+j>=0&&pc+j<=79){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					int dmg=generate_int(40,70)*p.getAtk()/100;	
					int randn=generate_int(0,10);
					int fz=0;
					if(randn<=3) fz=2;
					else if(randn<=6) fz=3;
					else if(randn<=8) fz=4;
					else if(randn<=9) fz=5;
					else fz=6;		
					f.getObj(pr+i,pc+j)->setFreeze(fz);
					fz--;
					f.getObj(pr+i,pc+j)->damage(dmg);
					action=action+"Frost Nova deals "+IntToString(dmg)+" damage and freezes "+IntToString(fz)+" turns to "+f.getObj(pr+i,pc+j)->getName()+"\n";
					if(f.getObj(pr+i,pc+j)->is_dead()){
					int gold=f.getObj(pr+i,pc+j)->getTreasure();
					int exp=f.getObj(pr+i,pc+j)->getExp();
					p.incGold(gold);
					p.incExp(exp);
					action=action+" you kills "+f.getObj(pr+i,pc+j)->getName();
					action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
					f.resetCell(pr+i,pc+j);
	}
				}
			}
			}
		}
	}
	}else{action="No Mana";}
	return action;
}

SpiritualHealing:: SpiritualHealing(){
	name="Spiritual Healing";
	description="Heals yourself. amount is based on your Atk and Def";
	cooldownRate=15;
	cooldown=0;
}

string SpiritualHealing::use(player& p,floor&f){
	if(cooldown>0){
	 return IntToString(cooldown)+ " turns to Cool Down";
	 }	
	int healing=generate_int(4,8)*(p.getAtk()+p.getDef())/10;
	p.changeHP(healing);
	cooldown=cooldownRate;
	string action="PC uses Spiritual Healing, HP increases "+IntToString(healing);
	return  action;
}

Slam:: Slam(){
	name="Slam";
	description="Slams the opponent, deals huge damage, ignore the defence";
	cooldownRate=15;
	cooldown=0;
}


string Slam::use(player& p,floor&f){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	printw("select direction(w,a,s,d) :\n");
	char dir=' ';
	cooldown=cooldownRate;
	while(!(dir=='w'||dir=='s'||dir=='a'||dir=='d')){
		dir=getch();
	}
	string action="";
	int pr=p.getR();
	int pc=p.getC();
	if(dir=='s') pr=pr+1;
	else if(dir=='w') pr=pr-1;
	else if(dir=='d') pc=pc+1;
	else pc=pc-1;
	if(f.getObj(pr,pc)!=NULL&&f.getObj(pr,pc)->getType()=='e'){
		int dmg=generate_int(200,250)*p.getAtk()/100;
		f.getObj(pr,pc)->damage(dmg);
		action=action+" PC SLAMS "+f.getObj(pr,pc)->getName()+" and deals "+IntToString(dmg)+" damage. ";
		if(f.getObj(pr,pc)->is_dead()){
			int gold=f.getObj(pr,pc)->getTreasure();
			int exp=f.getObj(pr,pc)->getExp();
			p.incGold(gold);
			p.incExp(exp);
			action=action+" you kills "+f.getObj(pr,pc)->getName();
			action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
			f.resetCell(pr,pc);
		}		
	}else{
		action="cannot find enemy";
	}
	return action;
}



FireBlast:: FireBlast(){
	name="Fire Blast";
	description="Blasts the enemy for fire damage. Hit the enemy in front up to 5 blocks away, coolDown every 3 turns";
	cooldownRate=3;
	cooldown=0;
	MP=10;
}

string FireBlast::use(player& p,floor&f){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	string action;
	if(p.getClass()->comsumeMP(MP)){
	printw("select direction(w,a,s,d) : \n");
	char dir=' ';
	cooldown=cooldownRate;
	while(!(dir=='w'||dir=='s'||dir=='a'||dir=='d')){
		dir=getch();
	}
	action="";
	int pr=p.getR();
	int pc=p.getC();
	int r=0;
	int c=0;
	if(dir=='s') r=1;
	else if(dir=='w') r=-1;
	else if(dir=='d') c=1;
	else c=-1;
	pr=pr+r;
	pc=pc+c;
	int count=1;
	while(f.getObj(pr,pc)==NULL&&count<=5){
		if(pr+r>=0&&pr+r<=24) pr=pr+r;
		if(pc+c>=0&&pc+c<=79) pc=pc+c;
		count++;
	}
	if(count>5){
		action="No enemy in front, fire blast misses";
	}else{
	if((f.getObj(pr,pc))->getType()!='e'){
		action=f.getObj(pr,pc)->getName()+" is in front of you, fire blast does no effect";
	}else if((f.getObj(pr,pc))->getType()=='e'){
		int dmg=generate_int(100,150)*p.getAtk()/(100+(f.getObj(pr,pc)->getDef())/2);
		f.getObj(pr,pc)->damage(dmg);
		action=action+"FireBlast hits "+f.getObj(pr,pc)->getName()+" and deals "+IntToString(dmg)+" damage. ";
		}
	if(f.getObj(pr,pc)->is_dead()){
		int gold=f.getObj(pr,pc)->getTreasure();
		int exp=f.getObj(pr,pc)->getExp();
		p.incGold(gold);
		p.incExp(exp);
		action=action+" you kills "+f.getObj(pr,pc)->getName();
		action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
		f.resetCell(pr,pc);
		}
	}
	}else{action="No Mana";}
	return action;
}

BloodMagic:: BloodMagic(){
	name="Blood Magic";
	description="deals damage to enemies up to 3 blocks aways and recover HP, coolDown 20 comsume 50MP";
	cooldownRate=20;
	cooldown=0;
	MP=50;
}

std::string BloodMagic:: use(player&p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	string action;
	if(p.getClass()->comsumeMP(MP)){
	cooldown=cooldownRate;
	action="PC uses BloodMagic\n";
	int pr=p.getR();
	int pc=p.getC();
	int dmg;
	int lust=0;
	for(int i=-3;i<=3;i++){
		for(int j=-3;j<=3;j++){
			if(pr+i>=0&&pr+i<=24&&pc+j>=0&&pc+j<=79){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					dmg=generate_int(40,60)*p.getAtk()/100;
					lust=lust+dmg/2;
					f.getObj(pr+i,pc+j)->damage(dmg);
					action=action+"Blood Magic deals "+IntToString(dmg)+" damage to "+f.getObj(pr+i,pc+j)->getName()+"\n";
					if(f.getObj(pr+i,pc+j)->is_dead()){
					int gold=f.getObj(pr+i,pc+j)->getTreasure();
					int exp=f.getObj(pr+i,pc+j)->getExp();
					p.incGold(gold);
					p.incExp(exp);
					action=action+" you kills "+f.getObj(pr+i,pc+j)->getName();
					action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
					f.resetCell(pr+i,pc+j);
					}
				}
			}
			}
		}
	}
	action=action+"you recover "+IntToString(lust)+" HP\n";
	p.changeHP(lust);
	}else{action="No Mana";}
	return action;
}
Vitality:: Vitality(){
	name="Vitality";
	description="hugely increase HP and slightly increase Atk and Def";
	cooldownRate=20;
	cooldown=0;
	MP=50;
}
std::string Vitality:: use(player& p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	if(p.getClass()->comsumeMP(MP)){
		int healing=generate_int(10,20)*(p.getAtk()+p.getDef())/10+ 100;
		cooldown=cooldownRate;
		p.changeHP(healing);
		p.changeAtk(5);
		p.changeDef(5);
		return "PC increase" +IntToString(healing)+"HP, 5 Atk and 5 Def";
	}else{
		return "No Mana";
	}
}


WoundingArrow:: WoundingArrow(){
	name="WoundingArrow";
	description="hit an enemy in front up to 10 blocks";
	cooldownRate=3;
	cooldown=0;
}

string WoundingArrow::use(player& p,floor&f){
	if(cooldown>0) return IntToString(cooldown)+ " turns to Cool Down";
	string action;
	printw("select direction(w,a,s,d)\n");
	char dir;
	cooldown=cooldownRate;
	while(!(dir=='w'||dir=='s'||dir=='a'||dir=='d')){
		dir=getch();
	}
	action="";
	int pr=p.getR();
	int pc=p.getC();
	int r=0;
	int c=0;
	if(dir=='s') r=1;
	else if(dir=='w') r=-1;
	else if(dir=='d') c=1;
	else c=-1;
	pr=pr+r;
	pc=pc+c;
	int count=1;
	while(f.getObj(pr,pc)==NULL&&count<=10){
		if(pr+r>=0&&pr+r<=24) pr=pr+r;
		if(pc+c>=0&&pc+c<=79) pc=pc+c;
		count++;
	}
	if(count>10){
		action="No enemy in front, arrow misses";
	}else{
	if((f.getObj(pr,pc))->getType()!='e'){
		action=f.getObj(pr,pc)->getName()+" is in front of you, cannot attack";
	}else if((f.getObj(pr,pc))->getType()=='e'){
		int dmg=generate_int(110,130)*p.getAtk()/(100+(f.getObj(pr,pc)->getDef()));
		f.getObj(pr,pc)->damage(dmg);
		action=action+"Wounding Arrow hits "+f.getObj(pr,pc)->getName()+" and deals "+IntToString(dmg)+" damage. ";
		}
	if(f.getObj(pr,pc)->is_dead()){
		int gold=f.getObj(pr,pc)->getTreasure();
		int exp=f.getObj(pr,pc)->getExp();
		p.incGold(gold);
		p.incExp(exp);
		action=action+" you kills "+f.getObj(pr,pc)->getName();
		action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
		f.resetCell(pr,pc);
		}
	}
	return action;
}

Flatten:: Flatten(){
	name="Flatten";
	description="Pound the ground, deals damage and stunning targets within one block at least 3 turns.";
	cooldownRate=15;
	cooldown=0;
}


std::string Flatten:: use(player&p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	string action;
	cooldown=cooldownRate;
	action="PC uses Flatten\n";
	int pr=p.getR();
	int pc=p.getC();
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(pr+i>=0&&pr+i<=24&&pc+j>=0&&pc+j<=79){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					int dmg=generate_int(120,150)*p.getAtk()/(100+f.getObj(pr+i,pc+j)->getDef());	
					int randn=generate_int(0,10);
					int fz=0;
					if(randn<=4) fz=4;
					else if(randn<=9) fz=5;
					else fz=6;		
					f.getObj(pr+i,pc+j)->setFreeze(fz);
					fz--;
					f.getObj(pr+i,pc+j)->damage(dmg);
					action=action+"Flatten deals "+IntToString(dmg)+" damage and stuns "+IntToString(fz)+" turns to "+f.getObj(pr+i,pc+j)->getName()+"\n";
					if(f.getObj(pr+i,pc+j)->is_dead()){
					int gold=f.getObj(pr+i,pc+j)->getTreasure();
					int exp=f.getObj(pr+i,pc+j)->getExp();
					p.incGold(gold);
					p.incExp(exp);
					action=action+" you kills "+f.getObj(pr+i,pc+j)->getName();
					action=action+" you get Gold"+ IntToString(gold)+" and EXP "+ IntToString(exp)+"\n"; 
					f.resetCell(pr+i,pc+j);
	}
				}
			}
			}
		}
	}
	return action;
}

DeathCurse:: DeathCurse(){
	name="Death Curse";
	description="curse the enemies 3 blocks around, weakenning their Atk and Def,cooldown every 20 turns";
	cooldownRate=20;
	cooldown=0;
}

std::string DeathCurse:: use(player&p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	string action;
	cooldown=cooldownRate;
	action="PC uses Frost Nova\n";
	int pr=p.getR();
	int pc=p.getC();
	for(int i=-2;i<=2;i++){
		for(int j=-2;j<=2;j++){
			if(pr+i>=0&&pr+i<=24&&pc+j>=0&&pc+j<=79){
			if((i!=0||j!=0)&&f.getObj(pr+i,pc+j)!=NULL){
				if(f.getObj(pr+i,pc+j)->getType()=='e'){
					f.getObj(pr+i,pc+j)->changeAtk(-f.getObj(pr+i,pc+j)->getAtk()/2);
					f.getObj(pr+i,pc+j)->changeDef(-f.getObj(pr+i,pc+j)->getDef()/2);
					action=action+"PC weakens"+f.getObj(pr+i,pc+j)->getName()+"\n";

				}
			}
			}
		}
	}
	return action;
}

Blessing:: Blessing(){
	name="Blessing";
	description="hugely increase HP and slightly increase Atk and Def";
	cooldownRate=25;
	cooldown=0;
}

std::string Blessing:: use(player& p,floor&f){
	if(cooldown>0){return IntToString(cooldown)+ " turns to Cool Down";}
	int healing=generate_int(15,30)*(p.getHP())/100+100;
		cooldown=cooldownRate;
		p.changeHP(healing);
		p.changeAtk(3);
		p.changeDef(3);
		return "PC increase "+IntToString(healing) +"HP, 3 Atk and 3 Def";
}

