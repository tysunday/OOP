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
#include <Windows.h>
#include <cmath>
using namespace std;

class Room {

public:
	Room(string type, int lengthRoom, int widthRoom, int heightRoom, bool glueTheCeilingOrNot, int roomArea) :
		_typeRoom(type), _lengthRoom(lengthRoom), _widthRoom(widthRoom), _heightRoom(heightRoom), _glueTheCeilingOrNot(glueTheCeilingOrNot), _roomArea(roomArea) {}

	string GetType() { return _typeRoom; }
	int GetLengthRoom() { return _lengthRoom; }
	int GetWidthRoom() { return _widthRoom; }
	int GetHeigthRoom() { return _heightRoom; }
	int GetRoomArea() { return _roomArea;  }
	bool GetGlueTheCeilingOrNot() { return _glueTheCeilingOrNot; }


	// member initializer list - это особый синтаксис с++
	// при котором поля внутри тела конструктора будут инициализироваться сразу значениями переданными в параметры 
	// конструктора что позволяет избежать лишних вычислений. Иным образом они бы сначала записывались 
	// значениями по умолчанию, а далее уже бы перезаписывались значениями переданными в параметры конструктора.

private:
	string _typeRoom; // тип комнаты (спальня, кухня...)
	int _widthRoom; // ширина комнаты.
	int _lengthRoom; // длина комнаты.
	int _heightRoom; // высота комнаты.
	bool _glueTheCeilingOrNot; // клеим потолок обоями?
	int _roomArea; // площадь комнаты.
};

class Apartment {
public:
	void CreateRoom(int _countRoom)
	{
		countRoom = _countRoom;
		rooms = new Room * [countRoom];
		for (int i = 0; i < countRoom; i++)
		{
			string type = "";
			int lengthRoom = 0, heightRoom = 0, widthRoom = 0, roomArea = 0;
			bool glueTheCeilingOrNot = 0;
			cout << "Введите название комнаты: ";
			cin >> type;
			cout << "Введите длину комнаты: ";
			cin >> lengthRoom;
			cout << "Ширину: ";
			cin >> widthRoom;
			cout << "Высоту: ";
			cin >> heightRoom;
			roomArea = (lengthRoom * heightRoom) + (widthRoom * heightRoom);
			cout << "Будем клеить потолок? 1 - да, 0 - нет: ";
			cin >> glueTheCeilingOrNot;
			rooms[i] = new Room(type, lengthRoom, widthRoom, heightRoom, glueTheCeilingOrNot, roomArea);
			cout << "\n\n";
		}
	}

	int GetCountRoom() { return countRoom; }
	// кол-во комнат.

	Room* GetRoom(int i) { return rooms[i]; }
	// для создания объекта.

private:
	int countRoom; // количество комнат.
	Room** rooms; // массив для создания объектов "комната".
};

class Wallpaper {
public:
	Wallpaper() {}
	Wallpaper(string _nameRoll, int _lengthRoll, int _widthRoll, float _cost, int _rollArea) :
		nameRoll(_nameRoll), rollLength(_lengthRoll), rollWidth(_widthRoll), cost(_cost), rollArea(_rollArea)  {}

	void CreateWallpaper(int typeRolls)
	{
		arrayRolls = new Wallpaper * [typeRolls];
		for (int i = 0; i < typeRolls; i++)
		{
			string nameRoll;
			int rollLength = 0, rollWidth = 0, rollArea = 0;
			float cost = 0;
			cout << "Введите название рулона: ";
			cin >> nameRoll;
			cout << "Введите длину рулона: ";
			cin >> rollLength;
			cout << "Введите ширину рулона: ";
			cin >> rollWidth;
			cout << "Введите стоимость рулона: ";
			cin >> cost; 
			rollArea = rollLength * rollWidth; // площадь одного рулона.
			arrayRolls[i] = new Wallpaper(nameRoll, rollLength, rollWidth, cost, rollArea);
		}
	}

	Wallpaper GetWallpaper(int i) { return *arrayRolls[i]; }
	string GetNameWallpaper() { return nameRoll; }
	int GetLengthWallpaper() { return rollLength; }
	int GetWidthWallpaper() { return rollWidth; }
	float GetCostWallpaper() { return cost; }
	int GetRollArea() { return rollArea; }

private:
	string nameRoll; // имя обоев.
	int rollLength; //  размер обоев длина.
	int rollWidth; //  размер обоев ширина.
	int rollArea; // площадь одного рулона обоев.
	Wallpaper** arrayRolls; // массив с объектами рулонов.
	int typeRolls; // количество видов рулонов.
	float cost; // цена обоев.
};
