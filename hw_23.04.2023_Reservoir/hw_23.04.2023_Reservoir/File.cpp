#pragma once
#include "Header.h"
#include "Reservouir.h"

void VisionFile()
{
	cout << "��������� �����: \n";
	fs::path current_path = fs::current_path();

	// �������� �� ���� ������ � ����� � ��������
	for (const auto& entry : fs::directory_iterator(current_path)) {
		// ���������, �������� �� ���� ��������� ������
		if (entry.path().extension() == ".txt") {
			// ������� ��� ���������� ����� �� �����
			cout << entry.path().filename() << endl;
		}
	}
}

void CreatedFile() {
	cout << "������� �������� ����� ��� ��� ��������: \n";
	string path;
	cin >> path;
	string temp = path;
	path = path + ".txt";
	ofstream fout;
	fout.open(path);
	path = temp;

	fout.is_open();
	if (!fout.is_open())
		cout << "���� �� ������. \n";
	else cout << "���� ������� ������. \n";
}

void WriteInFile() {
	cout << "������� �������� ����� � ������� ����� ���������� ����������: \n";
	string path;
	cin >> path;
	path = path + ".txt";
	ofstream fout(path);
	cout << "������� �����: \n";
	string sentence;
	cin.ignore();
	getline(cin, sentence, '*');
	fout << sentence;
	fout.close();
}

void ReadFile() {
	string path;
	cout << "������� �������� ����� ��� ������: \n";
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
	cout << "������� �������� ����� ������� �� ������ �������\n";
	nameRemoveFile = nameRemoveFile + ".txt";
	cin >> nameRemoveFile;
	remove(nameRemoveFile.c_str()); // c_str ����� ��� �������������� ������� string � � - ������ �.�. ��������� �� ������ �������� ���� const char*
}


void WriteObjectInFiles(Reservouir** obj, Reservouir& x) {
	string file;
	cout << "� ����� ���� ����� ���������� ����������?\n";
	VisionFile();
	cin.ignore();
	getline (cin, file);
	//system("pause"); system("cls");
	file = file + ".txt";
	ofstream fout;
	fout.open(file);
	cout << "file = file + \".txt\"";
	cout << "������� ����� ������� ���������� � ������� �� ����� ������� ����:\n ";
	x.ShowAllInfo();
	int i = 0;
	to_string(i);
	cin >> i;
	string information;
	information += "���: " + obj[i]->getType() + "\n";
	information += "���: " + obj[i]->getName() + "\n";
	information += "�������: " + to_string(obj[i]->getDepth()) + "\n";
	information += "������: " + to_string(obj[i]->getWidth()) + "\n";
	information += "�����: " + to_string(obj[i]->getLength()) + "\n";
	information += "�������: " + to_string(obj[i]->getSquare()) + "\n";
	information += "�����: " + to_string(obj[i]->getVolume()) + "\n";
	fout << information;
	fout.close();
}