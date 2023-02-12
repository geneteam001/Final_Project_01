#pragma once
#include "Array.h"
#include "User.h"

template <typename T = User> class Array_U : public Array<T>

{
public:
	Array_U();
	~Array_U();
	void print();

	 int findElement(T);
	 int findID(T);
private:

};


