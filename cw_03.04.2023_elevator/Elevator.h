#pragma once
#include <iostream>
using namespace std;
class Elevator
{
public:
	int MoveElevator()
	{
		cout << "Сейчас вы на этаже:" << currentFloors << endl;
		cout << "На какой вам этаж? \n";
		cout << "Всего этажей : \n";
		for (int i = floors[0]; i < floors[11]; i++) {
			cout << "Этаж: " << i << "\n";
		}
		cin >> desiredFloor;
		system("cls");
		while (desiredFloor > 9 || desiredFloor < -1)
		{
			cout << "Сейчас вы на этаже:" << currentFloors << endl;
			cout << "Такого этажа нет, попробуйте ещё раз:\n";
			cout << "Всего этажей : \n";
			for (int i = floors[0]; i < floors[11]; i++) {
				cout << "Этаж: " << i << "\n";
			}
			cin >> desiredFloor;
			system("cls");
		}
		currentFloors = desiredFloor;
		return currentFloors;
	}
private:
	int floors[12]{ -1,0,1,2,3,4,5,6,7,8,9,10 }; // этажи
	int currentFloors = 0; // текущий этаж
	int desiredFloor; // желаемый этаж
	bool togle; // вкл выкл?
};

