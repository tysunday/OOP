
#include "Header.h"
#include "Reservouir.h"
#include "File.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Reservouir x;
	x.CreateReservouir();
	WriteObjectFiles(x.getMassiveObj());
}
  