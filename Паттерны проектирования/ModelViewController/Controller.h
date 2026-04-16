#pragma once
#include "Model.h"
#include <iostream>

using namespace std;

class Controller
{
private:
	Model* model;
public:
	Controller(Model* model)
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

