#include "Bot.h"
void Bot::setOdwaga()
{
	std::cout << "wybierz poziom odwagi swojego bota(1,2 lub 3)"<<std::endl;
	while (1)
	{
		std::cin >> odwaga;
		if (std::cin.fail() == true || odwaga != 1 && odwaga != 2 && odwaga != 3) {
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
}
bool Bot::pobierzKarte()
{

	if (odwaga == 1)
	{
		if (wartoscReki() < 13)
			return true;
	}
	if (odwaga == 2)
	{
		if (wartoscReki() < 17)
			return true;
	}
	if (odwaga == 3)
	{
		if (wartoscReki() < 20)
			return true;
	}
	return false;
}
bool Bot::getCzySpasowal()
{
	if (odwaga == 1)
	{
		if (wartoscReki() < 13)
			return false;
	}
	if (odwaga == 2)
	{
		if (wartoscReki() < 17)
			return false;
	}
	if (odwaga == 3)
	{
		if (wartoscReki() < 20)
			return false;
	}
	return true;
}
Bot::Bot(int o)
{

}
Bot::Bot()
{

}
Bot::~Bot()
{
}
