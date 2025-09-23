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

int main()
{
    setlocale(LC_ALL, "");

    int season;
    cout << "Введите время года: ";
    cin >> season;
    cout << endl;

    if (season == 4) 
    {
        cout << "Осень - золотая пора!" << endl;
    }
    else if (season == 1)
    {
        cout << "Зима - пора снежная." << endl;
    }
    else if (season == 2)
    {
        cout << "Весна красна пришла!" << endl;
    }
    else
    {
        cout << "Лето, ах лето!" << endl;
    }

    return 0;
}
