#include "Array_Ch.h"


//template<> Array_Ch<Chat>::Array_Ch()
//{
//}

template<> Array_Ch<Chat*>::Array_Ch()
{
}

template<> Array_Ch<Chat*>::~Array_Ch()
{
}

template<> void Array_Ch<Chat>::print()
{
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			_dataPtr[i].printMessage();
		}
	}
}

//специализация функции print для класса Chat* указателей

template<> void Array_Ch<Chat*>::print()
{
	if (_dataPtr)
	{

		for (size_t i = 0; i < _size; i++)
		{
			(*_dataPtr[i]).printMessage(); //message? chat???
		}
	}
};

//функции findID для класса Chat* указателей
template<>
int Array_Ch<Chat*>::findID(Chat* chat)
{
	int ret{ -1 };
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if ((*_dataPtr[i]).getID() == (*chat).getID())
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}




//функции findChatName для класса Chat* указателей
template<>
int Array_Ch<Chat*>::findChatName(Chat* chat)
{
	int ret{ -1 };
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if ((*_dataPtr[i]).getChatName() == (*chat).getChatName())
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}


//функции findChatName для типа string
template<>
int Array_Ch<Chat*>::findChatName(std::string chatName)
{
	int ret{ -1 };
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if ((*_dataPtr[i]).getChatName() == chatName)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

//специализация функции printChatNames для класса Chat* указателей

template<> void Array_Ch<Chat*>::printChatNames()
{
	if (_dataPtr)
	{

		for (size_t i = 0; i < _size; i++)
		{
			(*_dataPtr[i]).printChatName(); // print ID and name of the chat
		}
	}
};

template<>
void Array_Ch<Chat*>::addChat(Chat* chat)
{
	insertElementEnd(chat);
	chat->setID(static_cast<unsigned long long>(getSize()));
}