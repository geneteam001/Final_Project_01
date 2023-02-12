//#pragma once

//#include <time.h>
//#include <chrono>
//#include <windows.h>



#include <iostream>
//#include <string>

#include "User.h"
#include "Array_U.h"
#include "Message.h"

using namespace std;

int main()
{
	string name;
	string pass;
	int cmd;
	char choice;




	//Вызываем конструктор Array для типа User - пользователи
	Array_U<>* usersPtr = new Array_U<>;
	//Получаем ссылку на пользователей
	Array_U<>& users = *usersPtr;

	Array_Ch<Chat*>* chatsPtr = new Array_Ch<Chat*>;
	Array_Ch<Chat*>& chats = *chatsPtr;

	Message messageTmp;



	//Создаём временного пользователя
	User userTmp;
	User* currentUserPtr{nullptr};

	Chat* chatPtr = new Chat;
	Chat& chat = *chatPtr;

	// создаём временного пользователя и добавляем его в конец
	//userTmp.setLogin("tmpUserLogin1");
	//userTmp.setPass("tmpUserPass1");
	//users.insertElementEnd(userTmp);




	while (true)
	{
			if (currentUserPtr) {currentUserPtr->printUser();}
		std::cout << "insert command" << std::endl;
		std::cin >> cmd;
		try
		{


			switch (cmd)
			{
			case 1: 
				if (currentUserPtr) { currentUserPtr->printUser(); }
				std::cout << "Registered users in chat" << std::endl; //users
				users.print();
				break;
			case 2:
				if (currentUserPtr) { currentUserPtr->printUser(); }
			{
				int foundElement{ 0 };
				std::cout << "insert your name" << std::endl; //login
				std::cin >> name;
				std::cout << name << endl;
				userTmp.setLogin(name);

				foundElement = users.findElement(userTmp);
				//std::cout << foundElement << std::endl;
				if (foundElement >= 0)
				{
					User& currentUser = users[foundElement];
					//User& currentUser = *currentUserPtr;
					currentUserPtr = &currentUser;
					std::cout << "logged in as: ";
					currentUser.printUser();

					std::cout << "Hello World must be printed here" << std::endl;
					messageTmp.setMessage("Hello!");
					chat.addMessage(messageTmp);
					//chat.printMessage();

					messageTmp.setMessage("World!");
					chat.addMessage(messageTmp);
					//chat.printMessage();



					//пробно создаём чат для пользователя с индексом 0
					try
					{
						users[0].addChat(chatPtr);
						std::cout << "print chat here" << std::endl;
						users[0].printChat(chatPtr);
						std::cout << "end print chat here" << std::endl;
					}

					catch (exception& except)
					{
						cout << endl << except.what() << endl;
					}




				}
				else
				{
					std::cout << "No such user" << std::endl;
					std::cout << "register user " << userTmp.getLogin() << "? (y/n)" << std::endl;
					std::cin >> choice;
					if (choice == 'y')
					{
						std::cout << "insert your password:" << std::endl;
						std::cin >> pass;
						userTmp.setPass(pass);
						userTmp.setID(static_cast<unsigned long long>(users.getSize()) + 1);
						users.insertElementEnd(userTmp);
						users.print();
						std::cout << users.findElement(userTmp) << std::endl;
						foundElement = users.findElement(userTmp);
						User& currentUser = users[foundElement];
						currentUserPtr = &currentUser;
					}
					else if (choice == 'n')
					{

					}
				}


				break;
			}

			case 3: //Write to user
				if (currentUserPtr) { currentUserPtr->printUser(); }
			{
				int foundElement{ 0 };
				int id;
				std::cout << "Select user" << std::endl; //login
				std::cin >> id;
				userTmp.setID(id);
				foundElement = users.findID(userTmp);
				users[foundElement].printUser();
				std::string str;
				str = currentUserPtr->getLogin();
				str += users[foundElement].getLogin();
				cout << str << std::endl;


				{
					Chat* tmpChatPtr = new Chat(str);
					chats.addChat(tmpChatPtr);
					currentUserPtr->addChat(tmpChatPtr);
					users[foundElement]. addChat(tmpChatPtr);
				}
				currentUserPtr->printChatNames();
				//get chat must be here!?
				//userTmp.addChat(currentUserPtr.)
			}
			default:
				;
			}
			
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}


		// current date/time based on current system
	//	time_t now = time(0);


	//Далее получение времени от Windows - для справки 
		/*			SYSTEMTIME st, lt;

					GetSystemTime(&st);
					GetLocalTime(&lt);

					printf("The system time is: %02d:%02d\n", st.wHour, st.wMinute);
					printf(" The local time is: %02d:%02d\n", lt.wHour, lt.wMinute);*/

	}


	//Не забыть поудалять тут все указатели и другую дребедень

	return 0;
}