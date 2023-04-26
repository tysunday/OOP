
#include "Header.h"
#include "Reservouir.h"
#include "File.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Reservouir object;
	
	cout << "Добро пожаловать, наверняка вы хотите внести информацию о каком-нибудь водоёме\n";
	cout << R"(Выберите интересующую вас функцию:
		1 - Создание информации о каком-либо водоёме
		2 - Показать информацию о каком-либо водоёме
		3 - Записать в файл информацию о каком-либо водоёме
		4 - Получить информацию обо всех водоёмах
		9 - Выйти из программы)" << endl << endl;
	int answer;
	cin >> answer;
	while (true) {
		switch (answer) {
		case 1:
			object.CreateReservouir();
			system("pause");
			system("cls");
			break;
		case 2:
			object.ShowInfo();
			system("pause");
			system("cls");
			break;
		case 3:
			WriteObjectInFiles(object.getMassiveObj(), object);
			system("pause");
			system("cls");
			break;
		case 4:
			object.ShowAllInfo();
			system("pause");
			system("cls");
			break;
		}
		cout << R"(Выберите интересующую вас функцию:
		1 - Создание информации о каком-либо водоёме
		2 - Показать информацию о каком-либо водоёме
		3 - Записать в файл информацию о каком-либо водоёме
		4 - Получить информацию обо всех водоёмах
		9 - Выйти из программы)" << endl << endl;
		cin >> answer;
	}
}