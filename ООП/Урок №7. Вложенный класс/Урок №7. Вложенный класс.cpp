#include <iostream>
#include <string.h>

using namespace std;

class Human
{
public:
    string name;
    int age;
//private:
    // inner class
    class Organ
    {
    public:
        string name;
        int weight;
        Organ(int _weight) : weight{ _weight } {}
        void PrintOrgan()
        {
            cout << "Organ weight is " << weight << " gramm" << endl;
        }
    };
public:
    Human(int _age) : age{ _age } {}
    Human(string _name) : name{_name} {}
    void PrintHuman()
    {
        cout << "Human name is " << name << " age: " << age << endl;
    }
};

// agregate
class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    void SetPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void Show()
    {
        cout << "Point (" << x << ":" << y << ")" << endl;
    }
};
class Figure
{
    // координаты углов
    Point* points;
    
    // количетво углов
    int count;

    // цвет фигуры
    int color;

public:
    Figure()
    {
        count = 0;
        color = 0;
        points = NULL;
    }
    ~Figure()
    {
        if (points != NULL)
        {
            delete[] points;
        }
    }
    void CreateFigure(int cuts, int color)
    {
        if (cuts < 3)
        {
            exit(0);
        }
        count = cuts;
        this->color = color;
        points = new Point[count];

        int tempX;
        int tempY;
        for (int i = 0; i < count; i++)
        {
            cout << "Set X: ";
            cin >> tempX;
            cout << "Set Y: ";
            cin >> tempY;
            cout << endl;
            points[i].SetPoint(tempX, tempY);
        }
    }
    void ShowFigure()
    {
        cout << "Figure color is " << color << endl;
        cout << "Cuts:" << endl;
        for (int i = 0; i < count; i++)
        {
            points[i].Show();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");
    
    // inner class
    /*
    Human human("Ivan");
    human.age = 17;
    human.PrintHuman();

    Human::Organ appendex(200);
    appendex.PrintOrgan();
    */

    // agregate
    Figure f;
    f.CreateFigure(3, 255);
    f.ShowFigure();
    
    return 0;
}
