#include "Header_of_Gun.h"

int Gun::NumberOfGun = 0;

Gun::Gun()
{
	ammocount = 30;
	price = 1000;
	ID = 0;
	name = AK_47;
	power = 5;
	NumberOfGun++;
}

Gun::Gun(int ammocount_, int price_, int ID_, int id, int power_)
{
	ammocount = ammocount_;
	price = price_;
	ID = ID_;
	power = power_;
	switch (id)
	{
	case 10:
		name = AK_47;
		break;
	case 11:
		name = M416;
		break;
	case 12:
		name = AKM;
		break;
	case 13:
		name = UZI;
		break;
	case 14:
		name = DP;
		break;
	case 15:
		name = UMP_45;
		break;
	case 16:
		name = FN_Five_seven;
		break;
	case 17:
		name = Tec_9;
		break;
	case 18:
		name = MAC_10;
		break;
	case 19:
		name = Skorpion;
		break;
	case 20:
		name = RPG_7;
		break;
	case 21:
		name = AT4;
		break;
	case 22:
		name = Javelin;
		break;
	case 23:
		name = Stinger;
		break;
	case 24:
		name = FIM_92;
		break;
	case 25:
		name = M320;
		break;
	case 26:
		name = GP_25;
		break;
	case 27:
		name = M203;
		break;
	case 28:
		name = M79;
		break;
	case 29:
		name = RPG_26;
		break;
	case 30:
		name = G36C;
		break;
	case 31:
		name = FAMAS;
		break;
	case 32:
		name = Galil;
		break;
	case 33:
		name = Tavor;
		break;
	}
	NumberOfGun++;
}

//Gun::Gun(Gun& other)
//{
//	ammocount = other.ammocount;
//	price = other.price;
//	ID = other.ID;
//	name = other.name;
//	power = other.power;
//	NumberOfGun++;
//}

int Gun::get_ammo()
{
	return ammocount;
}

int Gun::get_price()
{
	return price;
}

int Gun::get_Id()
{
	return ID;
}

string Gun::get_name()
{
	switch (name)
	{
	case 10:
		return "AK_47";
	case 11:
		return "M416";
	case 12:
		return "AKM";
	case 13:
		return "UZI";
	case 14:
		return "DP";
	case 15:
		return "UMP_45";
	case 16:
		return "FN_Five_seven";
	case 17:
		return "Tec_9";
	case 18:
		return "MAC_10";
	case 19:
		return "Skorpion";
	case 20:
		return "RPG_7";
	case 21:
		return "AT4";
	case 22:
		return "Javelin";
	case 23:
		return "Stinger";
	case 24:
		return "FIM_92";
	case 25:
		return "M320";
	case 26:
		return "GP_25";
	case 27:
		return "M203";
	case 28:
		return "M79";
	case 29:
		return "RPG_26";
	case 30:
		return "G36C";
	case 31:
		return "FAMAS";
	case 32:
		return "Galil";
	case 33:
		return "Tavor";
	}
}

int Gun::get_power()
{
	return power;
}

int Gun::get_NumberOfGun()
{
	return NumberOfGun;
}

void Gun::set_ammo(int ammo_)
{
	ammocount = ammo_;
}

void Gun::set_price(int price_)
{
	price = price_;
}

void Gun::set_ID(int ID_)
{
	ID = ID_;
}

void Gun::set_name(int name_)
{
	switch (name_)
	{
	case 10:
		name = AK_47;
		break;
	case 11:
		name = M416;
		break;
	case 12:
		name = AKM;
		break;
	case 13:
		name = UZI;
		break;
	case 14:
		name = DP;
		break;
	case 15:
		name = UMP_45;
		break;
	case 16:
		name = FN_Five_seven;
		break;
	case 17:
		name = Tec_9;
		break;
	case 18:
		name = MAC_10;
		break;
	case 19:
		name = Skorpion;
		break;
	case 20:
		name = RPG_7;
		break;
	case 21:
		name = AT4;
		break;
	case 22:
		name = Javelin;
		break;
	case 23:
		name = Stinger;
		break;
	case 24:
		name = FIM_92;
		break;
	case 25:
		name = M320;
		break;
	case 26:
		name = GP_25;
		break;
	case 27:
		name = M203;
		break;
	case 28:
		name = M79;
		break;
	case 29:
		name = RPG_26;
		break;
	case 30:
		name = G36C;
		break;
	case 31:
		name = FAMAS;
		break;
	case 32:
		name = Galil;
		break;
	case 33:
		name = Tavor;
		break;
	}
}

void Gun::set_power(int power_)
{
	power = power_;
}

void Gun::display()
{
	cout << "number of ammo : " << get_ammo() << endl;
	cout << "price : " << get_price() << endl;
	cout << "ID : " << get_Id() << endl;
	switch (name)
	{
	case 10:
		cout << "name : AK_47" << endl;
		break;
	case 11:
		cout << "name : M416" << endl;
		break;
	case 12:
		cout << "name : AKM" << endl;
		break;
	case 13:
		cout << "name : UZI" << endl;
		break;
	case 14:
		cout << "name : DP" << endl;
		break;
	case 15:
		cout << "name : UMP_45" << endl;
		break;
	case 16:
		cout << "name : FN_Five_seven" << endl;
		break;
	case 17:
		cout << "name : Tec_9" << endl;
		break;
	case 18:
		cout << "name : MAC_10" << endl;
		break;
	case 19:
		cout << "name : Skorpion" << endl;
		break;
	case 20:
		cout << "name : RPG_7" << endl;
		break;
	case 21:
		cout << "name : AT4" << endl;
		break;
	case 22:
		cout << "name : Javelin" << endl;
		break;
	case 23:
		cout << "name : Stinger" << endl;
		break;
	case 24:
		cout << "name : FIM_92" << endl;
		break;
	case 25:
		cout << "name : M320" << endl;
		break;
	case 26:
		cout << "name : GP_25" << endl;
		break;
	case 27:
		cout << "name : M203" << endl;
		break;
	case 28:
		cout << "name : M79" << endl;
		break;
	case 29:
		cout << "name : RPG_26" << endl;
		break;
	case 30:
		cout << "name : G36C" << endl;
		break;
	case 31:
		cout << "name : FAMAS" << endl;
		break;
	case 32:
		cout << "name : Galil" << endl;
		break;
	case 33:
		cout << "name : Tavor" << endl;
		break;
	}
	cout << "power of Gun : " << get_power() << endl;
}

Gun& Gun::operator=(Gun& other)
{
	ammocount = other.ammocount;
	price = other.price;
	ID = other.ID;
	name = other.name;
	power = other.power;
	return *this;
}

bool Gun::operator==(Gun& other)
{
	if (ammocount == other.ammocount &&
		price == other.price &&
		ID == other.ID &&
		name == other.name &&
		power == other.power)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gun::operator!=(Gun& other)
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
