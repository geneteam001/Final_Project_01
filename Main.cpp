//#include "Array.h"
#include "Chat.h"
//#include "User.h"

int main()
{

	//Вызываем конструктор Array для типа User - пользователи
	Array<User>* usersPtr = new Array<User>();
	//Получаем ссылку на пользователей
	Array<User>& users = *usersPtr;

	//Создаём временного пользователя
	User userTmp;
				//Array<User> Usersvvv;
	userTmp.setLogin("tmpUserLogin");
	userTmp.setPass("tmpUserPass");


	users.setNewSize(3);
	users.insertElementBeginning(userTmp);

	//для пробы выводим пароль пользователя добавленного в начало
	cout << "Pass: " << users[0].getPass() << endl;


	//users.insertElement(1, userTmp);


	//создаём чат
	Chat* chat = new Chat;




	//std::cout << "input login: " << endl;
	//string tmplogin;
	//cin >> tmplogin;


	//users.insertElement(1, userTmp);
	//users.print();
	//cout << "user 1" << users[1].getLogin() << endl;
	//cout << "user no: " << users.findElement(userTmp) << endl;

	////////try
	////////{
	////////	chat->addUser(new User(userTmp));
	////////	chat->addUser((*usersPtr)[users.findElement(userTmp)]);
	////////	chat->addUser(users[0]);
	////////}
	////////catch (exception& except)
	////////{
	////////	cout << except.what() << endl;
	////////}



	cout << " print chat users here :" << endl;
	chat->printUsers();
	cout << endl << endl;

	// создаём временного пользователя и добавляем его в конец
	userTmp.setLogin("tmpUserLogin1");
	userTmp.setPass("tmpUserPass1");
	users.insertElementEnd(userTmp);

	// ищем нужного пользователя в пользователях и добавляем его в чат первым
	chat->addUser(users[usersPtr->findElement(userTmp)]);
	chat->addUser(users[0]);

	//меняем пароль пользователю 0 через использование ссылки и проверяем, что пароль изменился 
	users[0].setPass("PassChanged");
	cout << "user 0 password: " << users[0].getPass() << endl;

	//распечатываем пользователей чата
	cout << " print chat ussers here :" << endl;
	chat->printUsers();

	//for pause
	//int tmp_int;
	//cin >> tmp_int;
	//cout << tmp_int << endl;
	//end for pause



	return 0;
}