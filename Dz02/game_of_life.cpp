#include "game_of_life.h"
#include <ctime>
#include <sstream>

bool game_of_life::slucajna_vrijednost()
{
	int x = rand() % 4;
	if (x == 0)
		return true;
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || j < 0)
		return false;
	if (_generacija[i][j] == false)
		return false;
	return true;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int count = 0;
			if (celija_zauzeta(i - 1, j - 1))
				count++;
			if (celija_zauzeta(i - 1, j))
				count++;
			if (celija_zauzeta(i - 1, j + 1))
				count++;
			if (celija_zauzeta(i, j - 1))
				count++;
			if (celija_zauzeta(i, j + 1))
				count++;
			if (celija_zauzeta(i + 1, j - 1))
				count++;
			if (celija_zauzeta(i + 1, j))
				count++;
			if (celija_zauzeta(i + 1, j + 1))
				count++;
			if (celija_zauzeta(i, j)) {
				if (count == 2 || count == 3)
					_sljedeca_generacija[i][j] = true;
				else
					_sljedeca_generacija[i][j] = false;
			}
			else {
				if (count == 3)
					_sljedeca_generacija[i][j] = true;
				else {
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	stringstream ss;
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i, j))
				ss << '*';
			else
				ss << '-';
		}
		ss << endl;
	}
	cout << ss.str();
}
