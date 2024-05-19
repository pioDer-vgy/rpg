#include <iostream>
#include <Windows.h>
#include "Klasy.cpp"

using namespace std;

int main()
{
	Player p1(100, 20, 1, 0, "Wojownik", 100);
	//Enemy e1(100, 10, 1, 20, "stwor");

	Entity* wsk;
	wsk = &p1;

	wsk->pokaz_staty();
}