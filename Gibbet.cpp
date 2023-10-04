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
    ifstream file;
    string word;
    unordered_set<char> guess;
    static const vector<string> hangmanArt;

public:
    Gibbet() = default;
    explicit Gibbet(const string& f_) : file(f_), word(istream_iterator<char>(file), istream_iterator<char>())
    {
        Play();
    }

    void Play();
};

void Gibbet::Play()
{
    int maxAttempts = hangmanArt.size() - 1;
    int attempts = 0;

    while (attempts < maxAttempts)
    {
        cout << "Слово: ";
        bool allGuessed = true; // Флаг для отслеживания, все ли буквы угаданы
        for (char c : word)
        {
            if (guess.find(c) != guess.end())
                cout << c;
            else
            {
                cout << "#";
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
    "_________\n|       |\n|\n|\n|\n|\n|",
    "_________\n|       |\n|       O\n|\n|\n|\n|",
    "_________\n|       |\n|       O\n|       |\n|       |\n|\n|",
    "_________\n|       |\n|       O\n|      \\|\n|       |\n|\n|",
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|\n|",
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|      /\n|",
    "_________\n|       |\n|       O\n|      \\|/\n|       |\n|      / \\\n|" };

int main()
{
    setlocale(LC_ALL, "Russian");
    string fileName = "wordlist.txt";
    Gibbet g(fileName);

    return 0;
}
