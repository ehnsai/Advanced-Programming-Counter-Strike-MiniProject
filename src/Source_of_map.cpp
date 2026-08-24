#include "Header_of_map.h"

map::map()
{
	nameOFdesigner = "default";
	nameOFmap = "map";
	night = false;
	snow = false;
}

map::map(string nm, string nd, bool n,bool s)
{
	nameOFmap = nm;
	nameOFdesigner = nd;
	night = n;
	snow = s;
}

//map::map(map& other)
//{
//	nameOFmap = other.nameOFmap;
//	nameOFdesigner = other.nameOFdesigner;
//	night = other.night;
//}

map& map::operator=(map& other)
{
	nameOFmap = other.nameOFmap;
	nameOFdesigner = other.nameOFdesigner;
	night = other.night;
	return *this;
}

bool map::operator==(map& other)
{
	if (nameOFmap == other.nameOFmap &&
		nameOFdesigner == other.nameOFdesigner &&
		night == other.night)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool map::operator!=(map& other)
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

string map::get_nameOFmap()
{
	return nameOFmap;
}

string map::get_nameOFdesigner()
{
	return nameOFdesigner;
}

bool map::get_night()
{
	return night;
}

bool map::get_snow()
{
	return snow;
}

void map::sett_nameOFdesigner(string n)
{
	nameOFdesigner = n;
}

void map::sett_nameOFmap(string n)
{
	nameOFmap = n;
}

void map::sett_night(bool n)
{
	night = n;
}

void map::sett_snow(bool s)
{
	snow = s;
}
