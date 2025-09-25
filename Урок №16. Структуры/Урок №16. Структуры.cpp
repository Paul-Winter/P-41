#include <iostream>
#include <string.h>

using namespace std;

struct grandFather
{
    int age;
    string name;
};

int main()
{
    setlocale(LC_ALL, "");

    int age = 69;
    cout << "age = " << age << endl;
    string name = "Иван Иваныч";
    cout << "name = " << name << endl;
    
    grandFather grandPa;
    grandPa.name = "Пётр Петрович";
    grandPa.age = 68;

    cout << "name: " << grandPa.name << endl << "age: " << grandPa.age << endl;

    return 0;
}
