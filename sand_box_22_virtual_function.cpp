#include <iostream>

using namespace std;

class Enemy{
	public:
	virtual void attack(){}

};

class Ninja: public Enemy{
	public:
	void attack(){
		cout << "ninja attack! " << endl;
		}
};

class Monster: public Enemy{
	public:
	void attack(){
		cout << "monster attack! " << endl;
		}
};

int main()
{
	Ninja ninja;
	Monster monster;
	Enemy *enemy_one = &ninja;
	Enemy *enemy_two = &monster;
	enemy_one->attack();
	enemy_two->attack();

	system("pause");

	
}
