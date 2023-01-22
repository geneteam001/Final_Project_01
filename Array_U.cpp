#include "Array_U.h"

Array_U<>::Array_U()
{
}

Array_U<>::~Array_U()
{
}


//специализация функции print для класса User
template<> 
void Array_U<User>::print()
{
    if (_dataPtr)
    {

        for (size_t i = 0; i < _size; i++)
        {
           _dataPtr[i].printUser();

        }
    }
};

//специализация функции print для класса User* указателей

template<>
void Array_U<User*>::print()
{
    if (_dataPtr)
    {

        for (size_t i = 0; i < _size; i++)
        {
            (*_dataPtr[i]).printUser();
        }
    }
};


//специализация функции findElement для класса User
template<>
int Array<User>::findElement(User user)
{
    int ret{ -1 };
    if (_dataPtr)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_dataPtr[i].getLogin() == user.getLogin())
            {
                ret = i;
                break;
            }
        }

        //Проверить в других местах и удалить, если не требуется!
        //if (ret == -1) 
        //{
        //    throw MyException("No such element in array!");
        //}
    }
    return ret;
};

//специализация функции findElement для класса User* указателя
template<>
int Array<User*>::findElement(User* user)
{
    int ret{ -1 };
    if (_dataPtr)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if ((*_dataPtr[i]).getLogin() == (*user).getLogin())
            {
                ret = i;
                break;
            }
        }
        if (ret == -1) {
            throw MyException("No such element in array!");
        }
    }
    return ret;
}