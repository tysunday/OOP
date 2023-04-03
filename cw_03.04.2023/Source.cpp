#include "Header.h"

void User:: getName(string name) {
	cout << endl << name;
}

float User::countSalary(float priceHours, int hours, float ratio)
{
	float salary = priceHours * hours * ratio;
	return salary;
}

void User::GetSalary(float priceHours, int hours, float ratio)
{
	float result = countSalary(priceHours, hours, ratio);
	cout << result;
}