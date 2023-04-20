#include <iostream>
#include <windows.h>
using namespace std;

class Animal {
public:

	Animal(string type, bool sex, string name, float cost) : _sex(sex), _name(name), _cost(cost) {}

	Animal() {}

	int CreateAnimal(string type) {
		cout << "How much animal you wanna create?\n";
		cin >> _count;
		animal = new Animal * [_count];
		for (int i = 1; i <= _count; i++) {
			bool sex = 0; float cost; int count;
			string name;

			cout << "Input gender animal (0 - men, 1 - women) : \n";
			cin >> sex;
			cout << "Input name animal \n";
			cin >> name;
			cout << "Input cost animal (float) \n";
			cin >> cost;

			animal[i] = new Animal(type, sex, name, cost);
		}
		return _count;
	}

	void ShowInfoAboutType() {
		cout << "Имеющиеся животные \n";
		for (int i = 1; i <= _count; i++)
		{
			cout << "Животное №" << i << endl;
			cout << "Имя " << animal[i]->_name << endl;
			cout << "Цена " << animal[i]->_cost << endl;
			cout << "Пол: "; 
			if (animal[i]->_sex == 0)
				cout << "М";
			else cout << "Ж";
			cout << endl << endl;
		}
	}

	~Animal() {
		cout << "Destructor Animal is initialized\n";
	}

private:
	Animal** animal;
	bool _sex;
	string _name;
	float _cost;
	int _count;
};

class Zoo : public Animal {
public:
	void CreateAnimalType() {
		cout << "Какой тип животного вы хотите создать ? Волк, пингвин? Введите: " << endl;
		cin >> _animalType;
		string type{ _animalType };
		_count += CreateAnimal(type);
	}

	int GetCount() { return _count; }

	void showCountAnimalInZOO() {
		cout << "\n\nВсего животных создано: ";
		cout << GetCount() << endl;
	}

	~Zoo() {
		cout << "Destructor ZOO is initialized \n";
	}

private:
	string _animalType;
	int _count = 0;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Zoo user;
	user.CreateAnimalType();
	user.ShowInfoAboutType();
}


