#include <iostream>
#include <string.h>

using namespace std;

enum Seasons
{
    WINTER,
    SPRING,
    SUMMER,
    AUTUMN
};
enum Menu { SIGN_IN = 1, REGISTER = 2, QUIT = 3 };

auto someFunc(int num)
{
    if (num == 1)
    {
        //return 10;
    }
    else
    {
        return 11.1; // конфликт типов возвращаемого значения;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    auto var = 2.0 + 2.0;
    auto ptr = &var;

    cout << "var = " << var << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "&ptr = " << &ptr << endl;

    auto my_result = someFunc();
    cout << "result = " << my_result << endl;

    return 0;
}
