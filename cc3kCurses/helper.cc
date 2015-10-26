#include<stdlib.h>  
#include<sstream>
#include<time.h> 
#include<string>
#include<iostream>
#include<fstream>
#include"helper.h"
#include"player.h"
#include"race.h"
#include"human.h"
#include"orc.h"
#include"elves.h"
#include"dwarf.h"
using namespace std;
bool setRace(player**p,string rc,bool input,char*** maps){
	if(rc=="h"){
		if(input) *p=new human(maps);
		else *p=new human();
		return true;
	}else if(rc=="e"){
		if(input) *p=new elves(maps);
		else *p=new elves();
		return true;
	}else if(rc=="d"){
		if(input) *p=new dwarf(maps);
		else *p=new dwarf();
		return true;
	}else if(rc=="o"){
		if(input) *p=new orc(maps);
		else *p=new orc();
		return true;
	}
	return false;
}

int generate_int(int lower,int upper){
	return rand()%(upper-lower+1)+lower;
}


string IntToString(int n){
	stringstream ss;
	ss<<n;
	string str=ss.str();
	return str;
}

int absl(int n){
	if(n<0) n=-n;
	return n;
}

int NextTo(int a1,int b1,int a2,int b2){
	if(a1==a2&&absl(b1-b2)==1){
		return true;
	}else if(b1==b2&&absl(a1-a2)==1){
		return true;
	}
	return false;
}

int NextTo(int a1,int b1,int a2,int b2,int d){
	if(absl(a1-a2)<=d&&absl(b1-b2)<=d){
		return true;
	}
	return false;
}

char*** readfile(string f){
	char*** map=new char**[7];
	for (int i=0; i<7; i ++){
		map[i]=new char*[25];
		for (int j=0; j<25; j ++){
			map[i][j]=new char[79];
		}
	}
	ifstream maps(f.c_str());
	string line;
	char cell;
	for (int k=0; k<7; k ++)
	{
	for (int i=0; i<25; i++){
		for (int j=0; j<79; j++){
			map[k][i][j]=' ';
		}
	}
	}
	for (int k=0; k<7; k ++)
	{
	for (int i=0; i<25; i++){
		getline(maps,line);
		for (int j=0; j<79; j++){
			map[k][i][j]=line[j];	
		}
	}
	}
	

	return map;
}

