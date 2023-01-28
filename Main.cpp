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

	Message messageTmp;



	//Создаём временного пользователя
	User userTmp;
	Chat* chatPtr = new Chat;
	Chat& chat = *chatPtr;

	// создаём временного пользователя и добавляем его в конец
	userTmp.setLogin("tmpUserLogin1");
	userTmp.setPass("tmpUserPass1");
	users.insertElementEnd(userTmp);

	while (true)
	{
		std::cout << "insert command" << std::endl;
		std::cin >> cmd;
		try
		{


			switch (cmd)
			{
			case 2: std::cout << "insert your name" << std::endl; //login

				std::cin >> name;
				std::cout << name << endl;
				userTmp.setLogin(name);
				users.print();
				std::cout << users.findElement(userTmp) << std::endl;
				if (users.findElement(userTmp) >= 0)
				{
					std::cout << "loged" << std::endl;

					std::cout << "Hello World must be printed here" << std::endl;
					messageTmp.setMessage("Hello!");
					chatPtr->addMessage(messageTmp);
					chat.printMessage();

					messageTmp.setMessage("World!");
					chatPtr->addMessage(messageTmp);
					chatPtr->printMessage();




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
						users.insertElementEnd(userTmp);
						users.print();
						std::cout << users.findElement(userTmp) << std::endl;

					}
					else if (choice == 'n')
					{

					}
				}


				break;




			default:
				break;
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
	return 0;
}