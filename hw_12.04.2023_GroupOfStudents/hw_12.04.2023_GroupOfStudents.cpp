#include <iostream>
#include <string>
#include <windows.h>


using namespace std;


class Lesson
{
public:
	Lesson(string _title, int _countGrade, int _averageGrade, int _grades[]) : title(_title), countGrade(_countGrade) {}; // member initializer list
	

	void CreateLesson(int _countGrade)
	{
		countGrade = _countGrade;
		lesson = new Lesson* [countGrade];

		for (int i = 0; i < countGrade; i++)
		{
			string title;
			int countGrade = 0, averageGrade = 0;
			int* grades = new int[countGrade];
			cout << "Введите название предмета.\n";
			cin >> title;

		}

	}

private:
	Lesson** lesson; // массив с оценками.
	string title; // название предмета.
	int countGrade; // количество оценок.
	int averageGrade; // средняя оценка.
};



int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int countGrade = 5 + rand() % 10;

}

