#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int size;
    int i = 0;
    int j = 0;
    char origin[50];
    char result[100];
    char* pOrigin;
    char* pResult;

    puts("Введите строку для замены (не более 49 символов) ");
    gets_s(origin);

    pOrigin = origin;
    pResult = result;
    size = 2 * strlen(origin);
    *(pResult + size) = '\0';

    while ((*pOrigin) != '\0')
    {
        *pResult++ = *pOrigin;
        *pResult++ = *pOrigin++;
    }
    puts(result);

    return 0;
}

