#include <iostream>
#include <string>
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
    system("cls");

    int wybor;

    cout << "Spotykasz wroga!\n";

    for (int i = 0; i < 20; i++)
    {
        if(wsk->czy_martwy() == true)
        {
            p.game_over();
        }

        cout << "Co zamierzasz zrobic?\n";
        wsk->pokaz_zycie();

        cout << "1. Atak\n" << "2. Czar\n";
        cin >> wybor;
    
        if (wybor == 1)
        {
            p.Atak(e);
        }

        else if(wybor == 2)
        {
            p.czar();
        }

        else
        {
            //walidacja
        }

        zmien_ture(wsk, p, e);
        
        if(wsk->czy_martwy() == true)
        {
            p.wygrana(e);
        }

        wsk->pokaz_zycie(); //potem usuń

        e.Atak(p);  

        zmien_ture(wsk, p, e);
    }

    cout << "Przeciwnik ucieka z powrotem do lasu, nic nie dostajesz";
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
    cout << "zycie: " << zycie << "\n\n";
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
	cout << "Game over, Christopher";
	exit(0);
}

void Player::Atak(Enemy &e)
{
    cout << nazwa << " atakuje " << e.nazwa << " z sila " << atak << "\n";
    e.zycie = e.zycie - atak;
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
    exit(0);
}

void Player::wygrana(Enemy e)
{
    cout << nazwa << " wygrywa pojedynek!\n";
    Player::level_up(e);
}

bool Player::czy_martwy()
{
    return Entity::czy_martwy();
}

void Player::pokaz_zycie()
{
    Entity::pokaz_zycie();
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
    }
}