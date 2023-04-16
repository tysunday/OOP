#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Grade {
public:
	string* Ptitle = titleGrade; // указатель на массив с предметами.

private:
	string titleGrade[10] = { "Math", "Spanish Language", "Russian Language", "Programming",
		"Physics", "PE", "History", "Science", "Art", "Basic military training" };
};

class GroupOfStudents {
public:
	string* PtitleGroup = titleGroup;
	string* PsubjectList = subjectList;
	string* PnameStudents = nameStudents; // указатель на массив с именами студентов.

	void CreateGroupOfStudents()
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << "Группа №" << i << " называется: " << titleGroup[i - 1] << endl;
			cout << "В ней учатся: ";
			for (int j = (i - 1) * 5; j < (i * 5); j++)
			{
				cout << nameStudents[j] << " ";
			}
			cout << endl;

			cout << "У группы " << titleGroup[i - 1] << " есть такие предметы как: " << endl;

			int count = 5 + rand() % 8; // кол-во предметов у группы берём рандомное.
			for (int l = 0; l < count; l++)
			{
				int numTitleGrade = 1 + rand() % 10;
				grades.Ptitle[numTitleGrade];

				bool flag = true;
				string* arrTitleGrade = new string[count];

				for (int x = 0; x < count; x++)
				{
					if (grades.Ptitle[numTitleGrade] == arrTitleGrade[x])
					{
						flag = false;
					}
				}
			}

			cout << endl << endl;
		}
	}

private:
	string titleGroup[3] = { "Army", "BV211", "PB211" }; // название группы  
	string nameStudents[15] = { "Oleg", "Maksim", "Vladislav", "Alena", "Ali", "Dmitriy", "Evgeniy",
		"Nastya", "Mihail", "Ruslan", "Danil", "Alexander", "Olga", "Ekaterina", "Viktoria" }; // имена студентов
	string* subjectList = new string[10]; // список предметов
	Grade grades;
};

class Student {
public:


private:
	string nameStudent;
	double* gradeList = new double[gradeCount]; // список оценок
	int gradeCount; // кол-во оценок
};








int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GroupOfStudents group;
	group.CreateGroupOfStudents();

}

