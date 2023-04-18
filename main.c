#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Dog
struct dog {
  char name[10]; // Name
  int age;       // Age
  struct dog *next;
};
typedef struct dog dog_t;

// Hash table
dog_t table[SIZE];

// Initialize table index
void node_initiaze(dog_t *table) {
  dog_t *head = malloc(sizeof(dog_t));
  strcpy(head->name, "None");
  head->age = 0;
  head->next = NULL;
  for (int i = 0; i < SIZE; i++) {
    table[i] = *head;
  }
}

// Get table head
dog_t *node_tail(dog_t *table, int index) {
  dog_t *tmp = &table[index];
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  return tmp;
}

// Hash function
int hash(char name[10]) {
  // Create hash with dog name
  long hash = 7;
  for (int i = 0; i < strlen(name); i++) {
    hash = hash * 31 + name[i];
  }

  // Get last digit of the hash
  return hash % SIZE;
}

// Insert new dog in the hash table
void insert(char name[10], int age) {
  // Create dog
  dog_t *new_dog = malloc(sizeof(dog_t));
  strcpy(new_dog->name, name);
  new_dog->age = age;
  new_dog->next = NULL;

  // Find last node in the index linked list
  dog_t *last;
  int index = hash(new_dog->name);
  last = node_tail(table, index);

  last->next = new_dog;
}

void print_table(dog_t *table) {
  dog_t *head;
  for (int i = 0; i < SIZE; i++) {
    head = &table[i];
    if (head->next == NULL) {
      i++;
    }
    dog_t *tmp = head->next;

    while (tmp != NULL) {

      printf("%s: %d\t", tmp->name, tmp->age);
      tmp = tmp->next;
    }
  }
}

int main() {
  node_initiaze(table);
  char name[10] = "Chloe";
  int age = 5;
  insert(name, age);

  strcpy(name, "Bingo");
  age = 17;
  insert(name, age);

  strcpy(name, "Lily");
  age = 3;
  insert(name, age);

  strcpy(name, "Kiki");
  age = 6;
  insert(name, age);

  strcpy(name, "Itou");
  age = 20;
  insert(name, age);

  print_table(table);
  return 0;
}