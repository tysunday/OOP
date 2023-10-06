#include "Car.h"

std::ostream& operator<<(std::ostream& out, const Car& car) {
	out << "Model: " << car.GetModel() << "\n";
	out << "Date of Manufacture: " << car.GetDateManufacture() << "\n";
	out << "Color: " << car.GetColor() << "\n";
	out << "Manufacturer: " << car.GetManufacturer() << "\n";
	out << "Country: " << car.GetCountry() << "\n";
	out << "Engine Capacity: " << car.GetEngineCapacity() << "\n";
	out << "Engine Power: " << car.GetEnginePower() << "\n";
	out << "Costs: " << car.GetCosts() << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Car& car) {
	std::string model, color, manufacturer, country;
	float engineCapacity, costs, enginePower;
	int dateManufacture;
	std::cout << "Model: ";
	in >> car.model;
	std::cout << "Date of Manufacture: ";
	in >> car.dateManufacture;
	std::cout << "Color: ";
	in >> car.color;
	std::cout << "Manufacturer: ";
	in >> car.manufacturer;
	std::cout << "Country: ";
	in >> car.country;
	std::cout << "Engine Capacity : ";
	in >> car.engineCapacity;
	std::cout << "Engine power: ";
	in >> car.enginePower;
	std::cout << "Costs: ";
	in >> car.costs;
	return in;
}