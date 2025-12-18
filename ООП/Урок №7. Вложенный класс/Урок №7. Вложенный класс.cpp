#include <iostream>
#include <string.h>

using namespace std;

// inner class
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

// composition
class Picture
{
    Figure* figures;
    string name;
    int figurescount;
public:
    Picture()
    {
        figures = NULL;
        name = "";
        figurescount = 0;
    }
    ~Picture()
    {
        if (figures != NULL)
        {
            delete[] figures;
        }
    }
    void PaintPicture()
    {
        int temp{ 0 }, temp2{ 0 };
        cout << "Введите имя картины: ";
        cin >> name;
        cout << "Сколько хотите фигур на картине? ";
        cin >> temp;
        if (temp < 2)
        {
            exit(0);
        }
        figurescount = temp;
        figures = new Figure[temp];
        for (int i = 0; i < figurescount; i++)
        {
            cout << "Введите цвет " << i+1 << " фигуры: ";
            cin >> temp;
            cout << "Введите количество точек " << i+1 << " фигуры: ";
            cin >> temp2;
            figures[i].CreateFigure(temp2, temp);
        }
    }
    void ShowPicture()
    {
        cout << "Имя картины: " << name<<endl;
        for (int i = 0; i < figurescount; i++)
        {
            figures[i].ShowFigure();
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
    /*
    Figure f;
    f.CreateFigure(3, 255);
    f.ShowFigure();
    */

    // composition
    Picture great_picture;
    great_picture.PaintPicture();
    great_picture.ShowPicture();
    
    return 0;
}
