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

class Figure
{

};

class Rectangle : public Figure
{
protected:
    int width;
    int height;
public:
    virtual int GetWidth()
    {
        return width;
    }
    virtual int GetHeight()
    {
        return height;
    }
    virtual void SetWidth(int width)
    {
        this->width = width;
    }
    virtual void SetHeight(int height)
    {
        this->height = height;
    }
    virtual int GetArea()
    {
        return width * height;
    }
};
//class Square : public Rectangle
class Square : public Figure
{
public:
    //int GetWidth() override
    //{
    //    return width;
    //}
    //int GetHeight() override
    //{
    //    return height;
    //}
    //void SetWidth(int width) override
    //{
    //    this->width = width;
    //    this->height = width;
    //}
    //void SetHeight(int height) override
    //{
    //    this->height = height;
    //    this->width = height;
    //}
    Square()
    {

    }
};

#pragma endregion

#pragma region Interface Segregation Principle

class Message
{
protected:
    string text;
    string subject;
    string toAddress;
    string fromAddress;
public:
    virtual string GetText() = 0;
    virtual string GetSubject() = 0;
    virtual string GetToAddress() = 0;
    virtual string GetFromAddress() = 0;
    virtual void SetText(string text) = 0;
    virtual void SetSubject(string subject) = 0;
    virtual void SetToAddress(string toAddress) = 0;
    virtual void SetFromAddress(string fromAddress) = 0;
    virtual void Send() = 0;
};
class EmailMessage : public Message
{
public:
    string GetText() override
    {
        return text;
    }
    string GetSubject() override
    {
        return subject;
    }
    string GetToAddress() override
    {
        return toAddress;
    }
    string GetFromAddress() override
    {
        return fromAddress;
    }
    void SetText(string text) override
    {
        this->text = text;
    }
    void SetSubject(string subject) override
    {
        this->subject = subject;
    }
    void SetToAddress(string toAddress) override
    {
        this->toAddress = toAddress;
    }
    void SetFromAddress(string fromAddress) override
    {
        this->fromAddress = fromAddress;
    }
    void Send() override
    {
        cout << "отправка текста электронной почтой" << endl;
    }
};
class SMSMessage : public Message
{
public:
    string GetText() override
    {
        return text;
    }
    string GetSubject() override
    {
        throw new exception;
    }
    string GetToAddress() override
    {
        return toAddress;
    }
    string GetFromAddress() override
    {
        return fromAddress;
    }
    void SetText(string text) override
    {
        this->text = text;
    }
    void SetSubject(string subject) override
    {
        throw new exception;
    }
    void SetToAddress(string toAddress) override
    {
        this->toAddress = toAddress;
    }
    void SetFromAddress(string fromAddress) override
    {
        this->fromAddress = fromAddress;
    }
    void Send() override
    {
        cout << "отправка текста службой коротких сообщений" << endl;
    }
};
class VoiceMessage : public Message
{
public:
    int* Voice;
    string GetText() override
    {
        throw new exception;
    }
    string GetSubject() override
    {
        throw new exception;
    }
    string GetToAddress() override
    {
        return toAddress;
    }
    string GetFromAddress() override
    {
        return fromAddress;
    }
    void SetText(string text) override
    {
        throw new exception;
    }
    void SetSubject(string subject) override
    {
        throw new exception;
    }
    void SetToAddress(string toAddress) override
    {
        this->toAddress = toAddress;
    }
    void SetFromAddress(string fromAddress) override
    {
        this->fromAddress = fromAddress;
    }
    void Send() override
    {
        cout << "отправка голосового сообщения" << endl;
    }
};

class IMessage
{
protected:
    string toAddress;
    string fromAddress;
public:
    virtual string GetToAddress() = 0;
    virtual string GetFromAddress() = 0;
    virtual void SetToAddress(string toAddress) = 0;
    virtual void SetFromAddress(string fromAddress) = 0;
    virtual void Send() = 0;
};
class ITextMessage : public IMessage
{
protected:
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
};
class ISubjectMessage : public IMessage
{
protected:
    string subject;
public:
    string GetSubject()
    {
        return subject;
    }
    void SetSubject(string text)
    {
        this->subject = text;
    }
};
class IVoiceMessage : public IMessage
{
protected:
    int* voice;
public:
    int* GetVoice()
    {
        return voice;
    }
    void SetVoice(int* record)
    {
        this->voice = record;
    }
};

#pragma endregion

#pragma region Dependency Inversion Principle

//class ConsolePrinter
class ConsolePrinter : public IPrinter
{
public:
    // void Print(string text)
    void Print(string text) override
    {
        cout << text << endl;
    }
};

class IPrinter
{
protected:
    virtual void Print(string text) = 0;
};

class Book
{
private:
    string text;
    //ConsolePrinter* printer;
    IPrinter* printer;
public:
    string GetText()
    {
        return text;
    }
    //ConsolePrinter* GetPrinter()
    IPrinter* GetPrinter()
    {
        return printer;
    }
    void SetText(string text)
    {
        this->text = text;
    }
    //void SetPrinter(ConsolePrinter* printer)
    void SetPrinter(IPrinter* printer)
    {
        this->printer = printer;
    }
};

#pragma endregion


int main()
{
    setlocale(LC_ALL, "");

    //Cook chief("Arnold");
    //cout << "зовём повара по имени " << chief.GetName() << endl;
    //Meal* rostbeef = new CookMeat();
    //Meal* vitamine = new CookSalad();
    //Meal* oatmeal = new CookPorrige();
    //cout << "заказываем кашу на завтрак" << endl;
    //chief.Make(oatmeal);
    //cout << "заказываем мясо на обед" << endl;
    //chief.Make(rostbeef);
    //cout << "заказываем салат на ужин" << endl;
    //chief.Make(vitamine);

    //Rectangle* rect = new Square();
    //rect->SetHeight(5);
    //rect->SetWidth(10);
    //if (rect->GetArea() != 50)
    //{
    //    throw new exception;
    //}

    return 0;
}
