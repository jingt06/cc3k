#ifndef __RUNE__H__
#define __RUNE__H__
#include"item.h"
class Rune: public Item {
	public:
	Rune();
	const char getType();
	void setAmount(int i);
	const char getChar();
	void useItem(player *p);
};


#endif
