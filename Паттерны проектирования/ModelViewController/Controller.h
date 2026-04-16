#pragma once
#include "Model.h"
#include <iostream>

using namespace std;

class ControllerTemperature
{
private:
	ModelTemperature* model;
public:
	ControllerTemperature(ModelTemperature* model)
	{
		this->model = model;
	}
	void Start()
	{
		model->SetTempC(0);
		double temp;
		do
		{
			cin >> temp;
			model->SetTempC(temp);
		} while (temp != 0);
	}
};

