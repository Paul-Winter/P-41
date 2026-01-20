#include <iostream>

using namespace std;

// Exception - исключение, исключительная ситуация
// try (контролировать)
// throw (бросать)
// catch (поймать)

int main()
{
    setlocale(LC_ALL, "");

    while (true)
    {
        try
        {
            double a;
            double b;

            cout << "\nВведите делимое: ";
            cin >> a;
            cout << "\nВведите делитель: ";
            cin >> b;

            if (b == 0)
            {
                throw b;
            }

            cout << "\nРезультат деления: " << a / b << endl;
        }
        catch (double ex)
        {
            cout << "\nОшибка - попытка деления на " << ex << endl;
        }
    }

    return 0;
}
