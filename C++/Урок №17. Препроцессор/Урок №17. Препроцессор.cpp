#include <iostream>
#include <string.h>

#define PI 3.14159026
#define E 2.71284
#define forever for(;;)
#define begin {
#define end }
#define ДА 1
#define НЕТ 0
#define ПОКА while

using namespace std;

//const double PI = 3.14159026;
const int HEIGHT = 186;
const int WEIGHT = 85;
const char SYMBOL = 'S';
const string NAME = "unknown";

//// Задание ////
// 
// С помощью директив препроцессора #define и #undef
// написать пример простого программного кода
// с использованием ветвления и цикла в стиле
// согласно заданного варианта:
// 
// 1. Бочаров   - python
// 2. Газарян   -
// 3. Дымочкина - церковно-славянский
// 4. Лобозев   - латино
// 5. Мальцева  -
// 6. Середа    - leet 1337 (буквы заменены цифрами)
// 7. Сухота    - hello world
// 8. Трещёткин -
// 9. Умханов   -
//
//////////////////

int main()
{
    setlocale(LC_ALL, "");

    cout << "Pi = " << PI << endl;
    cout << "E = " << E << endl;
    cout << "Height = " << HEIGHT << endl;
    cout << "Weight = " << WEIGHT << endl;
    cout << "Symbol = " << SYMBOL << endl;
    cout << "Name = " << NAME << endl;

    ПОКА(ДА)
    begin
    cout << "ДА" << " " << ДА << endl;
    char c;
    cin >> c;
    if (c == '1')
    {
        cout << "ВЫХОД" << endl;
        break;
    }
    end

//    forever
//    begin
//        cout << "! ";
//    end
//
//#undef begin
//#undef end

    //forever
    //{
    //    cout << "! ";
    //}

    return 0;
}
