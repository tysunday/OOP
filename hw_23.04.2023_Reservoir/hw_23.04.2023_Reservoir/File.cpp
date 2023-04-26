#pragma once
#include "Header.h"
#include "Reservouir.h"

void VisionFile()
{
	cout << "Доступные файлы: \n";
	fs::path current_path = fs::current_path();

	// Проходим по всем файлам в папке с проектом
	for (const auto& entry : fs::directory_iterator(current_path)) {
		// Проверяем, является ли файл текстовым файлом
		if (entry.path().extension() == ".txt") {
			// Выводим имя текстового файла на экран
			cout << entry.path().filename() << endl;
		}
	}
}

void CreatedFile() {
	cout << "Введите название файла для его создания: \n";
	string path;
	cin >> path;
	string temp = path;
	path = path + ".txt";
	ofstream fout;
	fout.open(path);
	path = temp;

	fout.is_open();
	if (!fout.is_open())
		cout << "Файл не открыт. \n";
	else cout << "Файл успешно открыт. \n";
}

void WriteInFile() {
	cout << "Введите название файла в который будем записывать информацию: \n";
	string path;
	cin >> path;
	path = path + ".txt";
	ofstream fout(path);
	cout << "Введите текст: \n";
	string sentence;
	cin.ignore();
	getline(cin, sentence, '*');
	fout << sentence;
	fout.close();
}

void ReadFile() {
	string path;
	cout << "Введите название файла для чтения: \n";
	cin >> path;
	path = path + ".txt";
	ifstream fin(path);
	string sentence;
	while (getline(fin, sentence)) {
		cout << sentence << endl;
	}
	fin.close();

}

void RemoveFile()
{
	string nameRemoveFile;
	cout << "Введите название файла которое вы хотите удалить\n";
	nameRemoveFile = nameRemoveFile + ".txt";
	cin >> nameRemoveFile;
	remove(nameRemoveFile.c_str()); // c_str нужен для преобразования объекта string в С - строку т.е. указатель на массив символов типа const char*
}


void WriteObjectInFiles(Reservouir** obj, Reservouir& x) {
	string file;
	cout << "В какой файл будем записывать информацию?\n";
	VisionFile();
	cin.ignore();
	getline (cin, file);
	//system("pause"); system("cls");
	file = file + ".txt";
	ofstream fout;
	fout.open(file);
	cout << "file = file + \".txt\"";
	cout << "Введите номер объекта информацию о котором мы будем вносить файл:\n ";
	x.ShowAllInfo();
	int i = 0;
	to_string(i);
	cin >> i;
	string information;
	information += "Тип: " + obj[i]->getType() + "\n";
	information += "Имя: " + obj[i]->getName() + "\n";
	information += "Глубина: " + to_string(obj[i]->getDepth()) + "\n";
	information += "Ширина: " + to_string(obj[i]->getWidth()) + "\n";
	information += "Длина: " + to_string(obj[i]->getLength()) + "\n";
	information += "Площадь: " + to_string(obj[i]->getSquare()) + "\n";
	information += "Объем: " + to_string(obj[i]->getVolume()) + "\n";
	fout << information;
	fout.close();
}