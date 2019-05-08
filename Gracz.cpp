#include "Gracz.h"
#pragma warning(disable:4996)
Gracz::Gracz()
{
	ilosc = 0;
	rozdanie = new Karta[ilosc];
}
void Gracz::nastepna()
{
	rozdanie++;
}
void Gracz::poprzednia()
{
	rozdanie--;
}
void Gracz::wyczyscReke()
{
	ilosc = 0;
	delete[]rozdanie;
}

void Gracz::setNazwa(std::string _imie)
{
	nazwa = _imie;
}
void Gracz::setCzySpasowal(bool _pas)
{
	czySpasowal = _pas;
}
int Gracz::iloscKart()
{	return ilosc;
}
void Gracz::wezKarte(Karta * _karta)
{
	Gracz temp;
	temp.ilosc = ilosc;
	temp.nazwa = nazwa;
	temp.rozdanie = new Karta[ilosc+1];
	for (int i = 0; i < ilosc; i++)
	{
		temp.rozdanie[i] = rozdanie[i];
	}
	temp.rozdanie[ilosc] = *_karta;
	*this = temp;
	ilosc++;
}

int Gracz::wartoscReki()
{
	int suma = 0;
	for(int i = 0; i<ilosc; i++)
		suma += rozdanie[i].getWartosc();
	return suma;
}

char Gracz::zwrocKolory()
{
		return rozdanie->getKolor();

}

char Gracz::zwrocFigury()
{
		return rozdanie->getFigura();
}

void Gracz::pokazReke()
{
	for (int i = 0; i < ilosc; i++)
	{
		rozdanie[i].wypisz();
	}
} 

Gracz::~Gracz()
{
	//delete[] rozdanie;
}