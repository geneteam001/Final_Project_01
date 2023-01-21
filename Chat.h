#pragma once
#include "Array_M.h"
#include "Array_U.h"
//#include "Array_M.h"
//#include "Message.h"
//#include "User.h"
class Chat
{
public:
	Chat();
	~Chat();
	//////void addUser(User& user)
	//////{
	//////	//_users.insertElementBeginning(*user);
	//////	_users.insertElementEnd(&user);
	//////}
	//////void printUsers();




	/*void addMessage(Message message)
	{
		_messages._insertElementEnd(message);
		

	}


	
	void printMessage();*/




protected:

			////здесь массив пользователей именно этого чата
	//////Array<User*> _users;
			////здесь массив сообщений чата
			// 
			// 
			// 
			// 
	Array_M _messages;
	Array_U _uessages;



};

Chat::Chat()
{
}

Chat::~Chat()
{
}

//////void Chat::printUsers()
//////{
//////	_users.print();
//////}

//inline void Chat::printMessage()
//{
//	_messages.print();
//}
