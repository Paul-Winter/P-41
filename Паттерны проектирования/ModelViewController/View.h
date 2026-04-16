#pragma once
#include "Model.cpp"
#include <iostream>

using namespace std;

class View : public Observer
{
private:
	Model* model;
public:
	View(Model* model)
	{
		this->model = model;
		this->model->AddObserver(this);
	}
	virtual void Update()
	{
		system("cls");
		cout << "Temperature in Celsius: " << model->GetTempC() << endl;
		cout << "Temperature in Fahrenheit: " << model->GetTempF() << endl;
		cout << "Input temperature in Celsius: ";
	}
};

