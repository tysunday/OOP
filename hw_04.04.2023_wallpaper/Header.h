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



class Apartment {

public:
	int GetCountRoom() {// получить количество комнат
		return countRoom;
	}
	int SetCountRoom(int value) { // установить количество комнат 
		countRoom = value;
	};
	void Calculation() {
	}

private:
	int countRoom; // количество комнат
};

class Room : public Apartment { // здесь я наследовал все публичные методы класса Apartment классу Room
public:
	string GetTypeRoom() {
		return typeRoom;
	}
	string SetTypeRoom(string value) {
		typeRoom = value;
	};

	float GetSizeRoom() {
		return sizeRoom;
	}
	float SetSizeRoom(float value) {
		sizeRoom = value;
	};

	bool GetGlueTheCeilingOrNot() {
		return glueTheCeilingOrNot;
	}
	bool SetGlueTheCeilingOrNot(bool value) {
		glueTheCeilingOrNot = value;
	};

private:
	string typeRoom; // тип комнаты (спальня, кухня...)
	float sizeRoom; // в квадратных метрах.
	bool glueTheCeilingOrNot; // клеим потолок обоями?
};

class Wallpaper : public Room { // здесь я наследовал все публичные методы класса Room классу Wallpaper
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
