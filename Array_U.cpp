#include "Array_U.h"

template<> Array_U<User>::Array_U()
{
}

template<> Array_U<User>::~Array_U()
{
}

//������������� ������� print ��� ������ User
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


//������������� ������� findElement ��� ������ User
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

//������� findID ��� ������ User
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


//������� findID ��� ���� int
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

//������������� ������� print ��� ������ User* ����������
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

//������������� ������� findElement ��� ������ User* ���������
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

