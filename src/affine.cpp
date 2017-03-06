#include <iostream>
#include "affine.h"

#define ALPHABET_SIZE 26
#define ASCII_A_VALUE 65

namespace affine {
    int convertCharToInt(char c) {
        return std::toupper(c) - ASCII_A_VALUE;
    }

    char convertIntToChar(int i) {
        return char(i + ASCII_A_VALUE);
    }

    Affine::Affine(int a, int b) {
        this->a = a;
        this->b = b;

        int aModulo = a%ALPHABET_SIZE;
        for (int i = 1; i < ALPHABET_SIZE; i++) {
            if ((aModulo*i)%ALPHABET_SIZE == 1) {
                c = i;
                break;
            }
        }
    }

    std::string Affine::encrypt(std::string plainText) {
        std::string cipherText;
        for (char x : plainText) {
            cipherText += convertIntToChar((a*convertCharToInt(x) + b)%ALPHABET_SIZE);
        }
        return cipherText;
    }

    std::string Affine::decrypt(std::string cipherText) {
        std::string plainText;
        for (char y : cipherText) {
            plainText += convertIntToChar((c*(convertCharToInt(y) - b)%ALPHABET_SIZE + ALPHABET_SIZE)%ALPHABET_SIZE);
        }
        return plainText;
    }
}