#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DynArray.h"
using namespace std;

// конструктор
DynArray::DynArray(int arrSize) : size{ arrSize }, arr{ new int[size] {} } {}

// конструктор копирования
DynArray::DynArray(const DynArray& array) : size{ array.size }, arr{ new int[size] }
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = array.arr[i];
	}
}
// деструктор
DynArray::~DynArray()
{
	delete[] arr;
}
// перегрузка оператора присваивания
const DynArray& DynArray::operator=(const DynArray& array)
{
	if (&array != this)
	{
		delete[] arr;
		size = array.size;
		arr = new int[size];

		for (int i = 0; i < size; ++i)
		{
			arr[i] = array.arr[i];
		}
	}
	return *this;
}

// оператор сравнения
bool DynArray::operator==(const DynArray& array) const
{
	if (size != array.size)
	{
		return false;
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != array.arr[i])
		{
			return false;
		}
	}
	return true;
}

// оператор индексирования
int DynArray::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cout << "Index out of range" << endl;
		exit(1);
	}
	return arr[index];
}

// оператор ввода
istream& operator>>(istream& input, const DynArray& array)
{
	for (int i = 0; i < array.size; i++)
	{
		input >> array.arr[i];
	}
	return input;
}

// оператор вывода
ostream& operator<<(ostream& output, const DynArray& array)
{
	for (int i = 0; i < array.size; i++)
	{
		output << array.arr[i] << " ";
	}
	output << endl;
	return output;
}

// размер массива
int DynArray::Length() const
{
	return size;
}
void DynArray::setrandom()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 99;
	}
}