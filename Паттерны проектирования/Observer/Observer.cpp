#include <iostream>
#include <vector>

using namespace std;

class IObserver
{
public:
    virtual void Update() = 0;
};
class ConcreteObserver : public IObserver
{
public:
    ConcreteObserver()
    {
        cout << "создан наблюдатель" << endl;
    }
    void Update() override
    {
        cout << "наблюдатель изменился" << endl;
    }
};
class SMS : public IObserver
{
public:
    SMS()
    {
    }
    void Update() override
    {
        cout << "отправлено SMS-сообщение" << endl;
    }
};
class Notification : public IObserver
{
public:
    Notification()
    {
    }
    void Update() override
    {
        cout << "отправлено PUSH-оповещение" << endl;
    }
};
class EmailMessage : public IObserver
{
public:
    EmailMessage()
    {
    }
    void Update() override
    {
        cout << "отправлено письмо на электронную почту" << endl;
    }
};
class IObservable
{
public:
    virtual void AddObserver(IObserver* obs) = 0;
    virtual void RemoveObserver(IObserver* obs) = 0;
    virtual void NotifyObservers() = 0;
};
class ConcreteObservable : public IObservable
{
private:
    vector<IObserver*> observers;
public:
    void AddObserver(IObserver* obs) override
    {
        cout << "наблюдатель подписался на объект наблюдения" << endl;
        observers.push_back(obs);
    }
    void RemoveObserver(IObserver* obs) override
    {
        cout << "наблюдатель удалён из списка наблюдателей" << endl;
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void NotifyObservers() override
    {
        for (IObserver* observer : observers)
        {
            cout << "объект наблюдения оповещает наблюдателя" << endl;
            observer->Update();
        }
    }
    ConcreteObservable()
    {
        cout << "создан объект наблюдения" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    
    ConcreteObservable* person = new ConcreteObservable();
    SMS* sms = new SMS();
    Notification* push = new Notification();
    EmailMessage* email = new EmailMessage();

    person->AddObserver(sms);
    person->AddObserver(push);
    person->AddObserver(email);
    person->NotifyObservers();

    person->RemoveObserver(push);
    person->NotifyObservers();

    return 0;
}
