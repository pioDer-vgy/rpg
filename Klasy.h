using namespace std;

//entity class
class Entity
{
protected:

	int zycie, atak, level, exp;
	string nazwa;

public:

	Entity(int z, int a, int l, int e, string n) : zycie(z), atak(a), level(l), exp(e), nazwa(n) {}
	virtual void pokaz_staty() = 0;
};

//enemy class
class Enemy: public Entity
{
public:

	Enemy(int z, int a, int l, int e, string n) : Entity(z, a, l, e, n) {}
};

//player class
class Player : public Entity
{
private:

	int mana;

public:

	Player(int z, int a, int l, int e, string n, int m) : Entity(z, a, l, e, n), mana(m) {}
	void pokaz_staty();
};