#include <iostream>
#include <string>
#include <stdexcept>

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
        /*
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
        */

        try
        {
            int* ptr = 0;
            int size;

            cout << "\nВведите размер массива (от 1 до 10): ";
            cin >> size;

            if (size < 1 || size > 10)
            {
                throw "\nОШИБКА - указан неверный размер!";
            }

            ptr = new int[size];

            if (!ptr)
            {
                throw "\nОШИБКА - невозможно выделить память!";
            }

            string a;
            cout << "\nВведите значение а (не равно 0): ";
            cin >> a;
            int number = stoi(a);
            
            if (number == 0)
            {
                throw number;
            }
        }
        catch(int ex)
        {
            cout << "\nОШИБКА: переменная а = " << ex << endl;
        }
        catch(const char* ex)
        {
            cout << ex << endl;
        }
        // универсальный catch
        catch(...)
        {
            cout << "\nОШИБКА: неизвестная ошибка!" << endl;
        }
    }

    return 0;
}
