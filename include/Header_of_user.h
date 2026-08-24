#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class user 
{
private:
	string username;
	string password;
	string nickname;
public:
	user();
	user(string username_, string password_, string nickname_);
	//user(user& other);
	string get_username();
	string get_nickname();
	string get_password();
	void sett_username(string username_);
	void sett_nickname(string nickname_);
	void sett_password(string password_);
};

#endif
