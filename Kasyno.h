#pragma once
#include "Gracz.h" 
#include "Karta.h"
#include "Bot.h"
class Kasyno
{
	Karta talia[52];
	Gracz *hazardzista[6];
	int wybrane[52] = {};
	int ileGraczy, ileBotow;
public:

	Karta dajKarte();
	Kasyno();
	void nazwijBoty();
	void nazwijGraczy();
	void zapisz();
	void potasuj();
	void rozlozTalie();
	void nowaGra();
	void graj();
	
	~Kasyno();
};

