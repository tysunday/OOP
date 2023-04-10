#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int countRoom;
	cout << "Введите количество комнат в которых требуется поклейка обоев: ";
	cin >> countRoom;

	Apartment House;
	House.CreateRoom(countRoom);

	for (int i = 0; i < House.GetCountRoom(); i++)
	{
		Room* room = House.GetRoom(i);
		cout << "Комната № " << i << " называется: " << room->GetType()
			<< "\n её длина: " << room->GetLengthRoom()
			<< "\n высота: " << room->GetHeigthRoom() 
			<< "\n ширина: " << room->GetWidthRoom() 
			<< "\n клеить потолок в ней ";
		if (room->GetGlueTheCeilingOrNot() == 0)
			cout << "не будем\n";
		else if (room->GetGlueTheCeilingOrNot() == 1)
			cout << "будем\n";
		cout << "Площадь стен комнаты: " << room->GetRoomArea() << endl;
	}


	int countRolls;
	cout << "Введите количество разных обоев: ";
	cin >> countRolls;
	
	Wallpaper paper;
	paper.CreateWallpaper(countRolls);

	for (int i = 0; i < countRolls; i++) {
		Wallpaper wallpaper = paper.GetWallpaper(i);
		cout << "Обои № " << i << " называются " << wallpaper.GetNameWallpaper() << endl
			<< "Их длина: " << wallpaper.GetLengthWallpaper() << endl
			<< "Ширина: " << wallpaper.GetWidthWallpaper() << endl
			<< "Площадь одного рулона: " << wallpaper.GetRollArea() << endl
			<< "Стоимость: " << wallpaper.GetCostWallpaper() << endl;
	}

	int idRoom, idRoll, answer = 0;
	do {
		cout << "Введите id комнаты в которой будем клеить обои: \n";
		cin >> idRoom;
		cout << endl;

		Room* room = House.GetRoom(idRoom);

		cout << "Комната № " << idRoom << " называется: " << room->GetType()
			<< "\n её длина: " << room->GetLengthRoom()
			<< "\n высота: " << room->GetHeigthRoom()
			<< "\n ширина: " << room->GetWidthRoom()
			<< "\n клеить потолок в ней ";
		if (room->GetGlueTheCeilingOrNot() == 0)
			cout << "не будем\n";
		else if (room->GetGlueTheCeilingOrNot() == 1)
			cout << "будем\n";
		cout << "Площадь стен комнаты: " << room->GetRoomArea() << endl;


		cout << "Введите id обоев которые будете клеить: \n";
		cin >> idRoll;
		cout << endl;

		Wallpaper wallpaper = paper.GetWallpaper(idRoll);
		cout << "Обои № " << idRoll << " называются " << wallpaper.GetNameWallpaper() << endl
			<< "Их длина: " << wallpaper.GetLengthWallpaper() << endl
			<< "Ширина: " << wallpaper.GetWidthWallpaper() << endl
			<< "Площадь одного рулона: " << wallpaper.GetRollArea() << endl
			<< "Стоимость: " << wallpaper.GetCostWallpaper() << endl;


		cout << "Для поклейки этой комнаты этими обоями вам понадобится ";
		int result = 0;
		result = room->GetRoomArea() / wallpaper.GetRollArea();
		cout << result << "рулонов.";
		cout << "Введите 0 если хотите закончить или 1 если продолжить: \n";
		cin >> answer;
	} while (answer != 0);


}