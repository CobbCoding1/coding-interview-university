#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_SIZE 256
#define SIZE 16

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
} person;

person *hash_table[SIZE];

int hash(char *name, int m) {
    return(((int) name[0] - 65) % m);
}

void init() {
    for(int i = 0; i < SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    for(int i = 0; i < SIZE; i++) {
        if(hash_table[i] != NULL) {
            printf("%s\n", hash_table[i]->name);
        } else {
            printf("Empty Element\n");
        }
    }
}

bool insert(person *p) {
    if(p == NULL) return false;

    int index = hash(p->name, SIZE);

    while(hash_table[index] != NULL) {
        index += 1;
    }
    hash_table[index] = p;
    return true;
}

void add(char key[MAX_NAME_SIZE], person *p) {
    if(p == NULL) return;

    int index = hash(key, SIZE);

   /* while(hash_table[index] != NULL && strcmp(hash_table[index], key)) {
        printf("%d\n", index);
        index += 1;
    } */
    hash_table[index] = p;
}


int get(char key[MAX_NAME_SIZE]) {
    int index = hash(key, SIZE);

    if(hash_table[index] == NULL) {
        printf("Key does not exist\n");
        return -1;
    }

    while((hash_table[index]->name == NULL || strcmp(hash_table[index]->name, key) != 0) && index < SIZE) {
        printf("%d -> %s\n", index, hash_table[index]->name);
        index++;
    }

    if (index < SIZE) {
        return hash_table[index]->age;
    } else {
        printf("Key does not exist\n");
        return -1;
    }
}

bool exists(char key[MAX_NAME_SIZE]) {
    int index = hash(key, SIZE);

    if(hash_table[index] == NULL) {
        return false;
    }

    while((hash_table[index]->name == NULL || strcmp(hash_table[index]->name, key) != 0) && index < SIZE) {
        printf("%d -> %s\n", index, hash_table[index]->name);
        index++;
    }

    if(index < SIZE) {
        return true;
    } else {
        return false;
    }
}

void remove_key(char key[MAX_NAME_SIZE]) {
    int index = hash(key, SIZE);

    if(hash_table[index] == NULL) {
        printf("Key does not exist!");
        return;
    }
    
    while((hash_table[index]->name == NULL || strcmp(hash_table[index]->name, key) != 0) && index < SIZE) {
        printf("%d -> %s\n", index, hash_table[index]->name);
        index++;
    }    

    if (index < SIZE) {
        hash_table[index] = NULL;
    } else {
        printf("Key does not exist\n");
        return;
    }
}

int main() {
    init();
    person john = {.name="John", .age=17};
    person jerry = {.name="Jerry", .age=56};
    person larry = {.name="larry", .age=69};
    person harry = {.name="harry", .age=32};

    insert(&john);
    insert(&larry);
    insert(&harry);
    insert(&jerry);

    printf("%d Exists\n", exists("harry"));

    printf("%d\n", get("John"));

    print_table();
    printf("%d\n", hash("Ascii", SIZE));
    return 0;
}