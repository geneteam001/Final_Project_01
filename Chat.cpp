#include "Chat.h"

Chat::Chat()
{
}

Chat::~Chat()
{
}

void Chat::printMessage()
{
	_messages.print();
}

void Chat::addMessage(Message message)
{
	_messages.insertElementEnd(message);
}