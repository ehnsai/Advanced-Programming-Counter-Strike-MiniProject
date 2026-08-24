#include "Header_of_random.h"


void random::sett_nameOfplayer(vector <string>& name)
{
	nameOfplayer = name;
}

void random::sett_availableGuns(vector <Gun>& guns)
{
	availableGuns = guns;
}

string random::random_nameOfplayer()
{
	vector<string> names = {
		"Aria", "Baran", "Cyrus", "Dara", "Ehsan",
		"Farhad", "Goli", "Hamed", "Iman", "Javad",
		"Kian", "Laleh", "Mani", "Navid", "Omid",
		"Pouya", "Qasem", "Reza", "Sara", "Tara",
		"Umid", "Vahid", "Yasin", "Zahra", "Ali",
		"Bahar", "Darya", "Elahe", "Farshad", "Gita",
		"Hossein", "Ishaq", "Jaleh", "Khosro", "Leyla",
		"Mehdi", "Narges", "Parisa", "Ramin", "Shadi",
		"Tina", "Vafa", "Younes", "Zeynab", "Arash",
		"Behnaz", "Davood", "Elham", "Firouz", "Golnar"
	};
	this->sett_nameOfplayer(names);
	int numberOfrand = rand() % nameOfplayer.size();
	return nameOfplayer[numberOfrand];
}


int random::random_nameOfGun()
{
	int numberOfrand = 10 + rand() % 24;
	return numberOfrand;
}


int random::random_idOfGun()
{
	return 10000 + (rand() % 90000);
}

int random::random_Health()
{
	return 10 + (rand() % 9000);
}


int random::random_Armor()
{
	return 100 + (rand() % 800);
}


bool random::random_bool()
{
	return rand() % 2 == 1;
}

int random::random_money()
{
	return 1000 + (rand() % 5000);
}

int random::random_ammocountOfGun()
{
	return rand() % 31 + 20;
}

int random::random_priceOfGun()
{
	return rand() % 3001 + 1000;
}

int random::random_powerOfGun()
{
	return rand() % 51 + 50;
}

Gun random::random_gun()
{
	int randd = rand() % 20;
	return availableGuns[randd];
}

int random::random_GunCount()
{
	return 1 + (rand() % 4);
}

Gun random::random_gun_based_on_money(int money)
{
	vector<Gun> affordableGuns;

	for (int i = 0; i < availableGuns.size(); ++i)
	{
		if (availableGuns[i].get_price() <= money)
		{
			affordableGuns.push_back(availableGuns[i]);
		}
	}

	if (affordableGuns.empty()) {
		return Gun();
	}

	int randIndex = rand() % affordableGuns.size();
	return affordableGuns[randIndex];
}

vector<Gun>& random::get_availableGuns()
{
	return availableGuns;
}

vector<string>& random::get_nameOfplayer()
{
	return nameOfplayer;
}

