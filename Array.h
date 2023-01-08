#pragma once
//#include "Array.h"
#include <iostream>
#include <exception>
#include <string>
#include "MyException.h"
#include "User.h"
//#include "Chat.h" //может закомментить?

template <typename T = int> class Array
{

private:
	int _size{ 0 }; //Array length
	T* _dataPtr{ nullptr };
	void partCopy(const int &startIndx, const int& endIndx, T* dataPtrNew, const int& shift = 0)
	{
		// !!! проверить корректность!
		for (size_t i = startIndx; i <= endIndx; i++)
		{
			dataPtrNew[i + shift] = _dataPtr[i];
		}
	}; //copy from ...to included with shift;

	void deleteArray()
	{
		if (_dataPtr)
			delete[] _dataPtr;
		_dataPtr = nullptr;
		_size = 0;
	};

public:
	Array() = default;
	Array(int size) : _size(size)
	{
		//_size = size;
		if (_size < 0)
		{
			throw MyException("Exception: Array size is less then zero. Array not created!");
		}
		_dataPtr = new T[_size]{};
	};

	Array(const Array* Source) //Array copy constructor
	{
		this->_size = Source->_size;
		if (_size < 0)
		{
			throw MyException("Exception: Array size is less then zero. Array not created!");
		}
		_dataPtr = new T[_size]{};
		for (size_t i = 0; i < _size; i++)
		{
			this->_dataPtr[i] = Source->_dataPtr[i];
		}
	};

	~Array()
	{
		deleteArray();
	};

	Array& operator= (const Array& Source) //Copy array
	{
		if (this != &Source) // protection against copy into self
		{
			this->_size = Source._size;
			if (_size < 0)
			{
				throw MyException("Exception: Array size is less then zero. Array not created!");
			}
			_dataPtr = new T[_size]{};
			for (size_t i = 0; i < _size; i++)
			{
				this->_dataPtr[i] = Source._dataPtr[i];
			}
		}
		return *this;
	};

	T& operator [] (int indx) const
	{
		if (indx < 0 || indx >= _size)
		{
			throw MyException("Exception: Index outside array!");
		}
		return _dataPtr[indx];
	};

	void setNewSize(const int sizeNew)
	{
		if (_dataPtr)
		{
			if (sizeNew < 0)
			{
				throw MyException("Exception: Array size is less then zero. Array not created!");
			}
			T* dataPtrNew{ nullptr }; //new array
			dataPtrNew = new T[sizeNew]{};
			_size <= sizeNew ? partCopy(0, _size - 1, dataPtrNew, 0) : partCopy(0, sizeNew - 1, dataPtrNew, 0);
			deleteArray();
			_dataPtr = dataPtrNew;
			_size = sizeNew;
			return;
		}
		else
		{
			_size = sizeNew;
			if (_size < 0)
			{
				throw MyException("Exception: Array size is less then zero. Array not created!");
			}
			_dataPtr = new T[_size]{};
		}
	};

	int getSize()
	{
		return _size;
	};

	void insertElement(const int indx, const T value)
	{

		int sizeNew{ 0 };

		T* dataPtrNew{ nullptr }; //new array
		sizeNew = _size + 1;
		if (indx < 0 || indx >= sizeNew)
		{
			throw MyException("Exception: Index outside array!");
		}
		dataPtrNew = new T[sizeNew]{};
		if (indx - 1 >= 0)
		{
			partCopy(0, indx - 1, dataPtrNew);;
		}
		if (indx < _size)
		{
			partCopy(indx, _size - 1, dataPtrNew, 1);
		}
		dataPtrNew[indx] = value;

		deleteArray();
		_dataPtr = dataPtrNew;
		_size = sizeNew;
		return;
	};

	void removeElement(const int indx)
	{
		int sizeNew{ 0 };
		if (indx < 0 || indx >= _size)
		{
			throw MyException("Exception: Index outside array!");
		}
		T* dataPtrNew{ nullptr }; //new array
		sizeNew = _size - 1;
		if (sizeNew < 0)
		{
			throw MyException("Exception: Array size is less then zero. Array not created!");
		}
		dataPtrNew = new T[sizeNew]{};
		if (indx - 1 >= 0)
		{
			partCopy(0, indx - 1, dataPtrNew);
		}
		if (indx < _size)
		{
			partCopy(indx + 1, _size - 1, dataPtrNew, -1);
		}

		deleteArray();
		_dataPtr = dataPtrNew;
		_size = sizeNew;
		return;
	};

	int findElement(const T value)
	{
		int ret{ -1 };
		if (_dataPtr)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_dataPtr[i] == value)
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
	};

	//void print()
	//{
	//	if (_dataPtr)
	//	{
	//		for (size_t i = 0; i < _size; i++)
	//		{
	//			std::cout << i << " : " << _dataPtr[i] << std::endl;
	//		}
	//	}
	//};

	void print()
	{
		if (_dataPtr)
		{
			for (size_t i = 0; i < _size; i++)
			{
				std::cout << i << " : " << _dataPtr[i] << std::endl;
			}
		}
	};
	/*void print()
	{
		if (_dataPtr)
		{
			
			for (size_t i = 0; i < _size; i++)
			{
				T tmp_user;
				tmp_user = _dataPtr[i];
				std::cout << i << " Login: " << tmp_user.getLogin() << std::endl;
				std::cout << i << " Pass: " << tmp_user.getPass() << std::endl;
			}
		}
	};*/

	//Additional functions
	void insertElementBeginning(const T value)
	{
		//if (!getSize())
		//{
		//	setNewSize(1);
		//}

		if (!_dataPtr)
		{
			_size = 1;
			if (_size < 0)
			{
				throw MyException("Exception: Array size is less then zero. Array not created!");
			}
			_dataPtr = new T[_size]{};
			_dataPtr[0] = value;
		}
		else
		{
			insertElement(0, value);
		}

	};
	void insertElementEnd(const T value)
	{
		//if (!getSize())
		//{
		//	setNewSize(1);
		//}
		if (!_dataPtr)
		{
			insertElementBeginning(value);
		}
		else
		{
			insertElement(_size, value);
		}
	};
	void removeElementBegining()
	{
		removeElement(0);
	};
	void removeElementEnd()
	{
		removeElement(_size - 1);
	};
	void setElement(const int indx, const T value)
	{
		if (indx < 0 || indx >= _size)
		{
			throw MyException("Exception: Index outside array!");
		}
		_dataPtr[indx] = value;
	};
	T getElement(const int indx)
	{
		return _dataPtr[indx];
	};
};

//специализация функции print для класса User
template<> 
void Array<User>::print()
{
	if (_dataPtr)
	{

		for (size_t i = 0; i < _size; i++)
		{
			std::cout << i << " Login: " << _dataPtr[i].getLogin() << std::endl;
			std::cout << i << " Pass: " << _dataPtr[i].getPass() << std::endl;
		}
	}
};

//специализация функции print для класса User* указателей

template<>
void Array<User*>::print()
{
	if (_dataPtr)
	{

		for (size_t i = 0; i < _size; i++)
		{
			std::cout << i << " Login: " << (*_dataPtr[i]).getLogin() << std::endl;
			std::cout << i << " Pass: " << (*_dataPtr[i]).getPass() << std::endl;
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
		if (ret == -1) {
			throw MyException("No such element in array!");
		}
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
};