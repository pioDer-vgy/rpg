#include <iostream>
#include <string.h>
#include "Klasy.h"

using namespace std;

//konstruktory


Enemy::Enemy(int z, int a, int l, int e, string n)
{
	zycie = z;
	atak = a;
	level = l;
	exp = e;
	nazwa = n;
}

Player::Player(int z, int a, int l, int e, string n, int m)
{	
	zycie = z;
	atak = a;
	level = l;
	exp = e;
	nazwa = n;
	mana = m;
}

//metody

void Player::pokaz_staty()
{
	cout << "Zycie: " << zycie << "\nMana: " << mana << "\n";
}

void Enemy::e_atak(Player p, Enemy e)
{
	cout << nazwa << " atakuje " << p.nazwa << " z sila " << atak << "\n";
	p.zycie -= atak;
}

void Player::e_atak(Player p, Enemy e)
{
	cout << nazwa << " atakuje " << e.nazwa << " z sila " << atak << "\n";
	e.zycie -= atak;
}

void Enemy::czar()
{
	cout << nazwa << " rzuca czar leczacy\n";
	zycie = zycie + 20;
}

void Player::czar()
{
	cout << nazwa << " rzuca czar leczacy\n";
	zycie = zycie + 20;
}

bool Enemy::czy_umarl()
{
	if (zycie <= 0)
	{
		return true;
	}
	return false;
}

bool Player::czy_umarl()
{
	if (zycie <= 0)
	{
		return true;
	}
	return false;
}

void Player::game_over()
{
	cout << "Game over";
	exit(0);
}

void Player::level_up(Enemy e)
{
	exp = exp + e.exp;
	if (exp >= 100)
	{
		level = level + 1;
		cout << nazwa << " Awansuje na " << level << "Poziom";
	}
}

int Player::get_level()
{
	return level;
}