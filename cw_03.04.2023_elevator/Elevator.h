#pragma once
#include <iostream>
using namespace std;
class Elevator
{
public:
	int MoveElevator()
	{
		cout << "������ �� �� �����:" << currentFloors << endl;
		cout << "�� ����� ��� ����? \n";
		cout << "����� ������ : \n";
		for (int i = floors[0]; i < floors[11]; i++) {
			cout << "����: " << i << "\n";
		}
		cin >> desiredFloor;
		system("cls");
		while (desiredFloor > 9 || desiredFloor < -1)
		{
			cout << "������ �� �� �����:" << currentFloors << endl;
			cout << "������ ����� ���, ���������� ��� ���:\n";
			cout << "����� ������ : \n";
			for (int i = floors[0]; i < floors[11]; i++) {
				cout << "����: " << i << "\n";
			}
			cin >> desiredFloor;
			system("cls");
		}
		currentFloors = desiredFloor;
		return currentFloors;
	}
private:
	int floors[12]{ -1,0,1,2,3,4,5,6,7,8,9,10 }; // �����
	int currentFloors = 0; // ������� ����
	int desiredFloor; // �������� ����
	bool togle; // ��� ����?
};

