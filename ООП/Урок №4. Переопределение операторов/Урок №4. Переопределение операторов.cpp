#include <iostream>
#include "DynArray.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    cout << "Привет, Мир!" << endl;

    DynArray da{ 5 }, db;

    da.setrandom();
    db.setrandom();

    DynArray dc{ da };

    cout << "da = " << da << endl;
    cout <<"db = " << db << endl;
    cout << "dc = " << dc << endl;

    cout << "Размер массива da: " << da.Length() << endl;
    cout << "Размер массива db: " << db.Length() << endl;


    if (da==db)
    {
        cout << "da == db - it's true!" << endl;
    }
    else
    {
        cout << "da == db - it's false!" << endl;
    }

    if (da == dc)
    {
        cout << "da == dc - it's true!" << endl;
    }
    else
    {
        cout << "da == dc - it's false!" << endl;
    }
    if (db == dc)
    {
        cout << "db == dc - it's true!" << endl;
    }
    else
    {
        cout << "db == dc - it's false!" << endl;
    }
    dc = db;
    cout << "dc = db" << endl;
    if (db == dc)
    {
        cout << "db == dc - it's true!" << endl;
    }
    else
    {
        cout << "db == dc - it's false!" << endl;
    }



    return 0;
}