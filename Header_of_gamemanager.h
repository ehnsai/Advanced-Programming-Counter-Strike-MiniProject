#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Header_of_ct.h"
#include "Header_of_terrorist.h"
#include "Header_of_map.h"

#include <iostream>
#include <vector>

using namespace std;

class gamemanager {
private:
	map map_of_game;
	vector <ct> vec_ct;
	vector <terrorist> vec_terrorist;
	int resualt;
	static gamemanager* ins;
	gamemanager()
	{
		resualt = 0;
	}
	gamemanager(const gamemanager&) = delete;
	gamemanager& operator=(const gamemanager&) = delete;
public:
	static gamemanager* get_ins();
	int get_resualt();
	void sett_resualt(int r);
	void sett_vec_ct(vector <ct> v);
	vector<ct>& get_vecct();
	vector<terrorist>& get_t();
	void sett_vec_terrorist(vector <terrorist> v);
	void sett_map_of_game(map m);
	map get_map();
	void startfight();
	void reset();
	int calcute_damage(int fdamage,bool night_, bool snowy_);
};


#endif
