#include "Array_M.h"

Array_M<>::Array_M()
{
}

Array_M<Message>::~Array_M()
{
}

template<>
void Array_M<Message>::print()
{
    if (_dataPtr)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _dataPtr[i].printMessage();
        }
    }
}
