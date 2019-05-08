#pragma once
#include "Karta.h"

class Gracz
{
	Karta *rozdanie;
	int ilosc;
	bool czySpasowal=false;
	std::string nazwa;

public:
	Gracz();
	void nastepna();
	void poprzednia();
	void wyczyscReke();
	void setNazwa(std::string _imie);
	std::string getNazwa() { return nazwa;};
	void setCzySpasowal(bool _pas);
	virtual void setOdwaga() {};
	bool getCzySpasowal() const {return czySpasowal;};
	int iloscKart();
	void wezKarte(Karta * _karta);
	int wartoscReki();
	char zwrocKolory();
	char zwrocFigury();
	void pokazReke();
	~Gracz();
};

