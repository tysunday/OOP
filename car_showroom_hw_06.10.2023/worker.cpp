#include "worker.h"

std::ostream& operator<<(std::ostream& out, const Worker& worker) {
	out << "Name -> " << worker.name << "\n";
	out << "Salary - > " << worker.salary << "\n";
	out << "Numbers of cars sold - >" << worker.countCarsSold << "\n";
	out << "Work - > ";
	if (worker.work) out << "YES\n";
	else out << "NO\n";
	return out;
}

std::istream& operator>>(std::istream& in, Worker& worker) {
	std::cout << "Name: ";
	in >> worker.name;
	std::cout << "Salary: ";
	in >> worker.salary;
	return in;
}

void Worker::FIRE() {
	std::cout << this->name << " уволен.\n";
	this->salary = 0;
	this->work = false;
}