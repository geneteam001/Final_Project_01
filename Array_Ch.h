#pragma once
#include "Array.h"
#include "Chat.h"


template <typename T = Chat> class Array_Ch : public Array<T>
{
public:
	Array_Ch();
	~Array_Ch();
	void print();
	
	int findID(T);
	int findChatName(T);
	int findChatName(std::string const);
	void printChatNames();
	void addChat(T chat);
private:



};
