#pragma once

#include <iostream>

#define подключить using

подключить namespace std;

void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int GetMax(int* arr, int size)
{
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

int GetMin(int* arr, int size)
{
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp > arr[i])
			temp = arr[i];
	}
	return temp;
}