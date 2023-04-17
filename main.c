#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dog
struct dog {
  char name[10]; // Name
  int age;       // Age
};
typedef struct dog dog_t;

// Link list node
struct node {
  dog_t dog;         // Dog
  struct node *next; // Next dog
};
typedef struct node node_t;


// Transforms a string to ascii
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

// Hash function
int hash(dog_t *dog) {
  int key = to_ascii(dog->name);
  return key;
}

int main() {
  dog_t *tmp;
  strcpy(tmp->name, "Chloe");
  tmp->age = 5;

  printf("%s", tmp->name);
  return 0;
}
