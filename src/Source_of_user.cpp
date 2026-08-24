#include "Header_of_user.h"


user::user()
{
	username = "";
	nickname = "";
	password = "";
}

user::user(string username_, string password_, string nickname_)
{
	username = username_;
	password = password_;
	nickname = nickname_;
}

//user::user(user& other)
//{
//	username = other.username;
//	nickname = other.nickname;
//	password = other.password;
//}

string user::get_username()
{
	return username;
}

string user::get_nickname()
{
	return nickname;
}

string user::get_password()
{
	return password;
}

void user::sett_username(string username_)
{
	username = username_;
}

void user::sett_nickname(string nickname_)
{
	nickname = nickname_;
}

void user::sett_password(string password_)
{
	password = password_;
}
