#include <iostream>
using namespace std;

void HumanObj(Human& object);

class Human {
private:
	Human** _human;
	string _name;
	int _age;
public:
	string getName() { return _name; }
	int getAge() { return _age; }

	Human() {}

	Human(string name, int age) :
		_name(name), _age(age) {}

	Human CreateHuman() {
		int age;
		string name;
		int size = 2;
		*_human = new Human[2];

		for (int i = 0; i < 2; i++) 
		{
			cout << "Введите имя: "; cin >> name;
			cout << "Введите возраст: "; cin >> age;
			_human[i] = new Human(name, age);
		}
	}
};

int main()
{

}


void HumanObj(Human& object) {

}