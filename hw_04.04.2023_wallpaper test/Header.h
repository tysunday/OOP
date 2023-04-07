//Написать программу «Стоимость обоев».Программа запрашивает :
//▷ количество комнат в квартире, в которых планируется клеить обои,
//▷ параметры каждой комнаты,
//▷ параметры каждого вида обоев, которые планируется использовать.
//В результате расчета программа выдает : необходимое
//количество рулонов каждого вида, общую стоимость
//закупки обоев.
//Разработать и  использовать в  программе классы :
//«Квартира», «Комната», «РулонОбоев».
//Атрибуты(поля) квартиры : список комнат.
//Атрибуты комнаты : название, размеры, клеить потолок
//или нет.Атрибуты рулона : название, размеры, цена.
#pragma once
#include <iostream>
using namespace std;

class Room {
public:
	Room(string typeRoom, float sizeRoom, bool GlueTheCeilingOrNot)
	{
		typeRoom = GetTypeRoom();
		sizeRoom = GetSizeRoom();
		GlueTheCeilingOrNot = GetGlueTheCeilingOrNot();
	}

	string GetTypeRoom() {
		return typeRoom;
	}
	string SetTypeRoom(string value) {
		cout << R"(Введите какая это комната:
		Ванная комната? Кухня? Гостиная? Спальня?)";
		cin >> value;
		typeRoom = value;
	};

	float GetSizeRoom() {
		return sizeRoom;
	}
	float SetSizeRoom(float value) {
		cout << "Введите размер комнаты: ";
		cin >> value;
		sizeRoom = value;
	};

	bool GetGlueTheCeilingOrNot() {
		return glueTheCeilingOrNot;
	}
	bool SetGlueTheCeilingOrNot(bool value) {
		cout << "Введите клеим потолок или нет? 1 - Клеим. 0 - Не клеим. \n";
		cin >> value;
		glueTheCeilingOrNot = value;
	};

private:
	string typeRoom; // тип комнаты (спальня, кухня...)
	float sizeRoom; // в квадратных метрах.
	bool glueTheCeilingOrNot; // клеим потолок обоями?
};

class Apartment {

public:
	Apartment (int countRoom) {
		rooms = new Room*[countRoom];
		for (int i = 0; i < countRoom; i++)
		{
			string type;
			float size;
			bool glue;
			cout << R"(Введите какая это комната:
		Ванная комната? Кухня? Гостиная? Спальня?)";
			cin >> type;
			cout << "Введите размер комнаты: ";
			cin >> size;
			cout << "Введите клеим потолок или нет? 1 - Клеим. 0 - Не клеим. \n";
			cin >> glue;
			rooms[i] = new Room(type, size, glue);
		}
	}

	Room* getRoom(int countRoom)
	{
		return rooms[countRoom];
	}

	int GetCountRoom() {// получить количество комнат
		return countRoom;
	}

	void SetCountRoom(int value) { // установить количество комнат 
		countRoom = value;
	};

private:
	int countRoom; // количество комнат
	Room** rooms;
};

class Wallpaper { 
public:
	string GetNameWallpaper() {
		return nameWallpaper;
	}
	string SetNameWallpaper(string value) {
		nameWallpaper = value;
	};

	int GetSizeWallpaper_length() {
		return sizeWallpaper_length;
	}
	int SetSizeWallpaper_length(int value) {
		sizeWallpaper_length = value;
	};

	int GetSizeWallpaper_width() {
		return sizeWallpaper_width;
	}
	int SetSizeWallpaper_width(int value) {
		sizeWallpaper_width = value;
	};

	int GetCost() {
		return cost;
	}
	int SetCost(int value) {
		cost = value;
	};

private:
	string nameWallpaper; // имя обоев
	int sizeWallpaper_length; //  размер обоев длина
	int sizeWallpaper_width; //  размер обоев ширина
	float cost; // цена обоев
};
