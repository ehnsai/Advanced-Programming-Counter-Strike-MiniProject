#include "Header_of_gamemanager.h"
#include <thread>
#include <chrono>
#include <Windows.h>


#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

gamemanager* gamemanager::ins = nullptr;

gamemanager* gamemanager::get_ins()
{
	if (ins == nullptr)
	{
		ins = new gamemanager();
	}
	return ins;
}

void gamemanager::sett_vec_ct(vector <ct> v)
{
	vec_ct = v;
}

void gamemanager::sett_vec_terrorist(vector <terrorist> v)
{
	vec_terrorist = v;
}

int gamemanager::get_resualt()
{
	return resualt;
}

void gamemanager::sett_resualt(int t)
{
	resualt = t;
}

vector<ct>& gamemanager::get_vecct()
{
	return vec_ct;
}

vector<terrorist>& gamemanager::get_t()
{
	return vec_terrorist;
}

map gamemanager::get_map()
{
	return map_of_game;
}

void gamemanager::sett_map_of_game(map m)
{
	map_of_game = m;
}

void gamemanager::startfight()
{
	cout << "\n\nMap of game : " << map_of_game.get_nameOFmap();
	if (map_of_game.get_snow())
	{
		cout << "\t\t\t\tMap is snowy";
	}
	else
	{
		cout << "\t\t\tMap is sunny";
	}
	if (map_of_game.get_night())
	{
		cout << "\t\t\tNight\n\n";
	}
	else
	{
		cout << "\t\t\tMorning\n\n";
	}
	int ct_ptr = 0;
	int terrorist_ptr = 0;
	bool endgame = false;
	while (!endgame)
	{
		while (vec_ct.size() > ct_ptr && vec_terrorist.size() > terrorist_ptr)
		{
			ct& current_ct = vec_ct[ct_ptr];
			terrorist& current_t = vec_terrorist[terrorist_ptr];
			if (!current_ct.get_Alive())
			{
				ct_ptr++;
				continue;
			}
			if (!current_t.get_Alive())
			{
				terrorist_ptr++;
				continue;
			}
			int ct_power = current_ct.calcutepower();
			int t_power = current_t.calcutepower();
			if (ct_power > t_power)
			{
				int damage = ct_power - t_power;
				damage = calcute_damage(damage, map_of_game.get_night(), map_of_game.get_snow());
				current_t.sett_Health(current_t.get_Health() - damage);

				cout << "\n\n\t\t\t\t\t" << BLUE << current_ct.get_nameOFplayer() << RESET << " damaged "
					<< RED << current_t.get_nameOFplayer() << RESET << endl;

				if (current_t.get_Health() <= 0)
				{
					current_t.sett_Alive(false);
					cout << "\n\n\t\t\t\t\t" << BLUE << current_ct.get_nameOFplayer() << RESET << " Killed "
						<< RED << current_t.get_nameOFplayer() << RESET << endl;
					terrorist_ptr++;
				}
			}
			else if (t_power > ct_power)
			{
				int damage = t_power - ct_power;
				damage = calcute_damage(damage, map_of_game.get_night(), map_of_game.get_snow());
				current_ct.sett_Health(current_ct.get_Health() - damage);

				cout << "\n\n\t\t\t\t\t" << RED <<  current_t.get_nameOFplayer() << RESET << " damaged "
					<< BLUE << current_ct.get_nameOFplayer() << RESET << endl;

				if (current_ct.get_Health() <= 0)
				{
					current_ct.sett_Alive(false);
					cout << "\n\n\t\t\t\t\t" << RED << current_t.get_nameOFplayer() << RESET << " Killed "
						<< BLUE << current_ct.get_nameOFplayer() << RESET << endl;
					ct_ptr++;
				}
			}
			else if (t_power == ct_power)
			{
				int damage = t_power;
				damage = calcute_damage(damage, map_of_game.get_night(), map_of_game.get_snow());
				current_ct.sett_Health(current_ct.get_Health() - damage);
				current_t.sett_Health(current_t.get_Health() - damage);

				cout << "\n\n\t\t\t\t\t" << BLUE << current_ct.get_nameOFplayer() << RESET << " and "
					<< RED << current_t.get_nameOFplayer() << RESET << "damaged each other. " << endl;

				if (current_ct.get_Health() <= 0)
				{
					current_ct.sett_Alive(false);
					cout << "\n\n\t\t\t\t\t" << RED << current_t.get_nameOFplayer() << RESET << " Killed "
						<< BLUE << current_ct.get_nameOFplayer() << RESET << endl;
					ct_ptr++;
				}
				else
				{
					ct_ptr++;
				}
				if (current_t.get_Health() <= 0)
				{
					current_t.sett_Alive(false);
					cout << "\n\n\t\t\t\t\t" << BLUE << current_ct.get_nameOFplayer() << RESET << " Killed "
						<< RED << current_t.get_nameOFplayer() << RESET << endl;
					terrorist_ptr++;
				}
				else
				{
					terrorist_ptr++;
				}
			}
			/*this_thread::sleep_for(chrono::milliseconds(500));*/
			Sleep(500);
		}
		bool ctAlive = false;
		for (int i = 0;vec_ct.size() > i;++i)
		{
			if (vec_ct[i].get_Alive() == true) 
			{
				ctAlive = true;
				break;
			}
		}
		bool tAlive = false;
		for (int i = 0;vec_terrorist.size() > i;++i)
		{
			if (vec_terrorist[i].get_Alive() == true)
			{
				tAlive = true;
				break;
			}
		}
		if (ctAlive && tAlive)
		{
			ct_ptr = 0;
			terrorist_ptr = 0;
			cout << "----- Next Round Starts -----" << endl;
		}
		else if(ctAlive && !tAlive)
		{
			endgame = true;
			cout << BLUE << "\n\t\t\t\t\tCt win!" << RESET << endl;
			resualt = 1;
		}
		else if (!ctAlive && tAlive)
		{
			endgame = true;
			cout << RED << "\n\t\t\t\t\tTerrorists win!" << RESET << endl;
			resualt = 2;
		}
		else
		{
			endgame = true;
			cout << "\n\t\t\t\t\tIt's a Draw!" << endl;
			resualt = 0;
		}
	}
}

void gamemanager::reset()
{
	vec_ct.clear();
	vec_terrorist.clear();
	resualt = -1;
}

int gamemanager::calcute_damage(int fdamage,bool night_, bool snowy_)
{
	if (night_ && snowy_)
	{
		return 0.7 * fdamage;
	}
	else if(night_ && !snowy_)
	{
		return 0.8 * fdamage;
	}
	else if (!night_ && snowy_)
	{
		return 0.9 * fdamage;
	}
	else
	{
		return fdamage;
	}
}
