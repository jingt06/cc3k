#include<stdlib.h>  
#include<time.h>  
#include<ncurses.h>
#include<string>
#include<iostream>
#include"print.h"
#include"helper.h"
#include"player.h"
#include <unistd.h>

using namespace std;
int main(int argc,char* argv[]){
	initscr();
	//noecho();
	char str[80];
	bool input=false;
	bool endGame=false;
	bool won=false;
	char *** map=NULL;
	if(argc==2){
		map =readfile(argv[1]);
		input=true;
	}
	void printGameOver();
	bool classset=false;
	srand(time(NULL));
	player* p=NULL;
	char cmd;
	bool act=false;
	bool setrace=false;
	
	printLogo();//print the story
	cmd=getch();
	printName();
	cmd=getch();
	printstory();
	int i;//item/skill #
	string action="";
	printOptions(); //display the options(command)
	printRace();//race infomation
	while(true){
		while(!setrace){
			if(cmd=='q'){
				endGame=true;
				break;
			}
			if(p!=NULL) delete p;
			if(!setRace(&p,str,false,map)){
				getstr(str);
			}else{
				setrace=true;
				clear();
				p->display();
				for (int i=0; i<80; i ++)
				{
					str[i]=' ';	
				}
			}

		}
		if(endGame){break;}
		cmd=getch();
	if(!p->isDead()||p->isWon()){
		if(cmd=='w'){
			action=p->move("no");
			act=true;
		}else if(cmd=='s'){
			action=p->move("so");
			act=true;
		}else if(cmd=='d'){
			action=p->move("ea");
			act=true;
		}else if(cmd=='a'){
			action=p->move("we");
			act=true;
		}else if (cmd == 'i'){ //inventory
			printw("\n");
			p->listInventory ();
		} else if (cmd=='u'){
			p->listInventory ();
			printw("\nselect the Item you want to use\n");
			cmd=getch();
			if((cmd>='0')&&(cmd<='5'))p->useItem(cmd-'0');	
			else printw("\nplease enter an integer\n");
			act=true;
		} else if (cmd=='o'){
			p->sellItem();
		} else if (cmd=='p'){
			p->buyItem();
		} else if (cmd == '['){
			p->listInventory ();
			printw("\nselect the Item you want to drop\n");
			cmd=getch();
			if((cmd>='0')&&(cmd<='5'))p->dropItem(cmd-'0');
			else printw("\nplease enter an integer\n");
		}else if (cmd == ']'){//check skill
			printw("key[j]: ");
			cout<<*(p->getskill());
			printw("\n");
			p->listCSkill();
		}else if (cmd == 'j'){
			action=p->useRaceSkill();
			act=true;
			}else if (cmd == 'k'){
			action=p->useCSkill1();
		act=true;
			}else if (cmd == 'l'){
			action=p->useCSkill2();
			act=true;
			}else if (cmd == ';'){
			action=p->useUSkill();
			act=true;
			}else if(cmd=='h'){
			act=true;
		}
	}
	if(cmd == '?'){
		clear;
		printOptions();
	} else if (cmd == 'r'){
		delete p;
		p=NULL;
		setrace=false;
		clear();
		printRace();
	}else if (cmd == 'q'){
		break;
	}
	
	if(act){
		clear();
		p->coolDown();
		action=p->EnemyTurn(action);
		p->display(action);
	}
	if(p!=NULL&&p->isDead()){
		clear();
		printGameOver();
		p->printScore();
		printw("\n");
	}else if(p!=NULL&&p->isWon()){
		clear();
		printWon();
		p->printScore();
		printw("\n");
	}
	act=false;
	action="";
	}
	delete p;
 	endwin();
}



