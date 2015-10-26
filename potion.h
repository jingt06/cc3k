#ifndef __POTION_H__
#define __POTION_H__
#include "item.h"
//class Item;
class Potion: public Item {
protected:
	bool isFromM;
public:
	Potion();
	const char getChar();
	const char getType();
	const bool getisFromM();
	void setisFromM(bool change);
	virtual ~Potion();
};
#endif