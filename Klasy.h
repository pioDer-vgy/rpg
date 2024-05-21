#include <iostream>
#include <string>

using namespace std;

class Player;

//entity class
class Entity
{
protected:

	int zycie, atak, level, exp;
	string nazwa;

public:

	Entity(int z, int a, int l, int e, string n) : zycie(z), atak(a), level(l), exp(e), nazwa(n) {}
	virtual void pokaz_staty();
	virtual bool czy_martwy();
	virtual void pokaz_zycie();
};

//enemy class
class Enemy: public Entity
{
	friend class Player;
public:

	Enemy(int z, int a, int l, int e, string n) : Entity(z, a, l, e, n) {}
	void pokaz_staty();
	void Atak(Player &p);
	bool czy_martwy();
	void pokaz_zycie();
};

//player class
class Player : public Entity
{
private:

	int mana;
	friend class Enemy;

public:

	Player(int z, int a, int l, int e, string n, int m) : Entity(z, a, l, e, n), mana(m) {}
	void pokaz_staty();
	void czar();
	void game_over();
	void Atak(Enemy &e);
	void level_up(Enemy e);
	bool czy_martwy();
	bool wygrana(Enemy e);
	void pokaz_zycie();
};