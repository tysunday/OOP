#include <iostream>
#include <windows.h>
using namespace std;

class Date {
public:
	Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

	Date() {}

	void SetDate() {
		int year, month, day; bool first = true;

		cout << "Введите год рождения: "; cin >> year;
		do {
			if (first) {
				cout << "Введите месяц рождения: ";
				cin >> month;
				first = false;
			}
			else {
				cout << "Месяцев всего 12, введите число от 1 до 12: ";
				cin >> month;
				
			}
		} while (month > 12 || month < 1);
		first = true;
		cout << "Введите день рождения: "; cin >> day;
		dateOfBirth = new Date(day, month, year);
	}

	void showDate() {
		cout << dateOfBirth->_day << endl;
		cout << dateOfBirth->_month << endl;
		cout << dateOfBirth->_year << endl;
	}

private:
	int _day;
	int _month;
	int _year;
	Date* dateOfBirth;
};

class Human : Date {
public:

	Human(int idHuman, string firstName, string secondName, string thirdName, Date dateOfBirth) :
		_idHuman(idHuman), _firstName(firstName), _secondName(secondName), _thirdName(thirdName), _dateOfBirth(dateOfBirth) {}

	Human() {
		int idHuman;
		string firstName, secondName, thirdName;
		Date dateOfBirth;
		cout << "Введите id человека: "; cin >> idHuman;
		cout << "Введите имя: "; cin >> firstName;
		cout << "Введите фамилию: "; cin >> secondName;
		cout << "Введите отчество: "; cin >> thirdName;
		SetDate();
		human = new Human(idHuman, firstName, secondName, thirdName, dateOfBirth);
	}

	void ShowHumanInfo() {
		cout << human->_idHuman << endl;
		cout << human->_firstName << endl;
		cout << human->_secondName << endl;
		cout << human->_thirdName << endl;
		showDate();
	}

	~Human() {
		cout << "Привет, я деструктор =)\n";
		cout << "Я сработал потому что ударился об ажурную скобку и автоматически почистил твою память, не благодари!\n";
	}

private:
	int _idHuman;
	string _firstName;
	string _secondName;
	string _thirdName;
	Date _dateOfBirth;
	Human* human;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		Human x;
		x.ShowHumanInfo();
	}

	cout << "\nА программа то ещё идёт, а деструктор уже сработал!\n";
}

