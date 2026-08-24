#include "Header_of_ct.h"

ct::ct()
{
	has_kit_disposal = false;
	disposalBomb = false;
}

ct::ct(string nameOFplayer_, vector <int> idOFGun_, vector <string> nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_,
	int GunCount_, bool h,bool d)
{
	player::sett_nameOFplayer(nameOFplayer_);
	player::sett_idOFGun(idOFGun_);
	player::sett_nameOFGun(nameOFGun_);
	player::sett_Health(Health_);
	player::sett_Armor(Armor_);
	player::sett_Alive(Alive_);
	player::sett_Bot(Bot_);
	player::sett_money(money_);
	has_kit_disposal = h;
	disposalBomb = d;
}

//ct::ct(ct& other)
//{
//	has_kit_disposal = other.has_kit_disposal;
//	disposalBomb = other.disposalBomb;
//}

bool ct::get_has_kit()
{
	return has_kit_disposal;
}

bool ct::get_disposalBomb()
{
	return disposalBomb;
}

void ct::sett_has_kit(bool h)
{
	has_kit_disposal = h;
}

void ct::sett_disposalBomb(bool d)
{
	disposalBomb = d;
}

ct& ct::operator=(ct& other)
{
	sett_nameOFplayer(other.get_nameOFplayer());
	sett_nameOFGun(other.get_nameOFGun());
	sett_idOFGun(other.get_idOFGun());
	sett_Health(other.get_Health());
	sett_Armor(other.get_Armor());
	sett_Alive(other.get_Alive());
	sett_Bot(other.get_Bot());
	sett_money(other.get_money());
	sett_GunCount(other.get_GunCount());
	has_kit_disposal = other.has_kit_disposal;
	disposalBomb = other.disposalBomb;
	return *this;
}

bool ct::operator==(ct& other)
{
	if (get_nameOFplayer() == other.get_nameOFplayer() &&
		get_nameOFGun() == other.get_nameOFGun() &&
		get_idOFGun() == other.get_idOFGun() &&
		get_Health() == other.get_Health() &&
		get_Armor() == other.get_Armor() &&
		get_Alive() == other.get_Alive() &&
		get_Bot() == other.get_Bot() &&
		get_money() == other.get_money() &&
		has_kit_disposal == other.has_kit_disposal &&
		disposalBomb == other.disposalBomb)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ct::operator!=(ct& other)
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

void ct::show()
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
