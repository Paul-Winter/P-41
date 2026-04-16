#pragma once
#include <vector>

using namespace std;

class ObserverNim
{
public:
	virtual void Update() = 0;
};

class ObservervableNim
{
private:
	vector<ObserverNim*> observers;
public:
	void AddObserver(ObserverNim* observer)
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

class ModelNim : public ObservervableNim
{
private:
	int nimO;
	int nim0;

public:
	ModelNim()
	{
		nimO = 21;
		nim0 = 0;
	}
	int GetNimO()
	{
		return nimO;
	}
	void SetNimO(int nim)
	{
		nimO = nim;
	}
	int GetNim0()
	{
		return nim0;
	}
	void SetNim0(int nim)
	{
		if (nim < 1)
		{
			nim0 = 1;
		}
		else if (nim > 4)
		{
			nim0 = 4;
		}
		else
		{
			nim0 = nim;
		}
		Notify();
	}
};

