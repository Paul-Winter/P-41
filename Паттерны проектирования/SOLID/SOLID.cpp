#include <iostream>

using namespace std;

#pragma region Single Responsibility Principle

class Report
{
private:
    string text;
public:
    string GetText()
    {
        return text;
    }
    void SetText(string text)
    {
        this->text = text;
    }
    void GoToFirstPage()
    {
        cout << "чтение отчёта с первой страницы" << endl;
    }
    void GoToLastPage()
    {
        cout << "чтение отчёта с последней страницы" << endl;
    }
    void GoToPage(int page)
    {
        cout << "чтение отчёта со страницы номер " << page << endl;
    }
    //void Print()
    //{
    //    cout << "==========распечатка отчёта==========\n" << text << endl;
    //}
};
class Printer
{
private:
    Report report;
public:
    void PrintReport()
    {
        cout << "==========распечатка отчёта==========\n" << report.GetText() << endl;
    }
};

#pragma endregion

#pragma region Open/Closed Principle

class Meal
{
public:
    virtual void Make() = 0;
};

class CookPorrige : public Meal
{
public:
    void Make() override
    {
        cout << "кипятим воду" << endl;
        cout << "засыпаем крупу" << endl;
        cout << "варим до готовности" << endl;
        cout << "сливаем остаток воды (если остался)" << endl;
    }
    CookPorrige()
    {

    }
};

class CookSalad : public Meal
{
public:
    void Make() override
    {
        cout << "чистим овощи" << endl;
        cout << "нарезаем ингредиенты" << endl;
        cout << "смешиваем салат" << endl;
        cout << "заправляем заправкой и добавляем приправы" << endl;
    }
    CookSalad()
    {

    }
};

class CookMeat : public Meal
{
public:
    void Make() override
    {
        cout << "разогреваем сковородку/духовку" << endl;
        cout << "ставим мясо" << endl;
        cout << "жарим/печём до готовности" << endl;
        cout << "посыпаем приправами и поливаем соусом" << endl;
    }
    CookMeat()
    {

    }
};

class Cook
{
private:
    string name;
public:
    string GetName()
    {
        return name;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    Cook(string name)
    {
        this->name = name;
    }
    void Make(Meal* meal)
    {
        meal->Make();
    }
    //void MakeBreakfast()
    //{
    //    cout << "варим овсянку" << endl;
    //    cout << "жарим яичницу" << endl;
    //    cout << "нарезаем колбасу" << endl;
    //    cout << "открываем банку фасоли в томатном соусе" << endl;
    //    cout << "выкладываем всё на тарелку" << endl;
    //    cout << "кушать подано!" << endl;
    //}
    //void MakeDinner()
    //{
    //    cout << "варим куриный бульон" << endl;
    //    cout << "жарим отбивную свиную" << endl;
    //    cout << "нарезаем овощи на салат" << endl;
    //    cout << "оформляем подачу блюд" << endl;
    //    cout << "кушать подано!" << endl;
    //}
    //void MakeSupper()
    //{
    //    cout << "завариваем чай" << endl;
    //    cout << "запекаем шарлотка" << endl;
    //    cout << "наливаем йогурт" << endl;
    //    cout << "кушать подано!" << endl;
    //}
};

#pragma endregion

#pragma region Liskov Substitution Principle



#pragma endregion


int main()
{
    setlocale(LC_ALL, "");

    Cook chief("Arnold");
    cout << "зовём повара по имени " << chief.GetName() << endl;
    Meal* rostbeef = new CookMeat();
    Meal* vitamine = new CookSalad();
    Meal* oatmeal = new CookPorrige();
    cout << "заказываем кашу на завтрак" << endl;
    chief.Make(oatmeal);
    cout << "заказываем мясо на обед" << endl;
    chief.Make(rostbeef);
    cout << "заказываем салат на ужин" << endl;
    chief.Make(vitamine);

    return 0;
}
