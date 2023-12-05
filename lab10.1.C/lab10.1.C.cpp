#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma execution_character_set("utf-8")

void convertToLowerCase(char* str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int hasAllLetters(const char* jdn, const char* word) {
    FILE* file = fopen(jdn, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", jdn);
        return 0;
    }

    char lettersInWord[6];  // Враховуємо нуль-термінатор
    strcpy(lettersInWord, word);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = tolower((unsigned char)ch);
        for (int i = 0; i < 5; i++) {
            if (lettersInWord[i] == ch) {
                lettersInWord[i] = ' ';
                break;
            }
        }

        int allLettersFound = 1;
        for (int i = 0; i < 5; i++) {
            if (lettersInWord[i] != ' ') {
                allLettersFound = 0;
                break;
            }
        }

        if (allLettersFound) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    const char* fileName = "jdn.txt";
    const char* wordToCheck = "while";

    if (hasAllLetters(fileName, wordToCheck)) {
        printf("File have all letters of word 'while'.\n");
    }
    else {
        printf("File don't have all letters of word 'while'.\n");
    }

    return 0;
}
