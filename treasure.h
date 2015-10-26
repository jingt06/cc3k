#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "treasure.h"
#include "item.h"
class Dragon;
class Item;
class Treasure: public Item {
	bool PickState;
	Dragon * dragon;
public:
	Treasure();
	void setAmount(int i);
	std::string getName();
	const char getType();
	const char getChar();
	void useItem(player *p);
	bool getPickState();
	void changePickState();
	void setDragon(Dragon * dragon);
	Dragon* getDragon();
	~Treasure();
};
#endif
