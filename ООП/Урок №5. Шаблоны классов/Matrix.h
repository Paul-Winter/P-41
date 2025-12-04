#pragma once
#include <iostream>

using namespace std;

template <class T>
class Matrix
{
protected:
	int height;
	int width;
	T** matrix;
private:
	bool allocate(int height, int width)
	{
		if (height <= 0 width <= 0)
		{
			return false;
		}
		this->height = height;
		this->width = width;
		matrix = new T * [height];
		for (int i = 0; i < height; i++)
		{
			matrix[i] = new T[width];
			for (int j = 0; j < width; j++)
			{
				matrix[i][j] = T();
			}
		}
		return true;
	}
	void clear()
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i < height; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		matrix = nullptr;
	}
	void copy(T** from)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				matrix[i][j] = from[i][j];
			}
		}
	}
public:
	Matrix(int height, int width)
	{
		if (height <= 0 || width <= 0)
		{
			cout << "Wrong size!" << endl;
			exit(1);
		}
		if (!allocate(height, width))
		{
			cout << "Wrong size!" << endl;
			exit(1);
		}
	}
	Matrix(int size) : Matrix(size, size) {}
	Matrix()
	{
		height = 0;
		width = 0;
		matrix = nullptr;
	}
	Matrix(const Matrix& matrix)
	{
		clear();
		allocate(matrix.height, matrix.width);
		copy(matrix);
	}
	~Matrix()
	{
		clear();
	}
};

