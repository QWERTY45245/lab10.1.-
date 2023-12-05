#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <Windows.h>

using namespace std;

bool hasAllLetters(const string& fileName, const string& word) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << fileName << endl;
        return false;
    }

    set<char> lettersInWord(word.begin(), word.end());
    char ch;

    while (file >> ch) {
        lettersInWord.erase(ch);
        if (lettersInWord.empty()) {
            file.close();
            return true;  // Всі букви слова "while" знайдені у файлі
        }
    }

    file.close();
    return false;  // Якщо ця точка досягається, є принаймні одна буква, яка відсутня у файлі
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string fileName = "jdn.txt";
    string wordToCheck = "while";

    if (hasAllLetters(fileName, wordToCheck)) {
        cout << "У файлі є всі букви слова 'while'." << endl;
    }
    else {
        cout << "У файлі відсутні всі букви слова 'while'." << endl;
    }

    return 0;
}
