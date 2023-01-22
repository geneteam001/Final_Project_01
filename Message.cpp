//#pragma once
#include "Message.h"

Message::Message()
{
}
Message::~Message()
{
}
void Message::setMessage(std::string message)
{
	_message = message;
}

std::string Message::getMessage() const
{
	return std::string();
}

void Message::printMessage()
{
}
