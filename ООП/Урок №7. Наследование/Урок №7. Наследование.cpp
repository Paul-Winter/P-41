#include <iostream>
#include <string.h>

using namespace std;

class Parent
{
    int countDefault;
protected:
    int countProtected;
public:
    int countPublic;
private:
    int countPrivate;

public:
    Parent()
    {
        cout << "Вызов конструктора Parent" << endl;
    }
};

class ChildPublic : public Parent
{
public:
    ChildPublic()
    {
        cout << "Вызов конструктора ChildPublic" << endl;
    }
};

class ChildProtected : protected Parent
{
public:
    ChildProtected()
    {
        cout << "Вызов конструктора ChildProtected" << endl;
    }
};

class ChildPrivate : private Parent
{
public:
    ChildPrivate()
    {
        cout << "Вызов конструктора ChildPrivate" << endl;
    }
};

class ChildDefault : Parent
{
public:
    ChildDefault()
    {
        cout << "Вызов конструктора ChildDefault" << endl;
    }
};
class Point
{
protected:
    int x;
    int y;
public:
    Point(int _x, int _y) :x{ _x }, y{_y}{}
    Point()
    {
        x = 0;
        y = 0;
    }
    int& getX()
    {
        return x;
    }
    int& getY()
    {
        return y;
    }
};
class Window : public Point
{
    int height;
    int width;
public:
    Window(int _height, int _width) : height{ _height }, width{ _width }{}
    int& getHeight()
    {
        return height;
    }
    int& getWidth()
    {
        return width;
    }
    void moveX(int Dx)
    {
        x += Dx;
    }
    void moveY(int Dy)
    {
        y += Dy;
    }
    void Show()
    {
        cout << "По Х " << x<<endl;
        cout << "По Y " << y << endl;
        cout << "По Height " << height << endl;
        cout << "По Width " << width << endl;
    }
};

class Roga
{
protected:
    int weight;
    string color;
public:
    Roga()
    {
        weight = 0;
        color = "Brown";
    }
};
class Kopyta
{
protected:
    int size;
    string form;
public:
    Kopyta()
    {
        size = 0;
        form = "big";
    }
};
class Los : public Roga, public Kopyta
{
public:
    string name;
    Los()
    {
        name = "Los Bezimanniy";
    }
    void show()
    {
        cout << "Name Losa: " << name<<endl;
        cout << "Size Kopyt: " << size << endl;
        cout << "Form Kopyt: " << form << endl;
        cout << "Color Rogov: " << color << endl;
        cout << "Weight Rogov: " << weight << endl;
    }
};

class Father
{
protected:
    string hair;
public:
    Father()
    {
        hair = "Black";
    }
    string getHair()
    {
        return hair;
    }
};

class Mother
{
protected:
    string eyescolor;
public:
    Mother()
    {
        eyescolor = "Green";
    }
    string getEyescolor()
    {
        return eyescolor;
    }
};

class GrandMother
{
protected:
    int weight;
public:
    GrandMother()
    {
        weight = 1;
    }
    int getWeight()
    {
        return weight;
    }
};

class GrandFather
{
protected:
    int height;
public:
    GrandFather()
    {
        height = 0;
    }
    int getHeight()
    {
        return height;
    }
};

class Baby : public GrandFather, public GrandMother, public Father, public Mother
{
    string name;
public:
    Baby()
    {
        name = "Ванечка Безымянный";
    }
    string getname()
    {
        return name;
    }
    void Show()
    {
        cout << "Name " << name << endl;
        cout << "Eyes color " << eyescolor << endl;
        cout << "Hair color " << hair << endl;
        cout << "Height " << height << endl;
        cout << "Weight " << weight << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    //Parent human("Ivan", 23);
    //human.Show();
    //human.SetAge(17);
    ////human.SetFingers(10);
    //human.Show();

    //ChildPublic baby("Vanechka", 1, 10);
    //baby.Show();

    //ChildDefault cd;
    //ChildPublic cp;
    //cp.countPublic = 12;
    //ChildProtected cpr;
    //ChildPrivate cpi;

    /*Window win(10, 10);
    win.Show();
    win.moveX(2);
    win.moveY(7);
    win.Show();

    Los Ivan;

    Ivan.show();*/

    Baby Vanechka;

    Vanechka.Show();

    return 0;
}
