#pragma once
#include <string>
class Message
{
public:
	Message();

	~Message();
	void userName(std::string userName);
	void setMessage(std::string message);
	void setTimeSend(std::string time);
	std::string getMessage() const;

	void printMessage();
private:
	std::string _userName;
	std::string _timeSend;
	std::string _message;
	std::string _timeRead;
};
