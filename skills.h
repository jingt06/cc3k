#ifndef __SKILLS_H__
#define __SKILLS_H__
#include<iostream>
#include<string>
#include"skill.h"
class player;
class BloodFury :public skill{
	public:
	BloodFury();
	std::string use(player& p);	
};
class ShadowMeld :public skill{
	public:
	ShadowMeld();
	std::string use(player& p);	
};

class StoneForm :public skill{
	public:
	StoneForm();
	std::string use(player& p);	
};

class HumanSpirit:public skill{
	public:
	HumanSpirit();
	std::string use(player& p);	
};

class Whirlwind:public skill{
	public:
	Whirlwind();
	std::string use(player& p,floor&f);
};

class DemoralizingShout:public skill{
	public:
	DemoralizingShout();
	std::string use(player&p,floor&f);
};

class FrostNova:public skill{
	public:
	FrostNova();
	std::string use(player&p,floor&f);
};

class SpiritualHealing: public skill{
	public:
	SpiritualHealing();
	std::string use(player&p,floor&f);
};

class Slam:public skill{
	public:
	Slam();
	std::string use(player& p,floor&f);
};

class FireBlast:public skill{
	public:
	FireBlast();
	std::string use(player& p,floor&f);
};

class BloodMagic:public skill{
	public:
	BloodMagic();
	std::string use(player& p,floor&f);
}; 

class Vitality:public skill{
	public:
	Vitality();
	std::string use(player& p,floor&f);
};

class WoundingArrow:public skill{
	public:
	WoundingArrow();
	std::string use(player& p,floor&f);
};

class Flatten:public skill{
	public:
	Flatten();
	std::string use(player& p,floor&f);
};

class DeathCurse:public skill{
	public:
	DeathCurse();
	std::string use(player& p,floor&f);
};
class Blessing:public skill{
	public:
	Blessing();
	std::string use(player& p,floor&f);
};

#endif
