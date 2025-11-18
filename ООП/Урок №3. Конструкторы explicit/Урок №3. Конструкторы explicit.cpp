#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) : day{day}, month{month}, year{year}
    {}
    Date(int year) : Date(1, 1, year)
    {}
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
};

void Print(Date date)
{
    cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << endl;
}

Date currentYear()
{
    return 2025;
}

class Array
{
    int size;
    int* array;
public:
    Array(int size) : size{ size }, array{ new int[size] } {}
    ~Array()
    {
        delete[] array;
    }
    int getSize() const
    {
        return size;
    }
    int getValue(int index) const
    {
        return array[index];
    }
    void setValue(int index, int value)
    {
        array[index] = value;
    }
    void print(int index) const;
};
void Array::print(int index) const
{
    cout << array[index] << " ";
};
void print(const Array& array)
{
    for (int i = 0; i < array.getSize(); i++)
    {
        array.print(i);
    }
    cout << endl;
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "Неявное преобразование" << endl;

    Print(2020);
    Date date = 2010;
    Print(date);
    Date current = currentYear();
    Print(current);
    
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "Явное преобразование" << endl;

    int size = 4;
    Array array(size);

    for (int i = 0; i < size; i++)
    {
        array.setValue(i, size - i);
    }
    print(array);
    print(3);

    return 0;
}
