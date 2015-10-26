#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<ncurses.h>
using namespace std;
int abs(int n){
	if(n<0) n=-n;
	return n;
}

void wall(char** map){
	for(int i=1; i<24; i += 1){
		for(int j=1;j<79; j += 1){
			if(map[i][j]=='.'&&map[i+1][j]==' ')map[i+1][j]='-';
			if(map[i][j]=='.'&&map[i-1][j]==' ')map[i-1][j]='-';
		}
	}
	for ( int i = 0; i < 25; i += 1)
	{
		for ( int j = 0; j < 79; j += 1)
		{
			if(map[i][j]=='.'&&map[i][j+1]!='.')map[i][j+1]='|';
			if(map[i][j]=='.'&&map[i][j-1]!='.')map[i][j-1]='|';
			if(map[i][j]=='-'&&map[i][j-1]!='-'&&map[i][j-1]!='.')map[i][j-1]='|';
			if(map[i][j]=='-'&&map[i][j+1]!='-'&&map[i][j+1]!='.')map[i][j+1]='|';
		}
	}		
}

void printMap(char** map){
	for(int i=0;i<25;i++){
		for(int j=0;j<80;j++){
			cout<<map[i][j];
		}
		printw("\n");
	}
}

void connect(int r1,int c1,int r2,int c2,char** map){
	int dir;
	while(r1!=r2||c1!=c2){
		dir=rand()%2;
		if(dir==0&&r1!=r2){
			if(r1>r2) r1--;
			else if(r1<r2) r1++;
		}else if(dir==1&&c1!=c2){
			if(c1>c2) c1--;
			else if(c1<c2) c1++;
		}
		if(map[r1][c1]==' ')map[r1][c1]='#';
		if(map[r1][c1]=='|'|| map[r1][c1]=='-')map[r1][c1]='+';
		
	}
}
void connect(int r[],int c[],char** map,int n){
	for(int i=0;i<n-1;i++){
		connect(r[i],c[i],r[i+1],c[i+1],map);
	}
	
}

bool expand(int r,int c,char** map){
	int dir;
	int count;
	while(map[r][c]!=' '){
		dir=rand()%4;
		if(dir==0){
			if(r<24)r++;
		}else if(dir==1){
			if(r>1)r--;
		}else if(dir==2){
			if(c<79)c++;
		}else{
			if(c>1)c--;
		}
	}
	map[r][c]='.';
	return false;///
}

char** RanGenMap(int n){
	char** map=new char*[25];
	for (int i = 0; i < 25; i++){
		map[i]=new char[80];
	}
	for(int i=0;i<25;i++){
		for(int j=0;j<80;j++){
			map[i][j]=' ';
		}
	}
	int r[n];
	int c[n];
	for(int i=0;i<n;i++){
		r[i]=rand()%22+2;
		c[i]=rand()%75+2;
		for(int j=0;j<i;j++){
			while(abs(r[j]-r[i])<=5&&abs(c[j]-c[i])<=15){
				r[i]=rand()%22+2;
				c[i]=rand()%75+2;
			}
		}
		map[r[i]][c[i]]='.';
	}
	
	for(int i=0;i<n;i++){
		int time=rand()%80+50;
		for(int j=0;j<time;j++){
			expand(r[i],c[i],map);
		}
	}
	wall(map);
	
	connect(r,c,map,n);
	
	for(int i=0;i<80;i++){
		map[0][i]='-';
		map[24][i]='-';
	}
	for(int i=0;i<25;i++){
		map[i][0]='|';
		map[i][79]='|';
	}
	return map;
}


