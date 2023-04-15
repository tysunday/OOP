#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

class Lesson
{
public:

	string arrayLessons[10] = { "Math", "Spanish Language", "Russian Language", "Programming", "Physics", "PE", "History",
		"Science", "Art", "Basic military training" };
		
	void CreateLesson(int _countLessons)
	{
		countLessons = _countLessons;
		lesson = new Lesson * [countGrade];

		for (int i = 0; i < countLessons; i++)
		{
			int sumGrades = 0;
			countGrade = 3 + rand() % 15; // рандомно назначаем количество оценок.
			double* grades = new double[countGrade];
			averageGrade = 0;

			for (int i = 0; i < countGrade; i++) { // рандомно назначаем оценки.
				grades[i] = 2 + rand() % 4;
				sumGrades = grades[i] + sumGrades; // считаем общее кол-во оценок для вычисления среднего значения.
			}
			
			averageGrade = sumGrades / countGrade; // ср. значение.
			cout << "Название предмета: " << arrayLessons[i] << endl; // выводим информацию.
			cout << "Количество оценок: " << countGrade << endl;
			cout << "Оценки: ";
			for (int i = 0; i < countGrade; i++) {
				cout << grades[i] << " ";
			}
			cout << endl;
			cout << "Средняя оценка: "; cout << setprecision(3) << averageGrade; cout << endl << endl;
		}
	}

private:
	Lesson** lesson; // массив с оценками.
	string title; // название предмета.
	double countGrade; // количество оценок.
	double averageGrade; // средняя оценка.
	int countLessons;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int countLessons = 10; // кол-во предметов.

	Lesson math;

	math.CreateLesson(countLessons);



}



















//Lesson(string _title, int _countGrade, double _averageGrade, double _grades[])
//	: title(_title), countGrade(_countGrade) {}; // member initializer list

//Lesson() {};

//Lesson(string _title, int _countGrade) {};