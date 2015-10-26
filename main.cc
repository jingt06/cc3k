#include<stdlib.h>  
#include<time.h>  
#include<string>
#include<iostream>
#include"print.h"
#include"helper.h"
#include"player.h"
#include"global.h"

using namespace std;
int main(int argc,char* argv[]){
	bool input=false;
	bool endGame=false;
	bool won=false;
	char *** map=NULL;
	char c=' ';
	string any;
	if(argc>=2){
		for (int i=1; i<argc; i ++)
		{
			string argument(argv[i]);
			if(argument=="-bonus"){
				bonus=true;
				maxfloor=7;
			}else{
				map =readfile(argv[i]);
				input=true;
				break;
			}
		}
	}
	void printGameOver();
	bool classset=false;
	srand(time(NULL));
	player* p=NULL;
	string cmd;
	bool act=false;
	bool setrace=false;
	
	printLogo();//print the story
	printName();
	printstory();
	int i;//item/skill #
	string action="";
	printOptions(); //display the options(command)
	printRace();//race infomation
	while(cin>>cmd){
		while(!setrace){
			if(cmd=="q"){
				endGame=true;
				break;
			}
			if(p!=NULL) delete p;
			if(!setRace(&p,cmd,input,map)){
				cin>>cmd;
			}else{
				setrace=true;
				p->display();
			}if(cin.eof()){
				endGame=true;
				break;
			}

		}
		if(endGame){break;}
	if(!p->isDead()||p->isWon()){
		if ((cmd == "no")||(cmd == "so")||(cmd == "ea")||(cmd == "we")||(cmd == "ne")||(cmd == "nw")||(cmd == "se")||	(cmd == "sw")){
			action=p->move(cmd);
			act=true;
		} else if (cmd == "a"){
			string dir;
			cin >> dir;
			action=p->attack(dir);
			act=true;
		}  else if (cmd == "I"&&bonus){ //inventory
			p->listInventory ();
		} else if (cmd=="u"){
			if(bonus){
				p->listInventory ();
				cout<<"plece slect the item you want to drop"<<endl;
				cin>>c;
				if(c>='0'&&c<='9'){
					i=c-'0';
				}else{
					cout<<"please input an integer"<<endl;
					continue;
				}
				p->useItem(i);
			}else{
				string dir;
				cin >> dir;
				action=p->use(dir);
				act=true;
			}
		} else if (cmd=="sell"&&bonus){
			p->sellItem();
		} else if (cmd=="buy"&&bonus){
			p->buyItem();
		} else if (cmd == "d"&&bonus){
			p->listInventory ();
			cout<<"plece slect the item you want to drop"<<endl;
			cin>>c;
			if(c>='0'&&c<='9'){
				i=c-'0';
			}else{
				cout<<"please input an integer"<<endl;
				continue;
			}
			p->dropItem(i);
			}else if (cmd == "s"&&bonus){//check skill
			cout<<"key[us1]: "<<*(p->getskill())<<endl;
			p->listCSkill();
		}else if (cmd == "us1"&&bonus){
			action=p->useRaceSkill();
			act=true;
			}else if (cmd == "us2"&&bonus){
			action=p->useCSkill1();
		act=true;
			}else if (cmd == "us3"&&bonus){
			action=p->useCSkill2();
			act=true;
			}else if (cmd == "usu"&&bonus){
			action=p->useUSkill();
			act=true;
			}else if(cmd=="w"){
			act=true;
		}
	}
	if(cmd == "?"){
		printOptions();
	} else if (cmd == "r"){
		delete p;
		p=NULL;
		setrace=false;
		printRace();
	}else if (cmd == "q"){
		break;
	}
	
	if(act){
		p->coolDown();
		action=p->EnemyTurn(action);
		p->display(action);
	}
	if(p!=NULL&&p->isDead()){
		printGameOver();
		p->printScore();
		cout<<endl;
	}else if(p!=NULL&&p->isWon()){
		printWon();
		p->printScore();
		cout<<endl;
	}
	act=false;
	action="";
	}
	//delete p;
	if (map!=NULL)
	{
		for (int i=0; i<maxfloor; i ++)
		{
			for (int j=0; j<25; j ++)
			{
				delete [] map[i][j];
			}
			delete [] map[i];
		}
		delete [] map;
	}
}



