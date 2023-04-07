#include "Header.h"

int main()
{
	//int inputCountRoom = 0;
	setlocale(LC_ALL, "Russian");

	//cout << "Введите количество комнат в которых требуется сделать ремонт: ";
	//cin >> inputCountRoom;

	//Apartment room(inputCountRoom);

	//cout << "Количество комнат в которых требуется сделать ремонт : ";
	//cout << room.GetCountRoom();

	Apartment apartamenti(2);
	apartamenti.SetCountRoom(2);
	

	for (int i = 0; i < apartamenti.GetCountRoom();i++)
	{
		Room* room = apartamenti.getRoom(2);
		apartamenti.getRoom(i);
		cout << "Room " << i << " is a " << room->GetTypeRoom() << " and is ";
	}
	//apartamenti.getRoom(1);



}

