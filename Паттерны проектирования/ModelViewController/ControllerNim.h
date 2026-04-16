#pragma once
#include "ModelNim.h"
#include <iostream>

using namespace std;

class ControllerNim
{
private:
	ModelNim* model;

public:
	ControllerNim(ModelNim* model)
	{
		this->model = model;
	}
	void Start()
	{
		//model->SetNim0(0);
		int step;
		do
		{
			cin >> step;
			model->SetNim0(model->GetNim0() + step);
			model->SetNimO(model->GetNimO() - step);
		} while (model->GetNimO() != 1);
	}
};

