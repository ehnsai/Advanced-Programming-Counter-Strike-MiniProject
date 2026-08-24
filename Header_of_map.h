#ifndef MAP_H
#define MAP_H

#include "Header_of_player.h"

class map
{
private:
	string nameOFmap;
	string nameOFdesigner;
	bool night;
	bool snow;
public:
	map();
	map(string nm, string nd, bool n,bool s);
	//map(map& other);
	string get_nameOFmap();
	string get_nameOFdesigner();
	bool get_night();
	bool get_snow();
	void sett_nameOFmap(string nm);
	void sett_nameOFdesigner(string nd);
	void sett_night(bool n);
	void sett_snow(bool s);
	map& operator=(map& other);
	bool operator==(map& other);
	bool operator!=(map& other);
};


#endif

