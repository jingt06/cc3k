#ifndef __ITEM_H__
#define __ITEM_H__


#include "object.h"
//class Object;
class player;
class Item: public Object {
protected:
	int amount;
public:
	Item();
	int getAmount();
	virtual const char getType() = 0;
	virtual void setAmount(int i) = 0;
	virtual std::string getName() = 0;
	virtual const char getChar() = 0;
	virtual void useItem(player *p) = 0;
	virtual bool getPickState();
	virtual void changePickState();
	virtual ~Item();
	virtual void UseRune(player& p);
	virtual void DropRune(player& p);
	virtual const bool getisFromM();
	virtual void setisFromM(bool change);
};
#endif
