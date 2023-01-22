#pragma once
#include <string>
class Message
{
public:
	Message();

	~Message();
	void setMessage(std::string message);

	std::string getMessage() const;

	void printMessage();
private:
	std::string _timeSend;
	std::string _message;
	std::string _timeRead;
};
