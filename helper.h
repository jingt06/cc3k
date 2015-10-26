#ifndef __HELPER_H__
#define __HELPER_H__
#include<string>
class player;
bool setRace(player** p, std::string rc,bool input,char*** maps);
int generate_int(int lower,int upper);
std::string IntToString(int n);
int absl(int n);
int NextTo(int a1,int b1,int a2,int b2,int d);
int NextTo(int a1,int b1,int a2,int b2);
char*** readfile(std::string f);
#endif
