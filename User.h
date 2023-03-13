#pragma once

#include "Array_Ch.h"

class User
{
public:
	User();
	User(std::string);
	~User();
	void setID(unsigned long long);
	void setLogin(std::string);
	void setPass(std::string);
	unsigned long long getID() const;
	std::string getLogin() const;
	std::string getPass() const;
	void printUser();
	void addChat(Chat* chat);
	void printChat(Chat* chat);
	void printChatNames();
private:
	std::string _login;
	std::string _pass;
	unsigned long long _ID {0};

	Array_Ch<Chat*> _chats;
	Array<int> _readPos; // array of chats read positions

};


