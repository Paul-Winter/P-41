#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    unsigned int x = 4;
    cout << "до сдвига влево: x = " << x << endl;
    x = x << 1;
    cout << "после сдвига влево: x = " << x << endl;
    cout << endl << endl;
    cout << "_____________________________________________________________" << endl;

    unsigned int a = 12;
    for (int i = 0; i < 4; i++)
    {
        unsigned int b = a >> i;
        cout << "a >> " << i << " = " << b << endl;
    }
    cout << endl << endl;
    cout << "_____________________________________________________________" << endl;

    int k, l, m, n;
    
    // побитовое ИЛИ
    k = 5;
    l = 6;
    m = 7;
    n = k | l;
    cout << "5 | 6 = " << n << endl;

    // побитовое И
    n = k & l;
    cout << "5 & 6 = " << n << endl;

    // побитовое XOR
    n = k ^ l;
    cout << "5 ^ 6 = " << n << endl;

    // побитовое НЕ
    n = ~m;
    cout << "~7 = " << n << endl;

    return 0;
}
