#pragma once

#include "Array_Ch.h"

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
	
	Array_Ch<> _chats;
	

};


