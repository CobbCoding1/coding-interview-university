#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* init(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(node *head){
    node *current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

}

int value_at(node *head, int index) {
    if(index < 0){
        return -1;
    }

    node *current = head;
    while(index != 0){
       current = current->next; 
       index--;
    }

    if(current == NULL){
        return -1;
    }

    return(current->data);
}

int list_size(node *head){
    int size = 0;
    node *current = head;
    while(current != NULL) { 
        size++;
        current = current->next;
    }
    
    return(size);
}

void push_front(node **head, int value) {
    node *new = init(value);

    new->next = *head;
    *head = new;
    printf("Inserted: %d\n", value);
}

void pop_front(node **head) {
    if(head == NULL) {
        return;
    }
    
    node *new = (*head)->next;
    free(*head);
    *head = new;
}

void push_back(node *head, int value) {
    node *new = init(value);
    node *current = head;

    if(head == NULL){
        head = new;
        return;
    }
    
    while(current->next != NULL){
        current = current->next;
    }

    current->next = new;
}

void pop_back(node **head) {
    if(*head == NULL) {
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node *current = *head;

    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void insert(node **head, int index, int value) {
    node *new_node = init(value);

    if(index >= list_size(*head)) {
        printf("Index is too big for the list!\n");
        exit(1);
    }

    if(index == 0) {
        new_node->next = *head;    
        *head = new_node;
        return;
    }
    node *current = *head;

    int i = 0;

    while(i < index-1) {
        current = current->next;
        i++;
    }

    new_node->next = current->next->next;
    current->next = new_node;
}

void erase(node* head, int index) {
    node *current = head;

    if(index < 0) {
        printf("Please enter a non-negative number!\n");
        exit(1);
    }

    if(index >= list_size(head)) {
        printf("Value is too great!\n");
        exit(1);
    }

    int i = 0;
    while(i < index-1) {
        current = current->next;
        i++;
    }

    current->next = current->next->next;
}

void remove_value(node** head, int value) {
    if(*head == NULL){
        return;
    }

    if((*head)->data == value) {
        node *new_head = (*head)->next;
        free(*head);
        *head = new_head;
        return;
    }
    node *current = *head;

    while(current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Value was too large!\n");
        exit(1);
    }

    node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void reverse(node** head) {
    node *current = *head;
    node *previous = NULL;
    node *next;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

int front(node* head) {
    return(head->data);
}

int back(node* head) {
    node *current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    return(current->data);
}

int value_n_from_end(node* head, int n) {
    int length = list_size(head) - 1;

    if(n > length) {
        printf("Value is too great!\n");
        exit(1);
    }

    if(n < 0) {
        printf("Please enter a non-negative number!\n");
        exit(1);
    }

    node *current = head;

    int i = length - n;
    while(i > 0) {
        current = current->next;
        i--;
    }

    return(current->data);
}

void free_list(node* head) {
    node *current = head;

    while(current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

bool empty(node *head){
    if(head == NULL){
        return(true);
    } else {
        return(false);
    }
}

int main(){
    node *head = init(1);

    head->next = init(2);
    head->next->next = init(15);

    push_front(&head, 255);
    push_back(head, 55);
    push_back(head, 5123);

    insert(&head, 5, 123);

    printf("value is: %d\n", value_n_from_end(head, 1));

    print_list(head);
    reverse(&head);
    printf("\n");
    print_list(head);


    free_list(head);

    return 0;
}