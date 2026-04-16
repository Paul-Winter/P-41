#pragma once
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void Update() = 0;
};

class Observervable
{
private:
	vector<Observer*> observers;
public:
	void AddObserver(Observer* observer)
	{
		observers.push_back(observer);
	}
	void Notify()
	{
		int size = observers.size();
		for (int i = 0; i < size; i++)
		{
			observers[i]->Update();
		}
	}
};

class Model : public Observervable
{
private:
	double temperatureF;	
public:
	double GetTempF()
	{
		return temperatureF;
	}
	double GetTempC()
	{
		return (temperatureF - 32.0) * 5.0 / 9.0;
	}
	void SetTempF(double tempF)
	{
		temperatureF = tempF;
		Notify();
	}
	void SetTempC(double tempC)
	{
		temperatureF = tempC * 9.0 / 5.0 + 32.0;
		Notify();
	}
};

