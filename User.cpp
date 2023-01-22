#include "User.h"

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

inline void User::setLogin(std::string login)
{
    _login = login;
}

inline void User::setPass(std::string pass)
{
    _pass = pass;
}

inline unsigned long long User::getID() const
{
    return _ID;
}

inline std::string User::getLogin() const
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
