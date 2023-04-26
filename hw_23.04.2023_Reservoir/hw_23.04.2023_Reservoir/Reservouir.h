#pragma once
#include "Header.h"

class Reservouir
{
public:
	Reservouir() {}
	Reservouir(string type, string name, double depth, double width, double length, double square, double volume)
		: _type(type), _name(name), _depth(depth), _width(width), _length(length), _square(square), _volume(volume) {}

	void CreateReservouir();
	void ShowInfo();
	void ShowAllInfo();

	double getVolume(); // объём
	double getSquare(); // площадь

	string getType() { return _type; }
	string getName() { return _name; }
	double getDepth() { return _depth; }
	double getWidth() { return _width; }
	double getLength() { return _length; }
	Reservouir** getMassiveObj() { return reservouir; }
	int getCount() { return _count; }

	~Reservouir() {
		cout << "***********************Деструктор сработал\n\n";
	}

private:
	Reservouir** reservouir;

	string _type; // ТИП - море? океан? пруд?
	string _name;
	double _depth; // глубина
	double _square;
	double _width;
	double _length;
	int _count = 0;
	double _volume;
};