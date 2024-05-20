#include <iostream>
#include <Windows.h>
#include "Funkcje.cpp"

using namespace std;

//void walka(Entity *wsk);

int main()
{
	Player p1(100, 20, 1, 0, "Wojownik", 100);
	Enemy e1(100, 15, 1, 20, "stwor");

	Entity* wsk;
	wsk = &p1;

	wsk->pokaz_zycie();

	walka(wsk, p1, e1);
}

