#include <iostream>
#include <string>
#include <Windows.h>
#include "Klasy.h"

//reszta funkcji

Entity* zmien_ture(Entity *&wsk, Player &p, Enemy &e)
{
    if(wsk == &p) wsk = &e;
    else wsk = &p;

    return wsk;
}

void walka(Entity *&wsk, Player &p, Enemy &e)
{
    int wybor;

    cout << "Spotykasz wroga!\n";
    Sleep(1500);

    for(;;)
    {
        system("cls");
        if(wsk->czy_martwy())
        {
            p.game_over();
        }

        cout << "Co zamierzasz zrobic?\n";
        wsk->pokaz_zycie();

        cout << "1. Atak\n" << "2. Czar\n";
        for(;;)
        {
            if (!(cin >> wybor) || wybor > 2 || wybor < 1)
            {
                cout << "Zly rodzaj ruchu, sproboj jeszcze raz\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }
    
        if (wybor == 1)
        {
            p.Atak(e);
        }

        else if(wybor == 2)
        {
            p.czar();
        }

        zmien_ture(wsk, p, e);
        
        if(wsk->czy_martwy())
        {
            if(p.wygrana(e))
            {
                break;
            }
        }

        e.Atak(p);  

        zmien_ture(wsk, p, e);
    }
}

//metody Entity

void Entity::pokaz_staty()
{
    cout << "Nazwa: " << nazwa << "\n";
	cout << "Zycie: " << zycie << "\n";
	cout << "Atak: " << atak << "\n";
	cout << "Level: " << level << "\n";
}

bool Entity::czy_martwy()
{
    bool flag;
    if (zycie <= 0)
    {
        flag = true;
    } else flag = false;
    return flag;
}

void Entity::pokaz_zycie()
{
    cout << nazwa << "\n";
    cout << "zycie: " << zycie << "\n";
}

//metody Enemy

void Enemy::pokaz_staty()
{
	Entity::pokaz_staty();
}

void Enemy::Atak(Player &p)
{
    cout << nazwa << " atakuje " << p.nazwa << " z sila " << atak << "\n";
    p.zycie = p.zycie - atak;
    Sleep(1000);
}

bool Enemy::czy_martwy()
{
    return Entity::czy_martwy();
}

//metody Player

void Player::pokaz_staty()
{
	Entity::pokaz_staty();
    cout << "mana: " << mana << "\n";
}

void Enemy::pokaz_zycie()
{
    Entity::pokaz_zycie();
}

void Player::game_over()
{
	cout << "Game over";
	exit(0);
}

void Player::Atak(Enemy &e)
{
    cout << nazwa << " atakuje " << e.nazwa << " z sila " << atak << "\n";
    e.zycie = e.zycie - atak;
    Sleep(1000);
}

void Player::level_up(Enemy e)
{
    exp = exp + e.exp;
    if (exp >= 15)
    {
        cout << nazwa << " awansuje na " << level+1 << " poziom!\n";
        exp = exp - 15;
        level = level + 1;
    }
}

bool Player::wygrana(Enemy e)
{
    cout << nazwa << " wygrywa pojedynek!\n";
    Sleep(1000);
    Player::level_up(e);
    return true;
}

bool Player::czy_martwy()
{
    return Entity::czy_martwy();
}

void Player::pokaz_zycie()
{
    Entity::pokaz_zycie();
    cout << "Mana: " << mana << "\n";
}

void Player::czar()
{
	cout << nazwa << " rzuca czar leczacy\n";
    mana = mana - 20;
    if (mana >= 0)
    {
        if (zycie == 100) 
            cout << nazwa << " ma juz maksymalna ilosc zdrowia\n";
        else
        {
            cout << "+20 do zdrowia\n";
            zycie = zycie + 20;
            if (zycie > 100)
            {
                zycie = 100;
            }
        }
    }
    else
    {
        cout << "Brak many!\n";
        mana = 0;
    }
}