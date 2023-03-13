//#pragma once
#include "Message.h"
#include <iostream>

Message::Message()
{
}
Message::~Message()
{
}
void Message::userName(const std::string userName)
{
	_userName = userName;
}
void Message::setMessage(const std::string message)
{
	_message = message;
}

void Message::setTimeSend(const std::string time)
{
	_timeSend = time;
}

std::string Message::getMessage() const
{
	return std::string();
}

void Message::printMessage()
{
	std::cout << _timeSend << _userName << ": " << _message << std::endl;
}
