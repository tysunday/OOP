//C помощью метода реализовать ввод данных работника с клавиатуры.
//Рассчитать с помощью методов заработную плату, за отработанное время, и премию, размер которой определяется в зависимости от стажа
//(при стаже до 1 года 0 %, до 3 лет 5 %, до 5 лет 8 %, свыше 5 лет 15 %).
//С помощью метода печати, реализовать вывод информации о работнике на экран.Предусмотреть метод для записи в файл данных о работнике.

#include <iostream>
#include <windows.h>
using namespace std;

class Worker
{
public:
	Worker(string secondName, float workersExperience, int workersHourlyWag, int countHoursWasWorked) :
		_secondName(secondName), _workersExperience(workersExperience), _workersHourlyWag(workersHourlyWag), _countHoursWasWorked(countHoursWasWorked) {}
	// конструктор для создания через метод объекта работник.

	Worker() {} // конструктор для инициализации объекта в main.

	Worker CreateWorker() {
		string secondName;
		float workersExperience{ 0 };
		int workersHourlyWag{ 0 }, countHoursWasWorked{ 0 };

		cout << "Введите фамилию работника: \n";
		cin >> secondName;
		cout << "Введите его стаж: \n";
		cin >> workersExperience;
		cout << "Введите какая у него заработная плата за час: \n";
		cin >> workersHourlyWag;
		cout << "Введите сколько часов отработал работник: \n";
		cin >> countHoursWasWorked;
		worker = new Worker(secondName, workersExperience, workersHourlyWag, countHoursWasWorked);
		cout << endl;
		return *worker;
	}

	float Salary() {
		// зарплата работника = зп.час * отраб.час + премия.
		float salary = worker->_workersHourlyWag * worker->_countHoursWasWorked + Premium(BasicSum());
		cout << "Зарплата = " << salary << endl;
		return salary;
	}

	float BasicSum() {
		// базовые выплаты = зп.час * отраб.час
		float BasicSum = worker->_workersHourlyWag * worker->_countHoursWasWorked;
		return BasicSum;
	}

	void WorkerInfo() {
		cout << "Фамилия работника: " << worker->_secondName << endl;
		cout << "Стаж работника: " << worker->_workersExperience << endl;
		cout << "Заработная плата за час: " << worker->_workersHourlyWag << endl;
		cout << "Часов отработал работник: " << worker->_countHoursWasWorked << endl;
		cout << endl;
	}

	float Premium(float basicSum) {
		float premium{ 0 };
		if (worker->_workersExperience > 1 && worker->_workersExperience < 3) {
			premium = basicSum * 0.05;
		}
		else if (worker->_workersExperience > 3 && worker->_workersExperience < 5) {

			premium = basicSum * 0.08;
		}
		else if (worker->_workersExperience > 5) {
			premium = basicSum * 0.15;
		}
		return premium;
	}

	string GetSecondName() { return _secondName; }
	float GetWorkersExperience() { return _workersExperience; }
	int GetWorkersHorulyWag() { return _workersHourlyWag; }
	int GetCountHourwsWasWorker() { return _countHoursWasWorked; }

private:
	string _secondName = ""; // фамилия работника.
	float _workersExperience; // исчисляется годами. (стаж)
	int _workersHourlyWag; // часовая заработная плата.
	int _countHoursWasWorked; // кол-во часов отработал работник.
	Worker* worker; // для создания объекта работник.
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Worker a;
	a.CreateWorker();
	a.WorkerInfo();
	a.BasicSum();
	a.Salary();

}

