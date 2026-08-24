#ifndef GUN_H
#define GUN_H

#include <iostream>
#include <string>

using namespace std;

enum Gunname {
	AK_47 = 10, M416 = 11, AKM = 12, UZI = 13, DP = 14, UMP_45 = 15, FN_Five_seven = 16,
	Tec_9 = 17 , MAC_10 = 18 , Skorpion = 19 ,
	RPG_7 = 20, AT4 = 21 , Javelin = 22, Stinger = 23, FIM_92 = 24 ,
	M320 = 25, GP_25 = 26 , M203 = 27 , M79 = 28 , RPG_26 = 29 ,
	G36C = 30 , FAMAS = 31 , Galil = 32 , Tavor = 33 
};

class Gun {
private:
	int ammocount;
	int price;
	int ID;
	Gunname name;
	int power;
	static int NumberOfGun;
public:
	Gun();
	Gun(int ammocount_, int price_, int ID_, int id, int power_);
	//Gun(Gun& other);
	int get_ammo();
	int get_price();
	int get_Id();
	string get_name();
	int get_power();
	static int get_NumberOfGun();
	void set_ammo(int ammo_);
	void set_price(int price_);
	void set_ID(int ID_);
	void set_name(int name_);
	void set_power(int power_);
	Gun& operator=(Gun& other);
	bool operator==(Gun& other);
	bool operator!=(Gun& other);
	void display();
};

#endif
