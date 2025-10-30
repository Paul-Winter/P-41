#include <iostream>

using namespace std;

int random(int x)
{
    srand(time(NULL));
    int y = rand() % x;
    //cout << y << endl;
    return y;
}

int main()
{
 /*   random(5);*/

    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i]= random(5);
       /* cout << arr[i]<<" ";*/
    }
    int* ukazatel = &arr[0];
    for (int i = 0; i < 100; i++)
    {
        cout << *(ukazatel + i) << " ";
        
    }
    const int size = 12;

    char mass[size]
    {
        'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'
    };
    
    for (int i = 0; i < size; i++)
    {
        cout << mass[i];
    }
    cout << endl;

    char* ukaz = &mass[0];

    for (int i = 0; i < size; i++)
    {
        cout << *(ukaz + i);
    }


    return 0;
}
