#include "Array_U.h"

template<> Array_U<User>::Array_U()
{
}

template<> Array_U<User>::~Array_U()
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
}


//специализация функции findElement для класса User
//template<> 
template<>
int Array_U<User>::findElement(User user)
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
    }
    return ret;
}

//функции findID для класса User
template<>
int Array_U<User>::findID(User user)
{
    int ret{ -1 };
    if (_dataPtr)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_dataPtr[i].getID() == user.getID())
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}


//функции findID для типа int
template<>
int Array_U<User>::findID(int userID)
{
    int ret{ -1 };
    if (_dataPtr)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_dataPtr[i].getID() == userID)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

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

 template<> Array_U<User*>::Array_U()
{
}

template<> Array_U<User*>::~Array_U()
{
}

//специализация функции findElement для класса User* указателя
template<>
int Array_U<User*>::findElement(User* user)
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

