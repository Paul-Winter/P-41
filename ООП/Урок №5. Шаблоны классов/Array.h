#pragma once
#include <iostream>

using namespace std;

template <class T>
class Array
{
	static const int size{ 5 };
	T array[size];

public:
	Array()
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = T();
		}
	}
	int getSize() const
	{
		return size;
	}
	T getItem(int index) const
	{
		if (index >= 0 && index < size)
		{
			return array[index];
		}
		else
		{
			cout << "Index is out of range" << endl;
			exit(1);
		}
	}
	void setItem(int index, T value)
	{
		if (index >= 0 && index < size)
		{
			array[index] = value;
		}
		else
		{
			cout << "Index is out of range\nИндекс вне границ массива" << endl;
			exit(1);
		}
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

