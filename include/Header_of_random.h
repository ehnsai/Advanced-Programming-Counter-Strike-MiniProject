#ifndef RANDOM_H
#define RANDOM_H

#include "Header_of_Gun.h"

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class random {
private:
	vector <string> nameOfplayer;
	vector <Gun> availableGuns;
public:
	random() {};
	void sett_nameOfplayer(vector <string>& name);
	void sett_availableGuns(vector <Gun>& guns);
	vector<string>& get_nameOfplayer();
	vector<Gun>& get_availableGuns();
	string random_nameOfplayer();
	int random_nameOfGun();
	int random_idOfGun();
	int random_Health();
	int random_Armor();
	bool random_bool();
	int random_money();
	int random_ammocountOfGun();
	int random_priceOfGun();
	int random_powerOfGun();
	int random_GunCount();
	Gun random_gun();
	Gun random_gun_based_on_money(int money);
};



#endif;
