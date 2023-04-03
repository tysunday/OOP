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
		for (int i = floors[0]; i < floors[11]; i++) {
			cout << "Этаж:" << "\n";
		}
		cin >> desiredFloor;
		while (desiredFloor > 10 && desiredFloor < -1)
		{
			cout << "Всего этажей : \n";
			cout << "Такого этажа нет, попробуйте ещё раз:\n";
			cin >> desiredFloor;
		}
		currentFloors = desiredFloor;
		return currentFloors;
	}
private:

	int floors[12]{ -1,0,1,2,3,4,5,6,7,8,9,10 }; // этажи
	int currentFloors; // текущий этаж
	int desiredFloor; // желаемый этаж
	bool togle; // вкл выкл?
};

