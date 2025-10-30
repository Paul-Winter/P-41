#include "iostream"
#include "Student.h"

using namespace std;

void Student::allMarks()
{
    cout << "ќценки:" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << marks[j] << endl;
    }
}
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    return sum / 5;
}
