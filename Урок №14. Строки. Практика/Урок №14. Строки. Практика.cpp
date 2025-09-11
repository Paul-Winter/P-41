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
    char result[50];
    char* pOrigin;
    char* pResult;

    puts("Введите строку для замены (не более 49 символов) ");
    gets_s(origin);

    pOrigin = origin;
    pResult = result;
    size = strlen(origin) + 1;

    while (i < size)
    {
        if (*(pOrigin + i) != 'i')
        {
            *(pResult + j) = *(pOrigin + i);
        }
        else
        {
            *(pResult + j + 1) = 'a';
        }
        i++;
        j++;
    }
    puts(result);

    return 0;
}

