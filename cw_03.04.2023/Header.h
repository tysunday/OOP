#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	int id;
	string password;
	string email;
	short cvc;
	string first_name;
	string last_name;
	string login;
	float countSalary(float priceHours, int hours, float ratio);

public:
	void GetSalary(float priceHours, int hours, float ratio);
	void getName(string name);
};

