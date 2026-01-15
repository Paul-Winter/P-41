#include <iostream>

using namespace std;

// абстрактный класс
class A
{
    //чисто виртуальная функция = 0 - чистый спецификатор
    virtual void SomeFunction() = 0;
};

class Pet
{
protected:
    int age;
    string name;
    //string say;
    int tailsize;
public:
    Pet(int age, string name, int tailsize) : age{ age }, name{ name }, tailsize{ tailsize }{}
    Pet() : Pet(10, "Питомец безымянный", 5){}
    /*string getSay()
    {
        return say;
    }*/

    virtual void say() = 0;
    virtual void show()
    {
        cout << "Имя: " << name << endl;
    }
};
class Dog :public Pet
{
protected:
    string breed;
public:
    Dog(int age, string name, int tailsize, string breed) :breed{ breed } 
    {
        this->age = age;
        this->name = name;
        this->tailsize = tailsize;
    }
    Dog() : Dog(5, "Собака безымянная", 10, "Бульдог") {}
    virtual void say()
    {
        cout << "Гав-гав"<<endl;
    }
    virtual void show()
    {
        cout << "Имя: " << name << endl;
        cout << "Порода: " << breed << endl;
    }
};
class Cat :public Pet
{
protected:
    string breed;

public:
    Cat(int age, string name, int tailsize, string breed) :breed{ breed }
    {
        this->age = age;
        this->name = name;
        this->tailsize = tailsize;
    }
    Cat() : Cat(7, "Кот безымянный", 15, "Сиамский") {}
    virtual void say()
    {
        cout << "Мяу-мяу" << endl;
    }
    virtual void show()
    {
        cout << "Имя: " << name << endl;
        cout << "Порода: " << breed << endl;
    }
};

class Animal
{
protected:
    string name;
    virtual void Show() = 0;
    virtual void Say() = 0;
};
class Frog: public Animal
{
    string color;
public:
    Frog(string color,string name)
    {
        this->color = color;
        this->name = name;
    }
    Frog():Frog("зелёная","Квакуша"){}
    virtual void Show()
    {
        cout << "Лягушка " << name << " " << color << endl;
    }
    virtual void Say() { cout << "Ква-ква" << endl; }
};
class Giraffe : public Animal
{
    int neck;
public:
    Giraffe(int neck, string name)
    {
        this->neck = neck;
        this->name = name;
    }
    Giraffe() :Giraffe(2, "Толик") {}
    virtual void Show()
    {
        cout << "Жираф " << name << ", шея " << neck << "м" << endl;
    }
    virtual void Say() { cout << "Shhhh" << endl; }
};

class Human
{
protected:
    string name;
    int age;
    int height;
    int weight;
    char gender;

public:
    Human(string name, int age, int height, int weight, char gender) : name{ name }, age{ age }, height{ height }, weight{ weight }, gender{ gender } {}
    Human() {}
    //virtual void Show() = 0;
    virtual void Show()
    {
        cout << name << "\t возраст: " << age << "\t рост:" << height << "\t вес: " << weight << endl;
    }
    virtual string GetName()
    {
        return name;
    }
    virtual int GetAge()
    {
        return age;
    }
    virtual int GetHeight()
    {
        return height;
    }
    virtual int GetWeight()
    {
        return weight;
    }
    virtual int GetGender()
    {
        return gender;
    }
    virtual void SetName(string value)
    {
        name = value;
    }
    virtual void SetAge(int value)
    {
        age = value;
    }
    virtual void SetWeight(int value)
    {
        weight = value;
    }
    virtual void SetHeight(int value)
    {
        height = value;
    }
};
class Mother : public Human
{
protected:
    string eyes;

public:
    Mother(string name, int age, int height, int weight, string eyes) : eyes{ eyes } 
    {
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
        this->gender = 'Ж';
        this->eyes = eyes;
    }
    Mother() : Mother("Мамаб", 62, 160, 50, "Карие") {}
    Mother(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    virtual void Show()
    {
        Human::Show();
        cout << "\t цвет глаз: " << eyes << endl;
    }
    void SetEyes(string value)
    {
        eyes = value;
    }
    string GetEyes()
    {
        return eyes;
    }
    virtual int GetGender()
    {
        return gender;
    }
};
class Father : public Human
{
protected:
    string hair;

public:
    Father(string name, int age, int height, int weight, string hair) : hair{ hair }
    {
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
        this->gender = 'M';
        this->hair = hair;
    }
    Father() {}
    Father(int height, int weight)
    {
        this->height = height;
        this->weight = weight;
        this->gender = 'M';
    }
    virtual void Show()
    {
        Human::Show();

        cout << "\t цвет волос: " << hair << endl;
    }
    void SetHair(string value)
    {
        hair = value;
    }
    string GetHair()
    {
        return hair;
    }
};
class Student : public Mother, public Father
{
protected:
    int ID;
public:
    Student(string name, int age, int height, int weight, string hair, string eyes, int ID) : ID{ ID }
    {
        Mother::name = name;
        Mother::age = age;
        Father::height = height;
        Father::weight = weight;
        Father::gender = 'M';
        this->hair = hair;
        this->eyes = eyes;
    }
    Student() : Student("Пузо", 17, 180, 80, "Чёрный", "Карие", 182207) {}
    int GetID()
    {
        return ID;
    }
    void SetID(int value)
    {
        ID = value;
    }
    virtual void Show()
    {
        //Father::Show();
        //Mother::Show();
        cout << Mother::name << "\t возраст: " << Mother::age << "\t рост:" << Father::height << "\t вес: " << Father::weight << "\t цвет глаз: " << eyes << "\t цвет волос: " << hair << "\t Id: " << ID << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Dog dog;
    Cat cat;
    dog.show();
    dog.say();
    cat.show();
    cat.say();
    //Pet pet;
    cout << "___________________________________________________________________________" << endl;
    
    //Animal beast;
    Frog frog;
    Giraffe giraffe;
    frog.Show();
    frog.Say();
    giraffe.Show();
    giraffe.Say();
    cout << "___________________________________________________________________________" << endl;

    Mother M("Mama", 29, 190, 50, "Зелёные");
    Father P("Papa", 30, 240, 200, "Блондин");
    Student S("Chypep", 12, 180, 60, "Блондин", "Зелёные", 182207);

    M.Show();
    cout << "___________________________________________________________________________" << endl;
    P.Show();
    cout << "___________________________________________________________________________" << endl;
    S.Show();
    cout << char(S.Father::GetGender()) << endl;

    return 0;
}