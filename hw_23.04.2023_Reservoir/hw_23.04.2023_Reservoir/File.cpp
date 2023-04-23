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

void WriteObjectFiles(Reservouir* obj[]) {
	int i = 0;
	cout << "Введите длину какого водоёма вы хотите узнать: \n";
	cin >> i;
	cout << "Длина: \n";
	cout << obj[i]->getLength();
	cout << obj[i]->getName();
	cout << obj[i]->getDepth();
}
