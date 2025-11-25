#include <iostream>

using namespace std;

// Создать класс "Дробь" для представления простой дроби
//      Поля:
// + числитель
// + знаменатель
//      Функции-члены:
// + конструктор принимающий числитель и знаменатель
// + конструктор по умолчанию
// + вывод дроби на экран
// + сложение
// - вычитание
// - умножение простой дроби с простой дробью
// - сложение
// - вычитание
// + умножение простой дроби с целым числом
// - В арифметических операциях предусмотреть вызов операций по цепочке (this)
// + Предусмотреть сокращение дроби (конструктор)

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) 
    {
        int nod = Nod(num, denom);
        numerator = num / nod;
        denominator = denom / nod;
        this->Print();
    }
    Fraction() : Fraction(1,1) {}
    void Print()
    {
        cout << "(" << numerator << '/' << denominator << ")" << endl;
    }
    Fraction Mult(Fraction f, int num)
    {
        f.numerator *= num;
        f.denominator *= num;
        f.Print();
        return f;
    }
    Fraction& Sum(Fraction f1, Fraction f2)
    {
        f1.Mult(f1, f2.denominator);
        f2.Mult(f2, f1.denominator);
        numerator = f1.numerator + f2.numerator;
        denominator = f1.denominator;
        cout << "numerator = " << numerator << endl << "denominator = " << denominator << endl;
        return *this;
    }
    friend Fraction& operator*(Fraction& f, int num)
    {
        f.numerator *= num;
        f.denominator *= num;
        f.Print();
        return f;
    }
    friend Fraction& operator+(Fraction& f1, Fraction& f2)
    {  
        Fraction result{1,1};
        //f1.Mult(f1, f2.denominator);
        //f2.Mult(f2, f1.denominator);
        f1 = f1 * f2.denominator;
        f2 = f2 * f1.denominator;
        //numerator = f1.numerator + f2.numerator;
        //denominator = f1.denominator;
        result.numerator = f1.numerator + f2.numerator;
        result.denominator = f1.denominator;
        //cout << "numerator = " << numerator << endl << "denominator = " << denominator << endl;
        return result;
    }
private:   
    int Nod(int numerator, int denominator)
    {
        while (numerator != 0 && denominator != 0)
        {
            if (numerator >= denominator)
            {
                numerator %= denominator;
            }
            else
            {
                denominator %= numerator;
            }
        }
        return numerator + denominator;
    }    
};
int main()
{
    setlocale(LC_ALL, "");

    Fraction frac{ 1,4 };
    frac.Print();
    
    Fraction test{ 1,6 };
    test.Print();
   
    //frac = frac.Sum(frac, test);
    frac.Print();
    Fraction res{};
    res = frac + test;
    res.Print();

    return 0;
}


