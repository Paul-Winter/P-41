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

// Бочаров      -   дни недели
// Газарян      -   месяцы
// Дымочкина    -   города
// Лобозев      -   планеты солнечной системы
// Середа       -   праздники
// Сухота       -   дни недели
// Умханов      -   месяцы

int main()
{
    setlocale(LC_ALL, "");

    int userChoise;
    do
    {
        cout << "Выберите действие:" << endl;
        cout << "1 - войти" << endl;
        cout << "2 - зарегистрироваться" << endl;
        cout << "3 - выход" << endl;
        cin >> userChoise;

        switch (userChoise)
        {
        case SIGN_IN: cout << "Введите логин и пароль!" << endl;
            break;
        case REGISTER: cout << "Введите логин, пароль и подтверждение пароля!" << endl;
            break;
        case QUIT: cout << "До свидания!" << endl;
            break;
        default: cout << "ERROR! Неправильно выбран номер пункта меню!" << endl;
            break;
        }
        cout << endl;
    } while (userChoise != 3);

    return 0;
}
