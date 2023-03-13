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

void User::setLogin(const std::string login)
{
    _login = login;
}

void User::setPass(const std::string pass)
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
    std::cout << " " << _ID;
    std::cout << " " << _login << std::endl; /*Login:*/
}

void User::addChat(Chat* chat)
{
    _chats.insertElementEnd(chat);
    _readPos.insertElementEnd(_chats.getSize());
}

void User::printChat(Chat* chat)
{
    _chats.print();
}

void User::printChatNames()
{
    _chats.printChatNames();
}




