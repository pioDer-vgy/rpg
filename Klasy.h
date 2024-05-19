#pragma once
#include <string.h>

using namespace std;

class Enemy;
class Player;

//entity class
class Entity
{
protected:
	int zycie, atak, level, exp;
	string nazwa;

public:
	virtual void e_atak(Player p, Enemy e) = 0;
	virtual void czar() = 0;
	virtual bool czy_umarl() = 0;
};

//enemy class
class Enemy: public Entity
{
	friend class Player;
public:

	Enemy(int z, int a, int l, int e, string n);
	virtual void e_atak(Player p, Enemy e);
	virtual void czar();
	virtual bool czy_umarl();
};

//player class
class Player : public Entity
{
	friend class Enemy;
protected:
	int mana;

public:

	Player(int z, int a, int l, int e, string n, int m);
	virtual void e_atak(Player p, Enemy e);
	virtual void czar();
	virtual bool czy_umarl();
	void level_up(Enemy e);
	void game_over();
	void pokaz_staty();
	int get_level();
};