#pragma once
#include "Gracz.h"
class Bot :public Gracz
{

int odwaga;

public:
	void setOdwaga();
	bool pobierzKarte();
	bool getCzySpasowal();

	Bot(int o); 
	Bot();
	~Bot();
};

