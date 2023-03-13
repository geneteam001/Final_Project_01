#pragma once
#include "Array.h"
#include "Message.h"

template <typename T = Message> class Array_M : public Array<T>
{
public:
    Array_M();
	~Array_M();
    virtual void print();

private:
};







