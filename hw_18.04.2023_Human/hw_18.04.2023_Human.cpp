#include <iostream>
#include <windows.h>
using namespace std;

class Date {
public:
	Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

	Date() {}

	void SetDate(int i) {
		int year, month, day; bool first = true;
		_count = i;
		_dateOfBirth = new Date * [_count];

		cout << "Введите дату рождения (ДД.ММ.ГГГГ) " << i + 1 << "-го человека: ";
		scanf_s("%d.%d.%d", &day, &month, &year);

		_dateOfBirth[i] = new Date(day, month, year);
	}

	void showDate() {
		int i = 0;
		cout << "О дате рождения какого объекта класса человек вы хотите узнать информацию? Введите число от 1 до " << _count << endl;
		cin >> i;
		cout << "Дата рождения (ДД.ММ.ГГГГ): " << _dateOfBirth[i]->_day << ".";
		cout << _dateOfBirth[i]->_month << ".";
		cout << _dateOfBirth[i]->_year << endl;
	}

private:
	int _day;
	int _month;
	int _year;
	Date** _dateOfBirth;
	int _count;
};

class Human : Date {
public:

	Human(int idHuman, string firstName, string secondName, string thirdName, Date dateOfBirth) :
		_idHuman(idHuman), _firstName(firstName), _secondName(secondName), _thirdName(thirdName), Date(dateOfBirth) {}

	int GetCount() { return _count; }

	void CreateHuman() {
		cout << "Сколько объектов класса человек вы хотите создать? ";
		cin >> _count;
		human = new Human * [_count];

		for (int i = 1; i <= _count; i++)
		{
			int idHuman;
			string firstName, secondName, thirdName;
			Date dateOfBirth;
			cout << "Введите id человека: "; cin >> idHuman;
			cout << "Введите имя: "; cin >> firstName;
			cout << "Введите фамилию: "; cin >> secondName;
			cout << "Введите отчество: "; cin >> thirdName;
			SetDate(i);
			human[i] = new Human(idHuman, firstName, secondName, thirdName, dateOfBirth);
		}
	}

	Human() {}

	void ShowHumanInfo() {
		int i = 0;
		cout << "О каком объекте класса человек вы хотите узнать информацию? Введите число от 1 до " << _count << endl;
		cin >> i;
		cout << "id: " << human[i]->_idHuman << endl;
		cout << "Имя: " << human[i]->_firstName << endl;
		cout << "Фамилия: " << human[i]->_secondName << endl;
		cout << "Отчество: " << human[i]->_thirdName << endl;
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
	Date** _dateOfBirth;
	Human** human;
	int _count;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		Human x;
		x.CreateHuman();
		x.ShowHumanInfo();
	}

	cout << "\nА программа то ещё идёт, а деструктор уже сработал!\n";
}