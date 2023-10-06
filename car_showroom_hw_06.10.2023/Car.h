#pragma once
#include "Header.h"
class Car
{
public:
	Car() 
		: model("unknown"), dateManufacture(0), color("unknown"), manufacturer("unknown"), country("unknown"), engineCapacity(0), enginePower(0), costs(0) {}

	Car(std::string _model, int _dateManufacture, std::string _color, std::string _manufacturer, std::string _country, float _engineCapacity, float _enginePower, float _costs)
		: model(_model), dateManufacture(_dateManufacture), color(_color), manufacturer(_manufacturer), country(_country), engineCapacity(_engineCapacity), enginePower(_enginePower), costs(_costs) {}

	std::string GetModel() const { return model; }
	int GetDateManufacture() const { return dateManufacture; }
	std::string GetColor() const{ return color; }
	std::string GetManufacturer() const { return manufacturer; }
	std::string GetCountry() const{ return country; }
	float GetEngineCapacity() const { return engineCapacity; }
	float GetEnginePower() const { return enginePower; }
	float GetCosts() const { return costs; }
	

	friend std::ostream& operator<<(std::ostream& out, const Car& car);
	friend std::istream& operator>>(std::istream& in, Car& car);

private:
	std::string model;
	int dateManufacture;
	std::string color;
	std::string manufacturer;
	std::string country;
	float engineCapacity;
	float enginePower;
	float costs;
};

