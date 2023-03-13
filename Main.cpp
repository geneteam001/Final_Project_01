#include <time.h>
#include <iostream>
#include "User.h"
#include "Array_U.h"
#include "Message.h"

using namespace std;

int main()
{
	system("chcp 1251");

	//глобальные переменные
	bool Q{ false };
	string userName;
	string pass;
	int cmd{0};
	std::string cmd_input;
	char choice;

	//создаём массив пользователей и указатель на него User - пользователи
	Array_U<>* usersPtr = new Array_U<>;
	//Получаем ссылку на пользователей
	Array_U<>& users = *usersPtr;

	//создаём массив указателей на чаты и указатель на этот массив
	Array_Ch<Chat*>* chatsPtr = new Array_Ch<Chat*>;
	Array_Ch<Chat*>& chats = *chatsPtr;

	//сообщение
	Message messageTmp;

	//Создаём временного пользователя
	User userTmp;

	//создаём "пустого" пользователя и указатель на него
	User* currentUserPtr{ nullptr };

	Chat* currentChatPtr{ nullptr };

	currentChatPtr = new Chat("Общий");

	//создаём пользователя для общего чата
	userTmp.setID(static_cast<unsigned long long>(users.getSize()) + 1); //формируем ID
	userTmp.setLogin("Общий");
	users.insertElementEnd(userTmp);
	//currentUserPtr = &users[users.findElement(userTmp)];

	while (!Q) //цикл
	{
		//если есть текущий пользователь - то распечатываем его
		if (currentUserPtr)
		{
			std::cout << "Активный пользователь: ";
			currentUserPtr->printUser();
		}

		std::cout << "Введите комманду (0 - помощ)" << std::endl;
		std::cin >> cmd_input;

		//проверяем корректность ввода
		try
		{
			cmd = std::stoi(cmd_input);
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
			cmd = 0;
		}

		try //обработка исключений
		{
			switch (cmd)
			{
			case 0:
				std::cout << "0 - помощь" << std::endl;
				std::cout << "1 - вывести данные текущего пользователя" << std::endl;
				std::cout << "2 - авторизоваться" << std::endl;
				std::cout << "3 - написать сообщение" << std::endl;
				std::cout << "8 - выйти из учётной записи" << std::endl;
				std::cout << "9 - выйти из программы" << std::endl;
				std::cout << "Имя пользователя должно состоять из одного слова" << std::endl;
				break;

			case 1: //распечатываем всех зарегистрированных пользователей,
				if (currentUserPtr) 
				{
					std::cout << "Активный пользователь: ";
					currentUserPtr->printUser();
					std::cout << endl;
					std::cout << "Чаты активного пользователя: " << std::endl;
					currentUserPtr->printChatNames();

				}
				//распечатываем имена всех зарегистрированных пользователей
				if (users.getSize() > 0)
				{
					std::cout << "Зарегистрированные пользователи: " << std::endl; //users
					users.print();
					std::cout << endl;
				}
				else
				{
					std::cout << "Нет зарегистрированных пользователей! " << std::endl;
				}
				break;
			case 2: // register user (check user)
				if (currentUserPtr) 
				{ 
					std::cout << "Активный пользователь: ";
					currentUserPtr->printUser(); 
				}
				if (currentChatPtr)
				{
					std::cout << "Активный чат: ";
					currentChatPtr->printChatName();
				}
				{
					int foundElement{ 0 }; // временная переменная для индекса найденного пользователя
					std::cout << "Введите ваше имя" << std::endl; //login
					std::cin >> userName;
					std::cout << userName << endl;
					userTmp.setLogin(userName);
					// ищем пользователя с заданным логином 
					foundElement = users.findElement(userTmp);
					if (foundElement >= 0) //если пользователь найден
					{
						//ввод пароля
						std::cout << "Введите пароль: " << std::endl;
						std::string tmp_pass;
						std::cin >> tmp_pass;
						if (users[foundElement].getPass() == tmp_pass)
						{
							// получаем указатель на найденного пользователя
							currentUserPtr = &users[foundElement];
							//выводим - залогинен как...
							std::cout << "Вы вошли как: ";
							currentUserPtr->printUser();
						}
						else
						{
							std::cout << "Вы ввели неверный пароль: " << std::endl;
						}
					}
					else //если пользователь не найден
					{
						std::cout << "Нет такого пользователя" << std::endl;
						std::cout << "Зарегистрировать пользователя " << userTmp.getLogin() << "? (y/n)" << std::endl;
						std::cin >> choice;
						if (choice == 'y' || choice == 'Y' || choice == 'н' || choice == 'Н') //зарегистрировать пользователя с указанным логином
						{
							std::cout << "Введите ваш пароль: " << std::endl;
							std::cin >> pass;

							userTmp.setPass(pass); // устанавливаем пароль
							userTmp.setID(static_cast<unsigned long long>(users.getSize()) + 1); //формируем ID

							users.insertElementEnd(userTmp); //добавляем пользователя в массив пользователей

							foundElement = users.findElement(userTmp); //ищем добавленного пользователя в массиве 

							currentUserPtr = &users[foundElement]; //получаем указатель на найденного добавленного пользователя и делаем его текущим пользователем
						}
						else if (choice == 'n')
						{

						}
					}
				}
				break;
			case 3: //Написать пользователю
				//Выводим имя активного пользователя 
				if (currentUserPtr)
				{
					std::cout << "Активный пользователь: ";
					currentUserPtr->printUser();

					//выводим имена всех пользователей
					std::cout << "Зарегистрированные пользователи: " << std::endl;
					users.print();

					{
						int foundElement{ 0 }; //временная переменная найденный элемент
						int id;  //временная переменная идентификатор
						std::string id_input;
						std::cout << "Выберите пользователя для чата (введите номер) " << std::endl;
						std::cin >> id_input;
						//проверяем корректность ввода
						try
						{
							id = std::stoi(id_input);
						}
						catch (exception& except)
						{
							cout << endl << except.what() << endl;
							id = -1;
						}

						//поиск пользователя с заданным id
						foundElement = users.findID(id);

						if (foundElement != -1)
						{
							//вывод найденного пользователя для отслеживания поведения программы
							std::cout << "Пользователь найден: ";
							users[foundElement].printUser();
						}
						else
						{
							std::cout << "Нет такого пользователя! " << std::endl;
						}
						
						std::string chatName; //имя чата первая комбинация
						std::string chatName_2; //имя чата вторая комбинация
						if (currentUserPtr)
						{
							if (users[foundElement].getLogin() == "Общий") //имя пользователя - Общий и имя чата задаём тоже Общий.
							{
								chatName = "Общий";
							}
							else
							{
								//формирования имени чата первая часть
								chatName = currentUserPtr->getLogin();
								chatName += users[foundElement].getLogin();
							}
							//формирования имени чата вторая часть
							chatName_2 = users[foundElement].getLogin();
							chatName_2 += currentUserPtr->getLogin();
						}

						{
							int indx = chats.findChatName(chatName);
							int indx_2 = chats.findChatName(chatName_2);
							if (!(indx == -1))
							{
								currentChatPtr = chats[indx];
								std::cout << "Такой чат уже существует: " << currentChatPtr->getChatName() << std::endl;
								currentChatPtr->printMessage();
							}
							else if (!(indx_2 == -1))
							{
								currentChatPtr = chats[indx_2];
								std::cout << "Такой чат уже существует: " << currentChatPtr->getChatName() << std::endl;
								currentChatPtr->printMessage();
							}
							else //если такого чата нет - создаём чат и добавляем указатели на него в список чатов каждого пользователя
							{
								currentChatPtr = new Chat(chatName);
								chats.addChat(currentChatPtr);
								currentUserPtr->addChat(currentChatPtr); // добавляем чат в текущего пользователя
								if (currentUserPtr->getLogin() != users[foundElement].getLogin()) // если собеседник не сам текущий пользователь
								{
									users[foundElement].addChat(currentChatPtr); // добавляем чат в пользователя собеседника
								}
							}

							//послать сообщение
							{
								// формируем сообщение
								std::string tmpString;
								std::cout << "Введите ваше сообщение: "; //<< std::endl;
								cin.ignore();
								std::getline(std::cin, tmpString);

								// текущие дата/время основываясь на текущей системе
								time_t now = time(0);
								// преобразуем now в формат string
								char dt[26];
								ctime_s(dt, sizeof dt, &now);
								std::string str = dt;
								Message currentMessage;
								currentMessage.setMessage(tmpString);
								currentMessage.setTimeSend(str);
								if (currentUserPtr)
								{
									currentMessage.userName(currentUserPtr->getLogin());
								}
								currentChatPtr->addMessage(currentMessage);
								currentChatPtr->printMessage(); // закоментить или убрать
								std::cout << endl;
							}
						}
					}
				}
				else
				{
					std::cout << "Вы не зарегистрированы! " << std::endl;
					}
				break;
			case 8: // logoff
				if (currentUserPtr)
				{
					std::cout << "Вы вышли из учётной записи";
					currentUserPtr->printUser();
					std::cout << std::endl;
					currentUserPtr = nullptr;
				}
				else
				{
					std::cout << "Прежде чем выйти из учётной записи необходимо в неё войти. Вы не вошли в учётую запись." << std::endl;
				}
				break;
			case 9: //Выход из программы
				Q = true;
				break;
			default:
				std::cout << "Нет такой команды: " << cmd << std::endl;
				break;
			}
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}

	}
	delete currentUserPtr;
	delete currentChatPtr;
	delete chatsPtr;
	delete usersPtr;
	return 0;
}