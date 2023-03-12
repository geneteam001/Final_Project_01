#include "Chat.h"

Chat::Chat()
{
	//Временно для диагностики создания объектов
	std::cout << " Chat Constructed" << std::endl;
}

Chat::Chat(const std::string chatname) :_chatname(chatname)
{
	//Временно для диагностики создания объектов
	std::cout << " Chat Constructed" << _chatname << std::endl;
}


Chat::~Chat()
{
	//Временно для диагностики создания объектов
	std::cout << " Chat Destructed" << _chatname << std::endl;
}

void Chat::setID(unsigned long long ID)
{
	_ID = ID;
}

void Chat::printMessage()
{
	_messages.print();
}

void Chat::addMessage(Message const message)
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