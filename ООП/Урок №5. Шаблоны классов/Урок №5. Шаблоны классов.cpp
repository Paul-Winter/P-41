#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Array<int> intArray;
    intArray.display();

    Array<string> strArray;
    strArray.setItem(0, "zero");
    strArray.setItem(1, "one");
    strArray.setItem(2, "two");
    strArray.setItem(3, "three");
    strArray.setItem(4, "four");
    strArray.display();

    return 0;
}