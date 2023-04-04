// установка диапазона движения лифта
//включение выключение лифта
//возвращение текущего состояния лифта
//возвращение текущего положения
//обработка вызова лифта (этаж)
#include "Elevator.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	Elevator Vladislav;
	while (true) {
		Vladislav.MoveElevator();
	}
}
