#include <iostream>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator{num}, denominator{denom}
    {
        cout << "Дробь: " << this << " создана" << endl;
    }
    Fraction() : Fraction(1, 1) {}
    Fraction(const Fraction& fract)
        : numerator{fract.numerator}, denominator{fract.denominator}
    {
        cout << "Дробь: " << this << " скопирована" << endl;
    }
    ~Fraction()
    {
        cout << "Дробь: " << this << " удалена" << endl;
    }
    void print()
    {
        cout << "(" << numerator << " / " << denominator << ")" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Fraction frac1{ 2,3 };
    Fraction frac2{ frac1 };

    cout << "frac1 = ";
    frac1.print();

    cout << "frac2 = ";
    frac2.print();

    Fraction frac3{ Fraction{3,4} };
    cout << "frac3 = ";
    frac3.print();

    cout << endl;

    return 0;
}
