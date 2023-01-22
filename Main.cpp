#pragma once
//#include "Chat.h"

#include <time.h>
#include <chrono>
#include <windows.h>
#include <string>

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

	//Создаём временного пользователя
	User userTmp;
	//////////////////////////////////////////Array<User> Usersvvv;
	////////////////////////////////////////userTmp.setLogin("tmpUserLogin");
	////////////////////////////////////////userTmp.setPass("tmpUserPass");


	////////////////////////////////////////users.setNewSize(3);
	////////////////////////////////////////users.insertElementBeginning(userTmp);

	//////////////////////////////////////////для пробы выводим пароль пользователя добавленного в начало
	////////////////////////////////////////cout << "Pass: " << users[0].getPass() << endl;


	//////////////////////////////////////////users.insertElement(1, userTmp);

	//Раскоментить!!!
	//создаём чат
	//Chat* chat = new Chat;

	//////////////////////////////////////cout << " print chat users here :" << endl;
	//////////////////////////////////////chat->printUsers();
	//////////////////////////////////////cout << endl << endl;

	//////////////////////////////////////// создаём временного пользователя и добавляем его в конец
	//////////////////////////////////////userTmp.setLogin("tmpUserLogin1");
	//////////////////////////////////////userTmp.setPass("tmpUserPass1");
	//////////////////////////////////////users.insertElementEnd(userTmp);

	//////////////////////////////////////// ищем нужного пользователя в пользователях и добавляем его в чат первым
	//////////////////////////////////////chat->addUser(users[usersPtr->findElement(userTmp)]);
	//////////////////////////////////////chat->addUser(users[0]);

	////////////////////////////////////////меняем пароль пользователю 0 через использование ссылки и проверяем, что пароль изменился 
	//////////////////////////////////////users[0].setPass("PassChanged");
	//////////////////////////////////////cout << "user 0 password: " << users[0].getPass() << endl;

	////////////////////////////////////////распечатываем пользователей чата
	//////////////////////////////////////cout << " print chat ussers here :" << endl;
	//////////////////////////////////////chat->printUsers();

	////////////////////////////////////////for pause
	////////////////////////////////////////int tmp_int;
	////////////////////////////////////////cin >> tmp_int;
	////////////////////////////////////////cout << tmp_int << endl;
	////////////////////////////////////////end for pause

	//////////////////////////////////////chat->addUser(users[0]);


	while (true)
	{
		std::cout << "insert command" << std::endl;
		std::cin >> cmd;
		try
		{


			switch (cmd)
			{
			//case 2: std::cout << "insert your name" << std::endl; //login

			//	std::cin >> name;
			//	std::cout << name << endl;
			//	userTmp.setLogin(name);
			//	users.print();
			//	std::cout << users.findElement(userTmp) << std::endl;
			//	if (users.findElement(userTmp) >= 0)
			//		std::cout << "loged" << std::endl;
			//	else
			//		std::cout << "No such user" << std::endl;
			//	std::cout << "register user " << userTmp.getLogin() << "? (y/n)" << std::endl;
			//	std::cin >> choice;
			//	if (choice == 'y')

			//	{
			//		std::cout << "insert your password:" << std::endl;
			//		std::cin >> pass;
			//		userTmp.setPass(pass);
			//		users.insertElementEnd(userTmp);
			//		users.print();
			//		std::cout << users.findElement(userTmp) << std::endl;

			//	}

			//	else if (choice == 'n')
			//		;

			//	break;




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

		Message messageTmp;
		messageTmp.setMessage("Hello!");
		/*chat->addMessage(messageTmp);
		chat->printMessage();

		messageTmp.setMessage("World!");
		chat->addMessage(messageTmp);
		chat->printMessage();*/



	}
	return 0;
}