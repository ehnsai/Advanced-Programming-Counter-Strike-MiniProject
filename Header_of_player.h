#ifndef PLAYER_H
#define PLAYER_H

#include "Header_of_Gun.h"
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

class player {
private:
	string ID;
	string nameOFplayer;
	vector <int> idOFGun;
	vector <string> nameOFGun;
	int Health;
	int Armor;
	bool Alive;
	bool Bot;
	int money;
	int GunCount;
	static int count;
	string generateID();

	struct Node 
	{
		Gun gun;
		Node* next;
		Node* prev;
		Node(Gun g)
		{
			gun = g;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head;
	Node* current;
public:
	player();
	player(string nameOFplayer_, vector <int>& idOFGun_, vector <string>& nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_,int GunCount_);
	//player(player& other);
	string get_ID();
	string get_nameOFplayer();
	vector <int>& get_idOFGun();
	vector <string>& get_nameOFGun();
	int get_Health();
	int get_Armor();
	bool get_Alive();
	bool get_Bot();
	int get_money();
	int get_GunCount();

	void sett_nameOFplayer(string n);
	void sett_idOFGun(vector <int>& i);
	void sett_nameOFGun(vector <string>& ng);
	void sett_Health(int h);
	void sett_Armor(int a);
	void sett_Alive(bool a);
	void sett_Bot(bool b);
	void sett_money(int m);
	void sett_GunCount(int c);

	void AddGun(Gun g);
	void nextGun();
	void prevGun();
	void displayGun();
	Gun get_currentGun();
	void printflash();

	player& operator=(player& other);
	bool operator==(player& other);
	bool operator!=(player& other);

	int calcutepower();

	void display();

	void navigateGuns();
};

#endif
