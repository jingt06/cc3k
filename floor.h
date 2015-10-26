#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include "cell.h"
#include "player.h"
#include "enemy.h"
#include "bosses.h"
#include "item.h"
#include "treasure.h"
class Item;
class Boss;
class player;
class Enemy;
class Cell;
class Dragon;
class floor{
	int maxEnemy;
	const int maxItem;
	const int maxWidth;
	const int maxHeight;
	bool random;
	int level,numEnemy,numItem,nummercdead, numdragon,numTreasure,numGoods;
	Enemy * floorEnemy[20];
	Item * floorItem[10];
	Item * merchantGoods[5];
	Treasure * floorTreasure[10];
	Boss * B;
	Cell **theWorld;
	player* p;
	Treasure* merchantHoard[20];
	Dragon * dragon[20];
	
	public:
	int label();
	void addItem(int n,int r,int c);
	void addTreasure(int n,int r,int c);
	void label(int i,int j,int c);
	floor(player* p,const int& level,bool ran,char**map=NULL);
	//std::string getItem(int r,int c);//the player get the item at (r,c)and return the action of this item
	//string getItem(int r, int c){//call player->getItem and delete the item from floorItem list
	void notify(int prevr,int prevc,int r,int c);//the character at (prevr,prevc) moves to (r,c)  and notify the TextDisplay
	void display(std::string action="");//call display in TextDisplay to print the display(map, action and status)
	void generateEnemy(int level,int n);//generate the enemy(strength depends on the level of the floor)
	void generateItem(int level,int n);//generate the Item in the floor
	void generateGoods();
	void generateTreasure(int level,int n);
	char check(int r,int c); //check if (r,c) is occupied,
						//return i: item
						//return .: able to move
						//return /: a stair
						//return e: an enemy
						//return x: unable to move 
	std:: string attack(int r,int c);
	std::string EnemyTurn(std::string action);
	Object* getObj(int r,int c);
	Item* getGoods(int i);
	void resetCell(int r,int c);
	std::string getItem(int r, int c, char ch);
	void generateRune();
	void linkDragonHoard();
	void listGoods();
	~floor();
};

#endif
