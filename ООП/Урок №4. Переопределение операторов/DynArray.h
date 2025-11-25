#pragma once

#include <iostream>

class DynArray
{
	friend std::ostream& operator<<(std::ostream&, const DynArray&);
	friend std::istream& operator>>(std::istream&, const DynArray&);

public:
	explicit DynArray(int = 10);
	DynArray(const DynArray&);
	~DynArray();
	int Length() const;

	const DynArray& operator=(const DynArray&);
	bool operator==(const DynArray&) const;
	bool operator!=(const DynArray& arr) const
	{
		return !(*this == arr);
	}
	int& operator[](int);
	int operator[](int) const;
	
private:
	int size;
	int* arr;
};

