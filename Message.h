#pragma once
#include <string>
class Message
{
public:
	Message();

	~Message();
	void setMessage(std::string message);
	//{
	//	_message = message;
	//};
	std::string getMessage() const;
	//{
	//	return string(_message);
	//};
	void printMessage();
private:
	std::string _timeSend;
	std::string _message;
	std::string _timeRead;
};


//
//inline void Message::printMessage()
//{
//	std::cout << _message << std::endl;
//}
//;

