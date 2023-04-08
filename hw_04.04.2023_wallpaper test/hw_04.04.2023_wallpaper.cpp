#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//int countRoom;
	//cout << "Введите количество комнат в которых требуется поклейка обоев: ";
	//cin >> countRoom;
	//Apartment House;
	//House.CreateRoom(countRoom);
	//for (int i = 0; i < House.GetCountRoom(); i++)
	//{
	//	
	//	Room* room = House.GetRoom(i);
	//	cout << "Комната № " << i + 1 << " называется: " << room->GetType() <<
	//		"\n её длина: " << room->GetLengthRoom()
	//		<< "\n высота: " << room->GetHeigthRoom() << 
	//		"\n ширина: " << room->GetWidthRoom() << "\n клеить потолок в ней ";
	//	if (room->GetGlueTheCeilingOrNot() == 0)
	//		cout << "будем\n";
	//	else if (room->GetGlueTheCeilingOrNot() == 1)
	//		cout << "не будем\n";
	//}

	//int roomArea = countRoom;
	//int *ArrayRoomArea = new int[roomArea];

	//for (int i = 0; i < countRoom; i++)
	//{
	//	ArrayRoomArea[i] = House.GetRoomArea(i);
	//	cout << "Периметр комнаты № " << i + 1 << " = " << ArrayRoomArea[i] << endl;;
	//}
	

	Wallpaper paper;
	paper.CreateWallpaper(2);

	for (int i = 0; i < 2; i++) {
		Wallpaper wallpaper = paper.GetWallpaper(i);
		cout << "Обои № " << i << " называются " << wallpaper.GetNameWallpaper() << endl << "Их длина: " << wallpaper.GetLengthWallpaper() << endl
			<< "Ширина: " << wallpaper.GetWidthWallpaper() << endl << "Стоимость: " << wallpaper.GetCostWallpaper() << endl;
	}
}

//Wallpaper white;
//int roolArea = white.CalculationAreaRoll();
//cout << "Площадь одного рулона = " << roolArea;

//int countOfRools; 
//countOfRools = ArrayRoomArea[0] / roolArea;
//cout << "\n\nНеобходимо рулонов: " << countOfRools;