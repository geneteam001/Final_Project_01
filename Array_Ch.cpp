#include "Array_Ch.h"

Array_Ch<>::Array_Ch()
{
}

Array_Ch<>::~Array_Ch()
{
}

void Array_Ch<>::print()
{
	if (_dataPtr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			_dataPtr[i].printMessage();
		}
	}
}