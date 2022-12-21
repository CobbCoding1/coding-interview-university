#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int* arr;
    int size;
    int capacity;
} vector;

void resize(vector *vec, int new_capacity) {
    vec->capacity = new_capacity;
    vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
}

void init(vector *vec) {
    vec->arr = malloc(INITIAL_CAPACITY * sizeof(int));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
}

void append(vector *v, int value){
    if(v->size >= v->capacity){
        resize(v, v->capacity *= 2);
    }

    v->arr[v->size] = value;
    v->size++;
}



void pop(vector *v){
    if(v->size != 0){
        if((v->capacity / v->size) >= 0.25){
            resize(v, v->capacity/2);
        }
        v->arr[v->size] = NULL;
        v->size--;
    }
}

int get(vector *v, int index) {
    if(index < 0 || index >= v->size){
        fprintf(stderr, "Error: Index %d out of bounds\n", index);
        exit(1);
    }
    return(v->arr[index]);
}

void free_vector(vector *vec) {
    free(vec->arr);
    vec->arr = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void insert(vector *vec, int item, int index) {
    if(index >= vec->capacity){
        resize(vec, index);
    }

    for(int i = vec->size; i > index; i--){
        vec->arr[i] = vec->arr[i-1];
    }

    vec->arr[index] = item;
    vec->size++;
}

void delete(vector *vec, int index){
    if(index >= vec->size){
        printf("Index %d is out of bounds", index);
        exit(1);
    }

    for(int i = vec->size; i >= index; i--){
        vec->arr[i] = vec->arr[i-1];
    }

    vec->size--;
}

void remove_item(vector *vec, int item){
    for(int i = vec->size; i >= 0; i--){
        if(vec->arr[i] == item){
            delete(vec, i);
        }
    }
}

int find(vector *vec, int item){
    for(int i = 0; i <= vec->size; i++){
        if(vec->arr[i] == item){
            return(i);
        }
    }

    return(-1);
}

int size(vector *v){
    return(v->size);
}

int capacity(vector *v){
    return(v->capacity);
}

bool is_empty(vector *v){
    if(v->size == 0){
        return(true);
    } else {
        return(false);
    }
}

void prepend(vector *v, int value){
    if(v->size >= v->capacity){
        resize(v, v->capacity *= 2);
    }

    for(int i = v->size; i < 0; i--){
        v->arr[i] = v->arr[i-1];
    }

    v->arr[0] = value;
    v->size++;
}

int main(int argc, char *argv[]) {
    vector v;
    init(&v);
    append(&v, 15);
    append(&v, 12);
    append(&v, 13);
    append(&v, 27);
    append(&v, 38);
    append(&v, 12309);
    printf("%d\n", get(&v, 0));
    printf("%d\n", find(&v, 38));
    free_vector(&v);
    return 0;
}