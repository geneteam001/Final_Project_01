#include "Chat.h"

Chat::Chat()
{
}

Chat::Chat(std::string chatname) :_chatname(chatname)
{
}


Chat::~Chat()
{
}

void Chat::setID(unsigned long long ID)
{
	_ID = ID;
}

void Chat::printMessage()
{
	_messages.print();
}

void Chat::addMessage(Message message)
{
	_messages.insertElementEnd(message);
}

unsigned long long Chat::getID() const
{
	return _ID;
}

void Chat::printChatName()
{
	std::cout << " " << _ID;
	std::cout << " " << _chatname << std::endl; /*Login:*/
	//std::cout << " Pass: " << _pass << std::endl;
}


std::string Chat::getChatName() const
{
	return _chatname;
}