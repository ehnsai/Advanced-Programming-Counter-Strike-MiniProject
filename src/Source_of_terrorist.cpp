#include "Header_of_terrorist.h"

terrorist::terrorist()
{
	hasbomb = false;
	plantingBomb = false;
}

terrorist::terrorist(string nameOFplayer_, vector <int> idOFGun_, vector <string> nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_,
	int GunCount_, bool h, bool p)
{
	player::sett_nameOFplayer(nameOFplayer_);
	player::sett_idOFGun(idOFGun_);
	player::sett_nameOFGun(nameOFGun_);
	player::sett_Health(Health_);
	player::sett_Armor(Armor_);
	player::sett_Alive(Alive_);
	player::sett_Bot(Bot_);
	player::sett_money(money_);
	player::sett_GunCount(GunCount_);
	hasbomb = h;
	plantingBomb = p;
}

//terrorist::terrorist(terrorist& other)
//{
//	hasbomb = other.hasbomb;
//	plantingBomb = other.plantingBomb;
//}

bool terrorist::get_hasBomb()
{
	return hasbomb;
}

bool terrorist::get_plantingBomb()
{
	return plantingBomb;
}

void terrorist::sett_hasBomb(bool h)
{
	hasbomb = h;
}

void terrorist::sett_plantingBomb(bool p)
{
	plantingBomb = p;
}

terrorist& terrorist::operator=(terrorist& other)
{
	sett_nameOFplayer(other.get_nameOFplayer());
	sett_nameOFGun(other.get_nameOFGun());
	sett_idOFGun(other.get_idOFGun());
	sett_Health(other.get_Health());
	sett_Armor(other.get_Armor());
	sett_Alive(other.get_Alive());
	sett_Bot(other.get_Bot());
	sett_money(other.get_money());
	hasbomb = other.hasbomb;
	plantingBomb = other.plantingBomb;
	return *this;
}

bool terrorist::operator==(terrorist& other)
{
	if (get_nameOFplayer() == other.get_nameOFplayer() &&
		get_nameOFGun() == other.get_nameOFGun() &&
		get_idOFGun() == other.get_idOFGun() &&
		get_Health() == other.get_Health() &&
		get_Armor() == other.get_Armor() &&
		get_Alive() == other.get_Alive() &&
		get_Bot() == other.get_Bot() &&
		get_money() == other.get_money() &&
		hasbomb == other.hasbomb &&
		plantingBomb == other.plantingBomb)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool terrorist::operator!=(terrorist& other)
{
	if (*this == other)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void terrorist::show()
{
	cout << "ID : " << get_ID() << endl;
	cout << "name of player : " << get_nameOFplayer() << endl;
	cout << "id of Gun : " << endl;
	for (int i = 0;get_GunCount() > i;++i)
	{
		cout << "Gun " << i + 1 << " : " << get_idOFGun()[i] << endl;
	}
	cout << "name of Guns : " << endl;
	for (int i = 0;get_GunCount() > i;++i)
	{
		cout << "Gun " << i + 1 << " : " << get_nameOFGun()[i] << endl;
	}
	cout << "Health : " << get_Health() << endl;
	cout << "Armor : " << get_Armor() << endl;
	cout << "Alive : " << get_Alive() << endl;
	cout << "Bot : " << get_Bot() << endl;
	cout << "money : " << get_money() << endl;
}
