#pragma once
#include "Array.h"
#include "Message.h"
//#include "User.h"
class Chat
{
public:
	Chat();
	~Chat();
	void addUser(User& user)
	{
		//_users.insertElementBeginning(*user);
		_users.insertElementEnd(&user);
	}
	void printUsers();
private:

	////здесь массив пользователей именно этого чата
	Array<User*> _users;
	////здесь массив сообщений чата
	Array<Message> _messages;




};

Chat::Chat()
{
}

Chat::~Chat()
{
}

void Chat::printUsers()
{
	_users.print();
}
