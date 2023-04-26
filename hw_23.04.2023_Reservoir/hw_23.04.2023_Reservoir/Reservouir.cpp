#pragma once
#include "Header.h"
#include "Reservouir.h"
#include "File.h"

double Reservouir::getVolume() {
	_volume = this->_width * this->_length * this->_depth;
	return this->_volume;
}

void Reservouir::CreateReservouir() {
	int count = 0;
	int tempCount = 0;
	cout << "Сколько всего водоёмов вы хотите создать? \n";
	cin >> count;
	if (_count > 0) {
		Reservouir** TempReservouir;
		int tempCount = _count;
		_count += count;
		TempReservouir = new Reservouir * [_count];
		for (int i = 1; i <= tempCount; i++) {
			TempReservouir[i] = reservouir[i];
		}

		for (int i = tempCount + 1; i <= tempCount + count;i++) {
			cout << "Введите что это за водоём. Пруд, море, океан?\n";
			cin >> _type;
			cout << "Введите его название: \n";
			cin >> _name;
			cout << "Введите глубину: \n";
			cin >> _depth;
			cout << "Введите ширину: \n";
			cin >> _width;
			cout << "Введите длину: \n";
			cin >> _length;
			cout << "На основе представленных вами данных площадь водоёма приблизительно равна: \n";
			cout << getSquare() << endl;
			cout << "На основе представленных вами данных объём водоёма приблизительно равен: \n";
			cout << getVolume() << endl;

			TempReservouir[i] = new Reservouir(_type, _name, _depth, _width, _length, _square, _volume);
		}
		reservouir = new Reservouir * [_count];

		for (int i = 1; i <= _count; i++) {
			reservouir[i] = TempReservouir[i];
		}
	}
	else {
		reservouir = new Reservouir * [_count];

		for (int i = 1; i <= count;i++)
		{
			cout << "Введите что это за водоём. Пруд, море, океан?\n";
			cin >> _type;
			cout << "Введите его название: \n";
			cin >> _name;
			cout << "Введите глубину: \n";
			cin >> _depth;
			cout << "Введите ширину: \n";
			cin >> _width;
			cout << "Введите длину: \n";
			cin >> _length;
			cout << "На основе представленных вами данных площадь водоёма приблизительно равна: \n";
			cout << getSquare() << endl;
			cout << "На основе представленных вами данных объём водоёма приблизительно равен: \n";
			cout << getVolume() << endl;

			reservouir[i] = new Reservouir(_type, _name, _depth, _width, _length, _square, _volume);
			_count++;
		}
	}
}

double Reservouir::getSquare() {
	_square = _width * _length;
	return this->_square;
}

void Reservouir::ShowInfo() {
	cout << "О каком водоёме конкретно вы хотите узнать? \n";
	cout << "Есть такие как ";
	for (int i = 1; i <= _count; i++)
	{
		cout << "Водоём № " << i << endl;
		cout << "Имя: " << reservouir[i]->getName() << endl;
		cout << "Тип: " << reservouir[i]->getType() << endl;
	}
	cout << endl;

	int number = 0;
	cout << "Введите номер интересующего водоёма: \n";
	cin >> number;

	cout << "Информация о выбранном вами водоёме: \n";
	cout << "Тип: " << reservouir[number]->_type << endl;
	cout << "Название: " << reservouir[number]->_name << endl;
	cout << "Глубина: " << reservouir[number]->_depth << endl;
	cout << "Длина: " << reservouir[number]->_length << endl;
	cout << "Ширина: " << reservouir[number]->_width << endl;
	cout << "Площадь: " << reservouir[number]->_square << endl;
	cout << "Объём: " << reservouir[number]->_volume << endl;
}

void Reservouir::ShowAllInfo() {

	cout << "***Информация о всех водоёмах!*** \n";

	cout << "Всего водоёмов ! " << _count << endl;

	for (int i = 1; i <= _count; i++) {
		cout << "Водоём № " << i << endl;
		cout << "Тип: " << reservouir[i]->_type << endl;
		cout << "Название: " << reservouir[i]->_name << endl;
		cout << "Глубина: " << reservouir[i]->_depth << endl;
		cout << "Длина: " << reservouir[i]->_length << endl;
		cout << "Ширина: " << reservouir[i]->_width << endl;
		cout << "Площадь: " << reservouir[i]->_square << endl;
		cout << "Объём: " << reservouir[i]->_volume << endl << endl;
	}
}

