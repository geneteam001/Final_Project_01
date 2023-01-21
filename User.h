#pragma once

#include <string>
//#include "Chat.h"
//using namespace std;

class User
{
public:
	User();
	~User();
	void setID(unsigned long long);
	void setLogin(std::string);
	void setPass(std::string);
	unsigned long long getID() const;
	std::string getLogin() const;
	std::string getPass() const;
	void printUser();
private:
	std::string _login;
	std::string _pass;
	unsigned long long _ID {0};
	
	//Array<Chat*> _chats;
	

};

//User::User()
//{
//}
//
//User::~User()
//{
//}
//
//inline void User::setID(unsigned long long ID)
//{
//	_ID = ID;
//}
//
//
//
//void User::setLogin(string login)
//{
//	_login = login;
//}
//
//void User::setPass(string pass)
//{
//	_pass = pass;
//}
//
//inline unsigned long long User::getID() const
//{
//	return _ID;
//}
//
//
//
//inline string User::getLogin() const
//{
//	return _login;
//}
//
//inline string User::getPass() const
//{
//	return (_pass);
//}
//
//inline void User::printUser()
//{
//	std::cout << " Login: " << _login << std::endl;
//	std::cout << " Pass: " << _pass << std::endl;
//}
