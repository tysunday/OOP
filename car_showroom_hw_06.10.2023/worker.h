#pragma once
#include "Header.h"
class Worker
{
public:
	Worker() = default;
	Worker(std::string _name, float _salary)
		: name(_name), salary(_salary), countCarsSold(0) {}

	friend std::ostream& operator<<(std::ostream& out, const Worker& worker);
	friend std::istream& operator>>(std::istream& in, Worker& worker);
	void FIRE(); // уволим-ка сотрудника.
private:
	std::string name;
	float salary;
	bool work = true;
	size_t countCarsSold = 0;
};

