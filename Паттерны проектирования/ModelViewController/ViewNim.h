#pragma once
#include "ModelNim.h"
#include <iostream>

using namespace std;


class ViewNim : public ObserverNim
{
private:
	ModelNim* model;

public:
	ViewNim(ModelNim* model)
	{
		this->model = model;
		this->model->AddObserver(this);
	}
	virtual void Update()
	{
		system("cls");
		for (int i = 0; i <= model->GetNim0(); i++)
		{
			cout << "0";
		}
		for (int i = 0; i < model->GetNimO(); i++)
		{
			cout << "O";
		}
		cout << endl;
		cout << "Заберите фигуры (от 1 до 4): ";
	}
};

