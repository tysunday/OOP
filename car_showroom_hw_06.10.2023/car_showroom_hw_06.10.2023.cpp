#include "Showroom.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Showroom showroom;
	showroom.AddCar();
	showroom.AddCar();
	std::cout << showroom.GetCars();
}