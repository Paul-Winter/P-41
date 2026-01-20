#include <iostream>

using namespace std;

// Exception - исключение, исключительная ситуация
// try (контролировать)
// throw (бросать)
// catch (поймать)

int Div(int x, int y)
{
    // попытка деления на ноль вызовет код ошибки: 1010
    if (y == 0)
    {
        throw y;
    }
    return x / y;
}

void Division(int x, int y)
{
    if (y == 0)
    {
        cout << "На ноль делить нельзя!" << endl;
    }
    else
    {
        cout << "x / y = " << x / y << endl;
    }
}

int SomeFunc()
{
    //try
    //{
        // блок кода, в котором может возникнуть исключительная ситуация
        //...
        //throw выражение определённого типа
    //}
    //catch (тип_исключения имя)
    //{
    //}
    return 0;
}

int main()
{
    setlocale(LC_ALL, "");

    //cout << "6 / 0 = " << Div(6, 0) << endl;
    //Division(6, 0);

    try
    {
        cout << "Перед ошибкой" << endl;
        throw 100;
        cout << "После ошибки" << endl;
    }
    catch(int ex)
    {
        cout << "Возникла ошибка с кодом: " << ex << endl;
    }
    cout << "Программа продолжила своё выполнение" << endl;

    return 0;
}
