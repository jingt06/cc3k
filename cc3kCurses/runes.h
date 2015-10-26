#ifndef __RUNES_H__
#define __RUNES_H__
#include "rune.h"
#include "player.h"

class StrengthRune:public Rune{
	public:
	StrengthRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};
class QuicknessRune:public Rune{
	public:
	QuicknessRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};

class HardnessRune:public Rune{
	public:
	HardnessRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};

class HealthRune:public Rune{
	public:
	HealthRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};

class PowerRune:public Rune{
	public:
	PowerRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};

class GodRune:public Rune{
	public:
	GodRune();
	std::string getName();
	void UseRune(player& p);
	void DropRune(player& p);
};
#endif
