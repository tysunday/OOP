//Задание.
//Реализуйте класс Дробь.Необходимо хранить числитель
//и знаменатель в качестве переменных - членов.Реализуйте
//функции - члены для ввода данных в переменные - члены,
//для выполнения арифметических операций(сложение,
//вычитание, умножение, деление, и т.д.).

#include <iostream>
using namespace std;
int Evklid(int a, int b); // алгоритм Евклида для нахождения наибольшего делителя.
int NOD; // глобальная переменная наибольшего общего делителя.
void iff(); // для выделения целого числа (пока не выделяет целое число, но приводит к наименьшему общему делителю)

class Shot {
public:
	void VisionShot() {
		if (number == 0)
			cout << numerator << "/" << denominator << endl;
		else if (number >= 1)
			cout << number << " " << numerator << "/" << denominator << endl;
	}
	int number;
	int numerator;
	int denominator;
};

Shot ThirdNumber;

Shot Sum(Shot FirstNumber, Shot SecondNumber) {
	int generalNumerator;
	generalNumerator = FirstNumber.denominator * SecondNumber.denominator;
	FirstNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	SecondNumber.numerator = SecondNumber.numerator * FirstNumber.denominator;
	ThirdNumber.denominator = generalNumerator;
	ThirdNumber.numerator = FirstNumber.numerator + SecondNumber.numerator;
	cout << "Результат сложения: ";
	iff();
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Multiplied(Shot FirstNumber, Shot SecondNumber) {
	ThirdNumber.numerator = FirstNumber.numerator * SecondNumber.numerator;
	ThirdNumber.denominator = FirstNumber.denominator * SecondNumber.denominator;
	cout << "Результат умножения: ";
	iff();
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Division(Shot FirstNumber, Shot SecondNumber) {
	ThirdNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	ThirdNumber.denominator = FirstNumber.denominator * SecondNumber.numerator;
	cout << "Результат деления: ";
	iff();
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

Shot Subtraction(Shot FirstNumber, Shot SecondNumber)
{
	int generalNumerator;
	generalNumerator = FirstNumber.denominator * SecondNumber.denominator;
	FirstNumber.numerator = FirstNumber.numerator * SecondNumber.denominator;
	SecondNumber.numerator = SecondNumber.numerator * FirstNumber.denominator;
	ThirdNumber.denominator = generalNumerator;
	ThirdNumber.numerator = FirstNumber.numerator - SecondNumber.numerator;
	cout << "Результат вычитания: ";
	iff();
	ThirdNumber.VisionShot();
	return ThirdNumber;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Shot FirstNumber;
	FirstNumber.numerator = 15;
	FirstNumber.denominator = 5;

	cout << "Первая дробь: "; FirstNumber.VisionShot(); 

	Shot SecondNumber;
	SecondNumber.numerator = 3;
	SecondNumber.denominator = 7;

	cout << "Вторая дробь: "; SecondNumber.VisionShot(); 

	ThirdNumber = Sum(FirstNumber, SecondNumber);
	ThirdNumber = Multiplied(FirstNumber, SecondNumber);
	ThirdNumber = Division(FirstNumber, SecondNumber);
	ThirdNumber = Subtraction(FirstNumber, SecondNumber);
	
}

void iff()
{
	if (ThirdNumber.numerator > ThirdNumber.denominator)
	{
		NOD = Evklid(ThirdNumber.numerator, ThirdNumber.denominator);
		ThirdNumber.numerator = ThirdNumber.numerator / NOD;
		ThirdNumber.denominator = ThirdNumber.denominator / NOD;
	}
	if (ThirdNumber.numerator > ThirdNumber.denominator)
	{
		int number = 0;
		number = ThirdNumber.numerator / ThirdNumber.denominator;
		ThirdNumber.numerator = ThirdNumber.numerator % ThirdNumber.denominator;
	}
}

int Evklid(int a, int b) { 
	if (b == 0) {
		return a;
	}
	return Evklid(b, a % b);
}
