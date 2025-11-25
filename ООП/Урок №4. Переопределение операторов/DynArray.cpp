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