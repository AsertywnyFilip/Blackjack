#include "Kasyno.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
template <typename T>
std::string NumberToString(T pNumber)
{
	std::ostringstream oOStrStream;
	oOStrStream << pNumber;
	return oOStrStream.str();
}
Karta Kasyno::dajKarte()
{
	int i;
	do 
	{ 
		i = (std::rand() % 52);
	} while (wybrane[i] == 1);
	wybrane[i] = 1;
	return talia[i];
}
Kasyno::Kasyno()
{
	for (int i = 0; i < 13; i++)
	{
		talia[i].setWartosc(i);
		talia[i + 13].setWartosc(i);
		talia[i + 26].setWartosc(i);
		talia[i + 39].setWartosc(i);

		for (int i = 0; i < 4; i++)
		{

			for (int j = 0; j < 13; j++)
			{
				talia[j + 13 * i].setKolor(i);
			}
		}
	}
}
void Kasyno::nazwijBoty()
{
	for (int i = ileGraczy; i < ileGraczy + ileBotow; i++)
	{
		std::string imieBota = "Bot " + NumberToString(i - ileGraczy + 1);
		hazardzista[i]->setNazwa(imieBota);
	}
}
void Kasyno::nazwijGraczy()
{
	for (int i = 0; i < ileGraczy; i++)
	{
		
		if (hazardzista[i]->getNazwa().empty())
		{
			
			std::cout << "podaj imie gracza " << i + 1 << std::endl;
			std::string imieGracza;
			std::cin >> imieGracza;
			hazardzista[i]->setNazwa(imieGracza);

		}
	}

}
void Kasyno::potasuj()
{
	for (int t = 0; t < 100; t++)
	{
		int i = (std::rand() % 52);
		int j = (std::rand() % 25);

		std::swap(talia[i], talia[j]);
	}
}

void Kasyno::rozlozTalie()
{
	for (int i = 0; i < 52; i++)
	{
		talia[i].wypisz();
	}
}

void Kasyno::graj()
{
	for (int i = 0; i < ileGraczy+ileBotow; i++)
	{
	
		hazardzista[i]->wezKarte(&this->dajKarte());
		hazardzista[i]->wezKarte(&this->dajKarte());
	}
	int decyzja, koniec =0;
	while (koniec!=ileGraczy)
	{
		int n = 0;
		while (n < ileGraczy)
		{
			std::cout << hazardzista[n]->getNazwa() << "  ";
			std::cout << "   Karty Gracza " << hazardzista[n]->getNazwa() << ": ";
			hazardzista[n]->pokazReke();
			std::cout <<std::endl<< "Jesli chcesz dobrac karte wybierz 1" << std::endl;
			std::cout << "Jesli chcesz spasowac wybierz 0" << std::endl<<std::endl;
			while (1)
			{
				std::cin >> decyzja;
				if (std::cin.fail() == true || decyzja!=0 && decyzja!=1) {
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			koniec = 0;
			if (decyzja == 1)
			{
				hazardzista[n]->wezKarte(&this->dajKarte());
				std::cout << "Karty Gracza " << hazardzista[n]->getNazwa() << ": ";
				hazardzista[n]->pokazReke();
				std::cout<< std::endl << std::endl;
				hazardzista[n]->setCzySpasowal(false);	
			}
			if(decyzja == 0)
			{
				hazardzista[n]->setCzySpasowal(true);
			}
			n++;
		}
			for (int i = ileGraczy; i < ileGraczy + ileBotow; i++)
			{

				if (hazardzista[i]->getCzySpasowal() == false)
				{
					hazardzista[i]->wezKarte(&this->dajKarte());
					std::cout << "Karty Gracza " << hazardzista[i]->getNazwa() << ": ";
					hazardzista[i]->pokazReke();
					std::cout << std::endl;
				}

			}

			for (int i = 0; i < ileGraczy+ileBotow; i++)
			{
				if (hazardzista[i]->wartoscReki() > 21)
					koniec = ileGraczy;
				else if (hazardzista[i]->getCzySpasowal() == true)
				{
					koniec++;
				}
			}

	}
	std::cout << "KONIEC GRY" << std::endl;
	int maxPunkty=1;
	int zwyciezca=0;
	for (int i = 0; i < ileGraczy+ileBotow; i++)
	{
		std::cout << "Gracz  " << hazardzista[i]->getNazwa()<< "   " << hazardzista[i]->wartoscReki() << std::endl;
		for (int j = 0; j < ileGraczy; j++)
		{
			if (hazardzista[i]->wartoscReki() > maxPunkty && hazardzista[i]->wartoscReki() <= 21)
			{
				maxPunkty = hazardzista[i]->wartoscReki();
				zwyciezca = i+1;
			}
		}
	}
	std::cout << "ZWYCIEZA GRACZ : " << hazardzista[zwyciezca-1]->getNazwa()<<std::endl;
	system("PAUSE");
}

void Kasyno::zapisz()
{
	std::ofstream plik;
plik.open("tabela.txt", std::ofstream::out);
	for (int i = 0; i < ileGraczy+ileBotow; i++)
	{
		plik << " Gracz: " << hazardzista[i]->getNazwa();
		plik << "    ";
		for (int j = 0; j < hazardzista[i]->iloscKart(); j++)
		{
			plik << hazardzista[i]->zwrocFigury();
			plik << hazardzista[i]->zwrocKolory();
			hazardzista[i]->nastepna();
		}
		plik << "    ";
		for (int j = 0; j < hazardzista[i]->iloscKart(); j++)
			hazardzista[i]->poprzednia();
		plik<< "pkt: " << hazardzista[i]->wartoscReki()<<std::endl;
	}
	plik.close();
}
void Kasyno::nowaGra()
{
	std::cout << "WITAJ W BLACKJACKU 2.0"<<std::endl;
	int zakoncz = 1;
	while (zakoncz = 1)
	{
		std::cout << "ile Graczy bierze udzial? (max 3)";
			while (1) 
			{
				std::cin >> ileGraczy;
				if (std::cin.fail() == true|| ileGraczy != 1 && ileGraczy != 2 && ileGraczy != 3) {
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
		std::cout << "ile Botow bierze udzial?";
		while (1)
		{
			std::cin >> ileBotow;
			if (std::cin.fail() == true || ileBotow != 1 && ileBotow != 2 && ileBotow != 3) {
				std::cout << "wykryto blad" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}

		for (int i = 0; i < ileGraczy; i++)
		{
			hazardzista[i] = new Gracz;
		}
		for (int i = ileGraczy; i < ileGraczy + ileBotow; i++)
		{
			hazardzista[i] = new Bot;
			hazardzista[i]->setOdwaga();
		}
		nazwijBoty();
		nazwijGraczy();
		int koniec = 0;
		while (koniec != 1)
		{
			int tasowanie;
			std::cout << "NOWA GRA" << std::endl;

			std::cout << "ILE RAZY POTASOWAC KARTY?" << std::endl;
			while (1)
			{
				std::cin >> tasowanie;
				if (std::cin.fail() == true || tasowanie>100) {
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			for (int i = 0; i < tasowanie; i++)
				potasuj();
			graj();
			zapisz();
			for (int i = 0; i < ileGraczy + ileBotow; i++)
			{
				hazardzista[i]->wyczyscReke();
			}
			for (int i = 0; i < 52; i++)
			{
				wybrane[i] = 0;
			}
			std::cout << "JESLI CHCESZ ZMIENIC WPISZ 1" << std::endl << "JESLI CHCESZ GRAC DALEJ WPISZ INNA LICZBE";
			while (1)
			{
				std::cin >> koniec;
				if (std::cin.fail() == true) {
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}

		}
	}
}
Kasyno::~Kasyno()
{



}
