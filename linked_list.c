#include <stdio.h>
#include <stdlib.h>


// Define what a node is 
struct node {
    int value; // Value of the item
    struct node* next; // Points to next item
};
typedef struct node node_t;


// Print the linked list
void printlist(node_t *head) {
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


// Create a new node 
node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t)); // Create the node
    result->value = value; // Set its value to value
    result->next = NULL; // Set the pointer of the next node to NULL
    return result;
}


// Interact wide list
// Find the last Node of the linked list
node_t *find_tail(node_t *head) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->next == NULL) return tmp; // If node doesn't point to something then it is last
        tmp = tmp->next;
    }
    return NULL;
}

// Find which node of that value
node_t *find_node(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) return tmp; 
        tmp = tmp->next;
    }
    return NULL;
}


// Insert node
// Inserts a node after specific node of the linked list
void insert_after_node(node_t *node_to_insert_after, node_t *node_to_insert) {
    node_to_insert->next = node_to_insert_after->next;
    node_to_insert_after->next = node_to_insert;
}

// Inserts a node at the beginning of the linked list
node_t *insert_at_head(node_t **head, int value) {
    node_t *node_to_insert = create_new_node(value);
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

// Inserts a node at the end of the linked list
void *insert_at_tail(node_t *head, int value) {
    node_t *node_to_insert_after = find_tail(head);
    if (head == NULL) {
        printf("Should do shit");
        insert_at_head(&head, value);
    } else { 
        insert_after_node(node_to_insert_after, create_new_node(value)); 
    }
}

int main() {
    node_t *head = NULL, *tmp;
    // if (head == NULL) {
    //     insert_at_head(&head, 0);
    // }

    for (int i=0; i < 10; i++) {
        insert_at_tail(head, i);
    }

    printlist(head);
    return 0;
}