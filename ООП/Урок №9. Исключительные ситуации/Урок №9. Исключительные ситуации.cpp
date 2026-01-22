#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Exception - исключение, исключительная ситуация
// try (контролировать)
// throw (бросать)
// catch (поймать)

class SmartDevice
{
public:
    int id;
    string name;
    bool isConnect;
    bool isWorking;

    SmartDevice(int _id, string _name, bool _isCon, bool _isWork)
        : id{ _id }, name { _name }, isConnect{ _isCon }, isWorking{ _isWork } {}
    SmartDevice() : SmartDevice(1, "unknown", false, false) {}

    virtual void ShowInfo() = 0;
};
class SensorDevice : public SmartDevice
{
public:
    SensorDevice(int _id, string _name, bool _isCon, bool _isWork)
    {
        this->id = _id;
        this->name = _name;
        this->isConnect = _isCon;
        this->isWorking = true;
    }
    SensorDevice() : SensorDevice(1, "unknown sensor", false, true) {}

    virtual void ShowInfo()
    {
        cout << "Smart Device: " << name << "\nId: " << id << "\nStatus: ";
        if (isConnect)
        {
            cout << "connected ";
        }
        else
        {
            cout << "disconnected ";
        }
        if (isWorking)
        {
            cout << "working" << endl;
        }
        else
        {
            cout << "not work" << endl;
        }
    }

    void SensorOn()
    {
        this->isWorking = true;
    }
    void SensorOnErr()
    {
        this->ShowInfo();
        SensorDeviceException sde;
        throw sde;
    }
    void SensorOff()
    {
        this->isWorking = false;
    }
    void SensorOffErr()
    {
        this->ShowInfo();
        SensorDeviceException sde;
        throw sde;
    }
    void SensorConn()
    {
        this->isConnect = true;
    }
    void SensorConnErr()
    {
        this->ShowInfo();
        SensorDeviceException sde;
        throw sde;
    }
    void SensorDisc()
    {
        this->isConnect = false;
    }
    void SensorDiscErr()
    {
        this->ShowInfo();
        SensorDeviceException sde;
        throw sde;
    }
};
class WorkingDevice : public SmartDevice
{
public:
    WorkingDevice(int _id, string _name, bool _isCon, bool _isWork)
    {
        this->id = _id;
        this->name = _name;
        this->isConnect = _isCon;
        this->isWorking = _isWork;
    }
    WorkingDevice() : WorkingDevice(1, "unknown device", false, false) {}

    virtual void ShowInfo()
    {
        cout << "Smart Device: " << name << "\nId: " << id << "\nStatus: ";
        if (isConnect)
        {
            cout << "connected ";
        }
        else
        {
            cout << "disconnected ";
        }
        if (isWorking)
        {
            cout << "working" << endl;
        }
        else
        {
            cout << "not work" << endl;
        }
    }

    void DeviceOn()
    {
        this->isWorking = true;
    }
    void DeviceOnErr()
    {
        this->ShowInfo();
        WorkingDeviceException sde;
        throw sde;
    }
    void DeviceOff()
    {
        this->isWorking = false;
    }
    void DeviceOffErr()
    {
        this->ShowInfo();
        WorkingDeviceException sde;
        throw sde;
    }
    void DeviceConn()
    {
        this->isConnect = true;
    }
    void DeviceConnErr()
    {
        this->ShowInfo();
        WorkingDeviceException sde;
        throw sde;
    }
    void DeviceDisc()
    {
        this->isConnect = false;
    }
    void DeviceDiscErr()
    {
        this->ShowInfo();
        WorkingDeviceException sde;
        throw sde;
    }
};

class SmartDeviceException
{
public:
    int kod;
    string message;

    SmartDeviceException(int _kod, string _message) {}
    SmartDeviceException() : SmartDeviceException(1, "unknown exception") {}

    virtual int ShowInfo() = 0;
};
class SensorDeviceException : public SmartDeviceException
{
public:
    SensorDeviceException() : SmartDeviceException(5, "sensor exception") {}

    virtual int ShowInfo()
    {
        cout << "Exception: " << message << endl;
        return this->kod;
    }
};
class WorkingDeviceException : public SmartDeviceException
{
public:
    WorkingDeviceException(int _kod, string _message) {}
    WorkingDeviceException() : SmartDeviceException(6, "device exception") {}

    virtual int ShowInfo()
    {
        cout << "Exception: " << message << endl;
        return this->kod;
    }
};


int main()
{
    setlocale(LC_ALL, "");

    while (true)
    {
        /*
        try
        {
            double a;
            double b;

            cout << "\nВведите делимое: ";
            cin >> a;
            cout << "\nВведите делитель: ";
            cin >> b;

            if (b == 0)
            {
                throw b;
            }

            cout << "\nРезультат деления: " << a / b << endl;
        }
        catch (double ex)
        {
            cout << "\nОшибка - попытка деления на " << ex << endl;
        }
        */

        /*
        try
        {
            int* ptr = 0;
            int size;

            cout << "\nВведите размер массива (от 1 до 10): ";
            cin >> size;

            if (size < 1 || size > 10)
            {
                throw "\nОШИБКА - указан неверный размер!";
            }

            ptr = new int[size];

            if (!ptr)
            {
                throw "\nОШИБКА - невозможно выделить память!";
            }

            string a;
            cout << "\nВведите значение а (не равно 0): ";
            cin >> a;
            int number = stoi(a);
            
            if (number == 0)
            {
                throw number;
            }
        }
        catch(int ex)
        {
            cout << "\nОШИБКА: переменная а = " << ex << endl;
        }
        catch(const char* ex)
        {
            cout << ex << endl;
        }
        // универсальный catch
        catch(...)
        {
            cout << "\nОШИБКА: неизвестная ошибка!" << endl;
        }
        */

        try
        {
            SensorDevice Sensor{ 1, "Датчик света", 1,1 };
            WorkingDevice Computer{ 2, "Домашний Компутер", 1,0 };
            Sensor.SensorDiscErr();
            Sensor.SensorOffErr();
            Computer.DeviceDiscErr();
            Computer.DeviceOnErr();
        }
        catch (SensorDeviceException ex)
        {
            cout << "Произошла ошибка датчика."<<ex.ShowInfo();
        }
        catch (WorkingDeviceException ex)
        {
            cout << "Произошла ошибка устройства." << ex.ShowInfo();
        }
        catch (...)
        {
            cout << "Неизвестная ошибка!";
        }
    }

    return 0;
}
