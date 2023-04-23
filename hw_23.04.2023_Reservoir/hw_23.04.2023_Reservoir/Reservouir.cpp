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
	cout << "������� ����� �������? \n";
	cin >> count;
	reservouir = new Reservouir * [count];
	for (int i = 1; i <= count;i++)
	{
		cout << "������� ��� ��� �� �����. ����, ����, �����?\n";
		cin >> _type;
		cout << "������� ��� ��������: \n";
		cin >> _name;
		cout << "������� �������: \n";
		cin >> _depth;
		cout << "������� ������: \n";
		cin >> _width;
		cout << "������� �����: \n";
		cin >> _length;
		cout << "�� ������ �������������� ���� ������ ������� ������ �������������� �����: \n";
		cout << getSquare() << endl;
		cout << "�� ������ �������������� ���� ������ ����� ������ �������������� �����: \n";
		cout << getVolume() << endl;

		reservouir[i] = new Reservouir(_type, _name, _depth, _width, _length, _square, _volume);
		_count++;
	}
}

double Reservouir::getSquare() {
	_square = _width * _length;
	return this->_square;
}

void Reservouir::ShowInfo() {
	cout << "� ����� ������ ��������� �� ������ ������? \n";
	cout << "���� ����� ��� ";
	for (int i = 1; i <= _count; i++)
	{
		cout << "����� � " << i << endl;
		cout << "���: " << reservouir[i]->getName() << endl;
		cout << "���: " << reservouir[i]->getType() << endl;
	}
	cout << endl;

	int number = 0;
	cout << "������� ����� ������������� ������: \n";
	cin >> number;

	cout << "���������� � ��������� ���� ������: \n";
	cout << "���: " << reservouir[number]->_type << endl;
	cout << "��������: " << reservouir[number]->_name << endl;
	cout << "�������: " << reservouir[number]->_depth << endl;
	cout << "�����: " << reservouir[number]->_length << endl;
	cout << "������: " << reservouir[number]->_width << endl;
	cout << "�������: " << reservouir[number]->_square << endl;
	cout << "�����: " << reservouir[number]->_volume << endl;
}

void Reservouir::ShowAllInfo() {

	cout << "***���������� � ���� �������!*** \n";

	for (int i = 1; i <= _count; i++) {
		cout << "����� � " << i << endl;
		cout << "���: " << reservouir[i]->_type << endl;
		cout << "��������: " << reservouir[i]->_name << endl;
		cout << "�������: " << reservouir[i]->_depth << endl;
		cout << "�����: " << reservouir[i]->_length << endl;
		cout << "������: " << reservouir[i]->_width << endl;
		cout << "�������: " << reservouir[i]->_square << endl;
		cout << "�����: " << reservouir[i]->_volume << endl << endl;
	}
}

