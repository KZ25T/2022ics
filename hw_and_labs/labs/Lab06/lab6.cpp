#include <cstdint>
#include <iostream>
#include <fstream>

#define LENGTH 3
#define MAXLEN 100

int16_t shiftLeft(int16_t a, int16_t n) {
    // assert n >= 0
    while (n > 0) {
        a += a;
        --n;
    }
    return a;
}

int16_t lab1(int16_t a, int16_t b) {
    int16_t cnt = 0;
    for (int16_t i = 0; i < b; ++i) {
        if (a & shiftLeft(1, i)) {
            ++cnt;
        }
    }
    return cnt;
}

int16_t lab2(int16_t p, int16_t q, int16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int16_t last1 = 1, last2 = 1, cur = 1;
    n -= 2;
    p -= 1;
    while (n >= 0) {
        last2 = last1;
        last1 = cur;
        while (cur >= 0) {
            cur -= q;
        }
        cur += q;
        cur += last2 & p; 
        --n;
    }
    return cur;
}

int16_t lab3(int16_t n, char s[]) {
    int16_t curLength = 1, maxLength = 0;
    for (int16_t i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            ++curLength;
        } else {
            if (curLength > maxLength) {
                maxLength = curLength;
            }
            curLength = 1;
        }
    }
    if (curLength > maxLength) {
        maxLength = curLength;
    }
    return maxLength;
}

void lab4(int16_t score[], int16_t *a, int16_t *b) {
    for (int16_t i = 1; i < 16; ++i) {
        int16_t j = i;
        int16_t t = score[j];
        while (j > 0 && t < score[j - 1]) {
            score[j] = score[j - 1];
            --j;
        }
        score[j] = t;
    }
    *a = 0;
    *b = 0;
    for (int16_t i = 15; i >= 8; --i) {
        if (score[i] >= 85 && score[i] >= score[12]) {
            *a += 1;
        } else if (score[i] >= 75 && score[i] >= score[8]) {
            *b += 1;
        }
    }
}

int main() {
    std::fstream file;
    file.open("test.txt", std::ios::in);

    // lab1
    int16_t a = 0, b = 0;
    for (int i = 0; i < LENGTH; ++i) {
        file >> a >> b;
        std::cout << lab1(a, b) << std::endl;
    }

    // lab2
    int16_t p = 0, q = 0, n = 0;
    for (int i = 0; i < LENGTH; ++i) {
        file >> p >> q >> n;
        std::cout << lab2(p, q, n) << std::endl;
    }

    // lab3
    char s[MAXLEN];
    for (int i = 0; i < LENGTH; ++i) {
        file >> n >> s;
        std::cout << lab3(n, s) << std::endl;
    }

    // lab4
    int16_t score[16];
    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < 16; ++j) {
            file >> score[j];
        }
        lab4(score, &a, &b);
        for (int j = 0; j < 16; ++j) {
            std::cout << score[j] << " ";
        }
        std::cout << std::endl << a << " " << b << std::endl;
    }

    file.close();
    return 0;
}