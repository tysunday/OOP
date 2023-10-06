#include "Showroom.h"

std::ostream& operator<<(std::ostream& out, const std::vector<Car>& cars) {
    size_t i = 1;
    for (const auto& car : cars) {
        out << "Car #" << i << ":\n" << car << '\n';
        i++;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const std::vector<Worker>& workers) {
    size_t i = 1;
    for (const auto& worker : workers) {
        out << "Worker #" << i << ":\n" << worker << '\n';
        i++;
    }
    return out;
}


std::ostream& operator<<(std::ostream& out, const Showroom& showroom) {
	out << "Cars in showroom:\n" << showroom.GetCars();  
	out << "Workers in showroom:\n" << showroom.GetWorkers();  
	return out;
}