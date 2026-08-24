#ifndef CT_H
#define CT_H

#include "Header_of_player.h"

class ct : public player
{
private:
	bool has_kit_disposal;
	bool disposalBomb;
public:
	ct();
	ct(string nameOFplayer_, vector <int> idOFGun_, vector <string> nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_,
		int GunCount_,bool h,bool d);
	//ct(ct& other);
	bool get_has_kit();
	bool get_disposalBomb();
	void sett_has_kit(bool h);
	void sett_disposalBomb(bool d);
	ct& operator=(ct& other);
	bool operator==(ct& other);
	bool operator!=(ct& other);
	void show();
};

#endif
