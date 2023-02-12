#pragma once

#include "Array_M.h"

class Chat
{
public:
	Chat();
	Chat(std::string chatname);
	~Chat();
	void setID(unsigned long long);
	virtual void printMessage();
	void addMessage(Message message);
	unsigned long long getID() const;
	void printChatName();
protected:
	std::string _chatname;
	unsigned long long _ID{ 0 };
	Array_M<Message> _messages;

};
