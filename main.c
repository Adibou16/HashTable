#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

static int size = 10;
int table[10] = {};
char dog[10] = "Maggy";


uint64_t to_ascii(char string[]) {
    int letter, digit;
    uint64_t word;
    int lenght = strlen(string);
    for (int i = 0; i < lenght; ++i) {
        letter = (int)string[i];
        digit = log10(letter) + 1;
        word *= pow(10, digit);
        word += letter;
    }
    return word;
}

int hash(char string[]) {
    int key = to_ascii(string);
    return (key % size);
}

int insert(char string[], int table[]) {
    int ascii = to_ascii(string);
    int index = hash(string);
    table[index] = *string;
    return 0;
}

// int remove(char string[], int table[]) {
//     int index = hash(string);
//     table[index] = 0;
//     return 0;
// }

int display(int table[]) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", table[i]);
    }
}


int main() {
    printf("%lld", to_ascii(dog));
    return 0;
}
