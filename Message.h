#pragma once
class Message
{
public:
	Message();
	~Message();

private:
	string _timeSend;
	string _message;
	string _timeRead;
	
	//void ltime()
	//{
	//	// current date/time based on current system
	//	time_t now = time(0);

	//	// convert now to string form
	//	char* dt = ctime(&now);
	//}
};

Message::Message()
{
}

Message::~Message()
{
};

