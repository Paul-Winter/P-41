#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    char symbol{ 'A' };
    int number{ 65 };

    //char8_t s1{ u8'A' };
    //char_16t s2{ u'A' };
    //char32_t s3{ U'A' };
    wchar_t s4{ L'A' };

    cout << "symbol: " << int(symbol) << endl;
    cout << "number: " << char(number) << endl;
    //cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;

    string s1;
    string s2;
    string s3;

    s1 = "abc";
    s2 = { 'x', 'y', 'z' };
    s3 = s1 + s2;

    cout << " " << s1 << " " << endl;
    cout << " " << s2 << " " << endl;
    cout << " " << s3 << " " << endl;

    s2 += s1;
    cout << " " << s2 << " " << endl;

    string s0 = "";
    cout << s0.empty() << endl;

    return 0;
}
