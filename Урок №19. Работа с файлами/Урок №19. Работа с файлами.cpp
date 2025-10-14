#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    const int n = 5;
    int arr[n];
    FILE* myFile;
    const char* path = "C:\\Users\\Student\\P-41\\Урок №19. Работа с файлами\\myFile.txt";

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 5;
    }

    if ((fopen_s(&myFile, path, "w")) != NULL)
        cout << "Указанный файл не может быть создан!";
    else
    {
        cout << "OK!";
        for (int i = 0; i < n; i++)
        {
            fprintf(myFile, "%1d ", arr[i]);
            fprintf(myFile, "\n");
        }
        cout << endl;

        if (fclose(myFile) == EOF)
            cout << "Файл не закрыт!";
        else
            cout << "Файл закрыт успешно!";
    }
    cout << endl;

    return 0;
}

