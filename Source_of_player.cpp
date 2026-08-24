#include "Header_of_player.h"


int player::count = 1;

string player::generateID()
{
	std::stringstream ss;
	ss << "player : " << time(nullptr);
	ss << "-" << rand() % 10000;
	ss << "-" << count++;
	return ss.str();
}

player::player()
{
	ID = generateID();
	 nameOFplayer = "none";
	 vector <int> id = { 0 };
	 vector <string> name = { "none" };
	 idOFGun = id;
	 nameOFGun = name;
	 Health = 0;
	 Armor = 0;
	 Alive = false;
	 Bot = false;
	 money = 0;
	 head = nullptr;
	 current = nullptr;
}

player::player(string nameOFplayer_, vector <int>& idOFGun_, vector <string>& nameOFGun_, int Health_, int Armor_, bool Alive_, bool Bot_, int money_, int GunCount_)
{
	ID = generateID();
	nameOFplayer = nameOFplayer_;
	idOFGun = idOFGun_;
	nameOFGun = nameOFGun_;
	Health = Health_;
	Armor = Armor_;
	Alive = Alive_;
	Bot = Bot_;
	money = money_;
	GunCount = GunCount_;
	head = nullptr;
	current = nullptr;
}

//player::player(player& other)
//{
//	ID = generateID();
//	nameOFplayer = other.nameOFplayer;
//	idOFGun = other.idOFGun;
//	nameOFGun = other.nameOFGun;
//	Health = other.Health;
//	Armor = other.Armor;
//	Alive = other.Alive;
//	Bot = other.Bot;
//	money = other.money;
//	head = other.head;
//	current = other.current;
//}

string player::get_ID()
{
	return ID;
}

string player::get_nameOFplayer()
{
	return nameOFplayer;
}

vector <int>& player::get_idOFGun()
{
	return idOFGun;
}

vector <string>& player::get_nameOFGun()
{
	return nameOFGun;
}

int player::get_Health()
{
	return Health;
}

int player::get_Armor()
{
	return Armor;
}

bool player::get_Alive()
{
	return Alive;
}

bool player::get_Bot()
{
	return Bot;
}

int player::get_money()
{
	return money;
}

int player::get_GunCount()
{
	return GunCount;
}

void player::sett_nameOFplayer(string n)
{
	nameOFplayer = n;
}

void player::sett_idOFGun(vector <int>& i)
{
	idOFGun = i;
}

void player::sett_nameOFGun(vector <string>& ng)
{
	nameOFGun = ng;
}

void player::sett_Health(int h)
{
	Health = h;
}

void player::sett_Armor(int a)
{
	Armor = a;
}

void player::sett_Alive(bool a)
{
	Alive = a;
}

void player::sett_Bot(bool b)
{
	Bot = b;
}

void player::sett_money(int m)
{
	money = m;
}

void player::sett_GunCount(int c)
{
	GunCount = c;
}

void player::AddGun(Gun g)
{
	Node* newNode = new Node(g);
	if (head == nullptr)
	{
		head = newNode;
		head->next = head;
		head->prev = head;
		current = head;
	}
	else
	{
		Node* last = head->prev;
		last->next = newNode;
		newNode->prev = last;
		newNode->next = head;
		head->prev = newNode;
	}
}

void player::nextGun()
{
	if (current != nullptr)
	{
		current = current->next;
		cout << "selected : " << current->gun.get_Id() << endl;
	}
}

void player::prevGun()
{
	if (current != nullptr)
	{
		current = current->prev;
		cout << "selected : " << current->gun.get_Id() << endl;
	}
}

Gun player::get_currentGun()
{
	return current->gun;
}

void player::displayGun()
{
	Node* temp = head;
	if (head == nullptr)
	{
		cout << "No Gun available";
		return;
	}
	else
	{
		int i = 1;
		do {
			if (temp == current)
			{
				cout << "     Gun " << i << " : " << temp->gun.get_Id();
				printflash();
				temp = temp->next;
				++i;
				continue;
			}
			cout << "     Gun " << i << " : " << temp->gun.get_Id() << endl;
			temp = temp->next;
			++i;
		} while (temp != head);
	}
}

void player::printflash()
{
	cout << " <-----" << endl;
}

void player::display()
{
	cout << "ID : " << get_ID() << endl;
	cout << "name of player : " << get_nameOFplayer() << endl;
	cout << "id of Gun : " << endl;
	for (int i = 0;GunCount > i;++i)
	{
		cout << "Gun " << i + 1 << " : " << idOFGun[i] << endl;
	}
	cout << "name of Guns : " << endl;
	for (int i = 0;GunCount > i;++i)
	{
		cout << "Gun " << i + 1 << " : " << nameOFGun[i] << endl;
	}
	cout << "Health : " << get_Health() << endl;
	cout << "Armor : " << get_Armor() << endl;
	cout << "Alive : " << get_Alive() << endl;
	cout << "Bot : " << get_Bot() << endl;
	cout << "money : " << get_money() << endl;
}

player& player::operator=(player& other) {
	if (this != &other) {
		
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}

		
		nameOFplayer = other.nameOFplayer;
		idOFGun = other.idOFGun;
		nameOFGun = other.nameOFGun;
		Health = other.Health;
		Armor = other.Armor;
		Alive = other.Alive;
		Bot = other.Bot;
		money = other.money;

		
		head = nullptr;
		current = nullptr;
		Node* temp = other.head;
		while (temp != nullptr) {
			AddGun(temp->gun);
			temp = temp->next;
		}
	}
	return *this;
}

bool player::operator==(player& other)
{
	if (nameOFplayer == other.nameOFplayer &&
		nameOFGun == other.nameOFGun &&
		idOFGun == other.idOFGun &&
		Health == other.Health &&
		Armor == other.Armor &&
		Alive == other.Alive &&
		Bot == other.Bot &&
		money == other.money)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool player::operator!=(player& other)
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

int player::calcutepower()
{
	if (head == nullptr) return money;

	Node* temp = head;
	int power_of_player = 0;
	do {
		Gun current = temp->gun;
		power_of_player += current.get_ammo() * current.get_power();
		temp = temp->next;
	} while (temp != head);

	return money + power_of_player;
}


void player::navigateGuns() {
	if (head == nullptr) {
		cout << "No guns to navigate!" << endl;
		return;
	}
	char input;
	do {
		displayGun();
		cout << "\npress:\n";
		cout << " n : for next Gun." << endl;
		cout << " p : for prev Gun." << endl;
		cout << " q : for exit" << endl;
		cin >> input;
		if (input == 'n') {
			nextGun();
		}
		else if (input == 'p') {
			prevGun();
		}
		system("cls");
	} while (input != 'q');
}

