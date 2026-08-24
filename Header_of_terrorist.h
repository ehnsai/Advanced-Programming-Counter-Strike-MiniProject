#ifndef TERRORIST_H
#define TERRORIST_H

#include "Header_of_player.h"


class terrorist : public player
{
private:
	bool hasbomb;
	bool plantingBomb;
public:
	terrorist();
	terrorist(string nameOFplayer_, vector <int> idOFGun_, vector <string> nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_,
		int GunCount_, bool h, bool p);
	//terrorist(terrorist& other);
	bool get_hasBomb();
	bool get_plantingBomb();
	void sett_hasBomb(bool h);
	void sett_plantingBomb(bool p);
	terrorist& operator=(terrorist& other);
	bool operator==(terrorist& other);
	bool operator!=(terrorist& other);
	void show();
};


#endif
