#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

class Gibbet
{
private:
    ifstream file;               // Поток для чтения файла
    string word;                 // Слово для угадывания
    unordered_set<char> guess;   // Угаданные символы
    static const vector<string> hangmanArt;  // ASCII искусство для виселицы

public:
    Gibbet() = default;
    explicit Gibbet(const string& f_) : file(f_), word(istream_iterator<char>(file), istream_iterator<char>())
    {
        Play();  // Начать игру
    }

    void Play();  // Функция для игры
};

void Gibbet::Play()
{
    int maxAttempts = hangmanArt.size() - 1;  // Максимальное количество попыток
    int attempts = 0;  // Текущее количество попыток

    while (attempts < maxAttempts)
    {
        cout << "Слово: ";
        bool allGuessed = true; // Флаг для отслеживания, все ли буквы угаданы
        for (char c : word)
        {
            if (guess.find(c) != guess.end())
                cout << c;  // Если буква угадана, выводим её
            else
            {
                cout << "#";  // Если буква не угадана, выводим #
                allGuessed = false;
            }
        }

        cout << "\nПопыток осталось: " << maxAttempts - attempts << "\n";

        if (allGuessed) // Проверяем, все ли буквы угаданы
        {
            cout << "Вы победили! Слово: " << word << "\n";
            return;
        }

        cout << "Введите букву или всё слово: ";
        string input;
        cin >> input;

        if (input.size() == 1)
        {
            char letter = tolower(input[0]);

            if (guess.find(letter) != guess.end())
            {
                cout << "Вы уже угадали эту букву.\n";
                continue;
            }

            guess.insert(letter);

            if (word.find(letter) == string::npos)
                attempts++;
        }
        else if (input.size() == word.size() && input == word)
        {
            cout << "Вы победили! Слово: " << word << "\n";
            return;
        }
        else
        {
            cout << "Неверное слово.\n";
            attempts++;
        }

        cout << "\n" << hangmanArt[attempts] << "\n\n";

        if (attempts >= maxAttempts)
        {
            cout << "Вы проиграли! Слово было: " << word << "\n";
            return;
        }
    }
}

const vector<string> Gibbet::hangmanArt = {
    "_________\n|       |\n|\n|\n|\n|\n|",  // Пустая виселица
    "_________\n|       |\n|       O\n|\n|\n|\n|",  // Первая стадия: голова
    "_________\n|       |\n|       O\n|       |\n|       |\n|\n|",  // Вторая стадия: голова и туловище
    "_________\n|       |\n|       O\n|      \\|\n|       |\n|\n|",  // Третья стадия: голова, туловище, и одна нога
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|\n|",  // Четвертая стадия: голова, туловище, и две ноги
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|      / \\\n|",  // Пятая стадия: голова, туловище, две ноги, и одна рука
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|      / \\\n|" };  // Шестая стадия: голова, туловище, две ноги, и две руки

int main()
{
    setlocale(LC_ALL, "Russian");  // Установка русской локали для корректного вывода
    string fileName = "wordlist.txt";  // Имя файла со словами
    Gibbet g(fileName);  // Создание объекта игры

    return 0;
}
