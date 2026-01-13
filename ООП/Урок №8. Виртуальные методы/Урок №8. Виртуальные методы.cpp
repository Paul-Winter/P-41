#include <iostream>

using namespace std;

class Parent
{
protected:
    string Form_Ears;
    string Color_Eyes;

public:
    Parent(string Form_Ears, string Color_Eyes) : Form_Ears{ Form_Ears }, Color_Eyes{ Color_Eyes }
    {
        cout << "Parent параметризованный конструктор" << endl;
    }    
    Parent() : Parent("Угловатые", "Карие")
    {
        cout << "Parent конструктор по умолчанию" << endl;
    }

    virtual void show()
    {
        cout << "Форма ушей: " << Form_Ears << "\tЦвет глаз: " << Color_Eyes << endl;
    }

    string GetEars()
    {
        return Form_Ears;
    }
    string GetEyes()
    {
        return Color_Eyes;
    }

    void SetEars(string value)
    {
        Form_Ears = value;
    }
    void SetEyes(string value)
    {
        Color_Eyes = value;
    }
};
class Child : public Parent
{
protected:
    string Form_Nose;
    string Color_Hair;
    
public:

    Child(string Form_Nose, string Color_Hair) : Form_Nose{ Form_Nose }, Color_Hair { Color_Hair }
    {
        cout << "Child параметризованный конструктор" << endl;
    }    
    Child() : Child("Картошкой", "Брюнет")
    {
        cout << "Child конструктор по умолчанию" << endl;
    }

    virtual void show()
    {
        cout << "Форма носа: " << Form_Nose << "\tЦвет волос: " << Color_Hair << "\nФорма ушей: " << Form_Ears << "\tЦвет глаз: " << Color_Eyes << endl;
    }

    string GetNose()
    {
        return Form_Nose;
    }
    string GetHair()
    {
        return Color_Hair;
    }

    void SetNose(string value)
    {
        Form_Nose = value;
    }
    void SetHair(string value)
    {
        Color_Hair = value;
    }
};
class Baby : public Child //, public Parent
{
protected:
    string Pampers_Size;
    int weight;

public:
    Baby(string Pampers_Size, int weight) : Pampers_Size{ Pampers_Size }, weight{ weight } {}
    Baby() : Baby("XL", 1)
    {
        cout << "Baby конструктор по умолчанию" << endl;
    }

    virtual void show()
    {
        cout << "Форма носа: " << Form_Nose << "\tЦвет волос: " << Color_Hair << "\nФорма ушей: " << Parent::Form_Ears << "\tЦвет глаз: " << Child::Color_Eyes << endl;
        cout << "Размер подгузника: " << Pampers_Size << "\tВес: " << weight << endl;
    }
};

class Matreshka
{
protected:
    int size;

public:
    Matreshka(int Psize) :size{ Psize } {}
    Matreshka() :Matreshka(20) {}
    virtual int GetSize()
    {
        return size;
    }
    virtual void SetSize(int value)
    {
        size = value;
    }
    virtual void Show()
    {
        cout << "Матрешка " << size << " см" << endl;
    }
};

class MiniMatreshka:public Matreshka
{
private:
    string color;

public:
    MiniMatreshka(string Pcolor, int Psize) :color{ Pcolor }
    {
        size = Psize;
    }
    MiniMatreshka() :MiniMatreshka("orange", 15) {}

    virtual string GetColor()
    {
        return color;
    }
    virtual void SetColor(string value)
    {
        color = value;
    }
    virtual void Show()
    {
        cout << "Мини матрешка " << size << " см" << ", цвет: " << color << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    /*
    Parent family;
    family.show();
    cout << endl << "-------------------------------------------------------------------" << endl;

    Child baby;
    //baby.Show_Child();
    baby.SetEars("Круглые");
    baby.SetEyes("Зеленые");
    baby.SetHair("Блондин");
    baby.SetNose("Заостренный");
    cout << endl << "-------------------------------------------------------------------" << endl;

    //baby.Show_Child();
    baby.show();
    cout << endl << "-------------------------------------------------------------------" << endl;

    Baby b;
    b.show();
    */

    Matreshka m1;
    MiniMatreshka m2;
    m1.Show();
    m2.Show();

    return 0;
}
