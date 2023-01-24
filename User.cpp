#include "User.h"

User::User()
{
}

User::~User()
{
}

void User::setID(unsigned long long ID)
{
	_ID = ID;
}

void User::setLogin(std::string login)
{
    _login = login;
}

void User::setPass(std::string pass)
{
    _pass = pass;
}

unsigned long long User::getID() const
{
    return _ID;
}

std::string User::getLogin() const
{
   return _login;
}

std::string User::getPass() const
{
    return (_pass);
}

void User::printUser()
{
    std::cout << " Login: " << _login << std::endl;
    std::cout << " Pass: " << _pass << std::endl;
}

void User::addChat(Chat* chat)
{
    _chats.insertElementEnd(chat);
}

void User::printChat(Chat* chat)
{
    _chats.print();
}





