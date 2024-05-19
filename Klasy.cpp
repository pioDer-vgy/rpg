#include <iostream>
#include "Klasy.h"

//metody

void Player::pokaz_staty()
{
    cout << "\nNazwa: " << nazwa << "\n";
	cout << "Zycie: " << zycie << "\n";
	cout << "Atak: " << atak << "\n";
    cout << "mana: " << mana << "\n";
	cout << "EXP: " << exp << "\n";
	cout << "Level: " << level << "\n";
}