#pragma once
#include <string>
using namespace std;

class User
{
public:
	User();
	~User();
	void setID(unsigned long long);
	void setLogin(string);
	void setPass(string);
	unsigned long long getID() const;
	string getLogin() const;
	string getPass() const;
private:
	string _login;
	string _pass;
	unsigned long long _ID {0};
	
};

User::User()
{
}

User::~User()
{
}

inline void User::setID(unsigned long long ID)
{
	_ID = ID;
}



void User::setLogin(string login)
{
	_login = login;
}

void User::setPass(string pass)
{
	_pass = pass;
}

inline unsigned long long User::getID() const
{
	return _ID;
}



inline string User::getLogin() const
{
	return _login;
}

inline string User::getPass() const
{
	return (_pass);
}


