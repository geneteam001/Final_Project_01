#include <time.h>
#include <iostream>
#include "User.h"
#include "Array_U.h"
#include "Message.h"

using namespace std;

int main()
{
	system("chcp 1251");

	//���������� ����������
	bool Q{ false };
	string userName;
	string pass;
	int cmd{0};
	std::string cmd_input;
	char choice;

	//������ ������ ������������� � ��������� �� ���� User - ������������
	Array_U<>* usersPtr = new Array_U<>;
	//�������� ������ �� �������������
	Array_U<>& users = *usersPtr;

	//������ ������ ���������� �� ���� � ��������� �� ���� ������
	Array_Ch<Chat*>* chatsPtr = new Array_Ch<Chat*>;
	Array_Ch<Chat*>& chats = *chatsPtr;

	//���������
	Message messageTmp;

	//������ ���������� ������������
	User userTmp;

	//������ "�������" ������������ � ��������� �� ����
	User* currentUserPtr{ nullptr };

	Chat* currentChatPtr{ nullptr };

	currentChatPtr = new Chat("�����");

	//������ ������������ ��� ������ ����
	userTmp.setID(static_cast<unsigned long long>(users.getSize()) + 1); //��������� ID
	userTmp.setLogin("�����");
	users.insertElementEnd(userTmp);
	//currentUserPtr = &users[users.findElement(userTmp)];

	while (!Q) //����
	{
		//���� ���� ������� ������������ - �� ������������� ���
		if (currentUserPtr)
		{
			std::cout << "�������� ������������: ";
			currentUserPtr->printUser();
		}

		std::cout << "������� �������� (0 - �����)" << std::endl;
		std::cin >> cmd_input;

		//��������� ������������ �����
		try
		{
			cmd = std::stoi(cmd_input);
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
			cmd = 0;
		}

		try //��������� ����������
		{
			switch (cmd)
			{
			case 0:
				std::cout << "0 - ������" << std::endl;
				std::cout << "1 - ������� ������ �������� ������������" << std::endl;
				std::cout << "2 - ��������������" << std::endl;
				std::cout << "3 - �������� ���������" << std::endl;
				std::cout << "8 - ����� �� ������� ������" << std::endl;
				std::cout << "9 - ����� �� ���������" << std::endl;
				std::cout << "��� ������������ ������ �������� �� ������ �����" << std::endl;
				break;

			case 1: //������������� ���� ������������������ �������������,
				if (currentUserPtr) 
				{
					std::cout << "�������� ������������: ";
					currentUserPtr->printUser();
					std::cout << endl;
					std::cout << "���� ��������� ������������: " << std::endl;
					currentUserPtr->printChatNames();

				}
				//������������� ����� ���� ������������������ �������������
				if (users.getSize() > 0)
				{
					std::cout << "������������������ ������������: " << std::endl; //users
					users.print();
					std::cout << endl;
				}
				else
				{
					std::cout << "��� ������������������ �������������! " << std::endl;
				}
				break;
			case 2: // register user (check user)
				if (currentUserPtr) 
				{ 
					std::cout << "�������� ������������: ";
					currentUserPtr->printUser(); 
				}
				if (currentChatPtr)
				{
					std::cout << "�������� ���: ";
					currentChatPtr->printChatName();
				}
				{
					int foundElement{ 0 }; // ��������� ���������� ��� ������� ���������� ������������
					std::cout << "������� ���� ���" << std::endl; //login
					std::cin >> userName;
					std::cout << userName << endl;
					userTmp.setLogin(userName);
					// ���� ������������ � �������� ������� 
					foundElement = users.findElement(userTmp);
					if (foundElement >= 0) //���� ������������ ������
					{
						//���� ������
						std::cout << "������� ������: " << std::endl;
						std::string tmp_pass;
						std::cin >> tmp_pass;
						if (users[foundElement].getPass() == tmp_pass)
						{
							// �������� ��������� �� ���������� ������������
							currentUserPtr = &users[foundElement];
							//������� - ��������� ���...
							std::cout << "�� ����� ���: ";
							currentUserPtr->printUser();
						}
						else
						{
							std::cout << "�� ����� �������� ������: " << std::endl;
						}
					}
					else //���� ������������ �� ������
					{
						std::cout << "��� ������ ������������" << std::endl;
						std::cout << "���������������� ������������ " << userTmp.getLogin() << "? (y/n)" << std::endl;
						std::cin >> choice;
						if (choice == 'y' || choice == 'Y' || choice == '�' || choice == '�') //���������������� ������������ � ��������� �������
						{
							std::cout << "������� ��� ������: " << std::endl;
							std::cin >> pass;

							userTmp.setPass(pass); // ������������� ������
							userTmp.setID(static_cast<unsigned long long>(users.getSize()) + 1); //��������� ID

							users.insertElementEnd(userTmp); //��������� ������������ � ������ �������������

							foundElement = users.findElement(userTmp); //���� ������������ ������������ � ������� 

							currentUserPtr = &users[foundElement]; //�������� ��������� �� ���������� ������������ ������������ � ������ ��� ������� �������������
						}
						else if (choice == 'n')
						{

						}
					}
				}
				break;
			case 3: //�������� ������������
				//������� ��� ��������� ������������ 
				if (currentUserPtr)
				{
					std::cout << "�������� ������������: ";
					currentUserPtr->printUser();

					//������� ����� ���� �������������
					std::cout << "������������������ ������������: " << std::endl;
					users.print();

					{
						int foundElement{ 0 }; //��������� ���������� ��������� �������
						int id;  //��������� ���������� �������������
						std::string id_input;
						std::cout << "�������� ������������ ��� ���� (������� �����) " << std::endl;
						std::cin >> id_input;
						//��������� ������������ �����
						try
						{
							id = std::stoi(id_input);
						}
						catch (exception& except)
						{
							cout << endl << except.what() << endl;
							id = -1;
						}

						//����� ������������ � �������� id
						foundElement = users.findID(id);

						if (foundElement != -1)
						{
							//����� ���������� ������������ ��� ������������ ��������� ���������
							std::cout << "������������ ������: ";
							users[foundElement].printUser();
						}
						else
						{
							std::cout << "��� ������ ������������! " << std::endl;
						}
						
						std::string chatName; //��� ���� ������ ����������
						std::string chatName_2; //��� ���� ������ ����������
						if (currentUserPtr)
						{
							if (users[foundElement].getLogin() == "�����") //��� ������������ - ����� � ��� ���� ����� ���� �����.
							{
								chatName = "�����";
							}
							else
							{
								//������������ ����� ���� ������ �����
								chatName = currentUserPtr->getLogin();
								chatName += users[foundElement].getLogin();
							}
							//������������ ����� ���� ������ �����
							chatName_2 = users[foundElement].getLogin();
							chatName_2 += currentUserPtr->getLogin();
						}

						{
							int indx = chats.findChatName(chatName);
							int indx_2 = chats.findChatName(chatName_2);
							if (!(indx == -1))
							{
								currentChatPtr = chats[indx];
								std::cout << "����� ��� ��� ����������: " << currentChatPtr->getChatName() << std::endl;
								currentChatPtr->printMessage();
							}
							else if (!(indx_2 == -1))
							{
								currentChatPtr = chats[indx_2];
								std::cout << "����� ��� ��� ����������: " << currentChatPtr->getChatName() << std::endl;
								currentChatPtr->printMessage();
							}
							else //���� ������ ���� ��� - ������ ��� � ��������� ��������� �� ���� � ������ ����� ������� ������������
							{
								currentChatPtr = new Chat(chatName);
								chats.addChat(currentChatPtr);
								currentUserPtr->addChat(currentChatPtr); // ��������� ��� � �������� ������������
								if (currentUserPtr->getLogin() != users[foundElement].getLogin()) // ���� ���������� �� ��� ������� ������������
								{
									users[foundElement].addChat(currentChatPtr); // ��������� ��� � ������������ �����������
								}
							}

							//������� ���������
							{
								// ��������� ���������
								std::string tmpString;
								std::cout << "������� ���� ���������: "; //<< std::endl;
								cin.ignore();
								std::getline(std::cin, tmpString);

								// ������� ����/����� ����������� �� ������� �������
								time_t now = time(0);
								// ����������� now � ������ string
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
								currentChatPtr->printMessage(); // ����������� ��� ������
								std::cout << endl;
							}
						}
					}
				}
				else
				{
					std::cout << "�� �� ����������������! " << std::endl;
					}
				break;
			case 8: // logoff
				if (currentUserPtr)
				{
					std::cout << "�� ����� �� ������� ������";
					currentUserPtr->printUser();
					std::cout << std::endl;
					currentUserPtr = nullptr;
				}
				else
				{
					std::cout << "������ ��� ����� �� ������� ������ ���������� � �� �����. �� �� ����� � ������ ������." << std::endl;
				}
				break;
			case 9: //����� �� ���������
				Q = true;
				break;
			default:
				std::cout << "��� ����� �������: " << cmd << std::endl;
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