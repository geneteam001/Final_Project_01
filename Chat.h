#pragma once

#include "Array_M.h"

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


	//void printUsers();
	virtual void printMessage();

	void addMessage(Message message);
	


	
	




protected:

			////здесь массив пользователей именно этого чата
	//Array_U<User*> _users;
			////здесь массив сообщений чата
			// 
			// 
			// 
			// 

	Array_M<Message> _messages;



};



//void Chat::printUsers()
//{
//	_users.print();
//}
//
//inline void Chat::printMessage()
//{
//	_messages.print();
//}
