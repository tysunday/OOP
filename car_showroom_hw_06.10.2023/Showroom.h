#pragma once
#include "Car.h"
#include "worker.h"

std::ostream& operator<<(std::ostream& out, const std::vector<Car>& cars);
std::ostream& operator<<(std::ostream& out, const std::vector<Worker>& workers);

class Showroom
{
public:
	friend std::ostream& operator<<(std::ostream& out, const std::vector<Car>& cars);
	friend std::ostream& operator<<(std::ostream& out, const std::vector<Worker>& workers);
	friend std::ostream& operator<<(std::ostream& out, const Showroom& showroom);
	
	std::vector<Car> GetCars() const { return cars; }
	std::vector<Worker> GetWorkers() const { return workers; }

	void AddCar() {
		Car car;
		std::cin >> car;
		cars.push_back(car);
	}

	void AddWorker() {
		Worker worker;
		std::cin >> worker;
		workers.push_back(worker);
	}

private:
	std::vector <Car> cars;
	std::vector <Worker> workers;
	float CashRegister;
};