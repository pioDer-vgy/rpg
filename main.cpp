#include <iostream>
#include "Funkcje.cpp"

using namespace std;

int main()
{
	system("cls");
	Player p1(100, 20, 1, 0, "Wojownik", 100);
	Enemy e1(100, 15, 1, 20, "stwor");

	Entity* wsk;
	wsk = &p1;

	walka(wsk, p1, e1);
}