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

// Remove a dog by finding its hash
void remove_name(char name[10], dog_t *table) {
  dog_t *tmp, *last;

  int index = hash(name);
  last = &table[index];
  tmp = last->next;

  while (tmp != NULL) {
    if (index == hash(tmp->name)) {
      last->next = tmp->next;
      free(tmp);
      return;
    }
    last = tmp;
    tmp = tmp->next;
  }
}

// Remove dog by finding its age
void remove_age(int age, dog_t *table) {
  dog_t *tmp, *last;

  last = &table[index];
  tmp = last->next;

  while (tmp != NULL) {
    if (age == tmp->age) {
      last->next = tmp->next;
      free(tmp);
      return;
    }
    last = tmp;
    tmp = tmp->next;
  }
}

void print_table(dog_t *table) {
  dog_t *head, *tmp;
  for (int i = 0; i < SIZE; i++) {
    head = &table[i];
    tmp = head->next;

    while (tmp != NULL) {
      printf("%s: %d,\t", tmp->name, tmp->age);
      tmp = tmp->next;
    }
  }
  printf("\n");
}

int main() {
  node_initiaze(table);
  char name[10];
  int age, input;

  while (1) {
    printf("What do you want to do?\n");
    printf(
        "1. Insert\t2. Remove by name\t3. Remove by age\t4. Print\t5. Exit\n");
    scanf("%d", &input);

    switch (input) {
    case 1:
      printf("Name:\n");
      scanf("%s", name);
      printf("Age:\n");
      scanf("%d", &age);
      insert(name, age);
      break;

    case 2:
      printf("Name:\n");
      scanf("%s", name);
      remove_name(name, table);
      break;

    case 3:
      printf("Age:\n");
      scanf("%d", &age);
      remove_age(age, table);
      break;

    case 4:
      print_table(table);
      break;

    case 5:
      return 1;
    }
  }

  return 0;
}