#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 30

typedef struct {
    int value[QUEUE_CAPACITY];
    int read;
    int write;
} Queue;

void init(Queue *queue) {
    queue->read = 0;
    queue->write = 0;
}

bool full(Queue *queue) {
    return(queue->write + 1) % QUEUE_CAPACITY == queue->read;
}

bool empty(Queue *queue) {
    return(queue->write == queue->read);
}

void enqueue(Queue *queue, int value) {
    if(full(queue)) {
        printf("Error, the queue is full!\n");
        exit(1);
    }

    queue->value[queue->write] = value;
    queue->write = (queue->write + 1) % QUEUE_CAPACITY;
}

void dequeue(Queue *queue) {
    if(empty(queue)) {
        printf("Error, the queue is empty!\n");
        exit(1);
    }

    queue->read = (queue->read + 1) % QUEUE_CAPACITY;
}

void free_queue(Queue *queue) {
    init(queue);
}

void print_queue(Queue *queue) {
    if(empty(queue)) {
        printf("Error, empty queue!\n");
        return;
    }

    printf("Queue: ");
    for(int i = queue->read; i != queue->write; i = (i + 1) % QUEUE_CAPACITY) {
        printf("%d ", queue->value[i]);
    }

    printf("\n");

}

int main() {
    Queue *queue = malloc(sizeof(Queue));
    init(queue);

    enqueue(queue, 15);
    enqueue(queue, 27);
    enqueue(queue, 28);
    enqueue(queue, 30);
    print_queue(queue);
    dequeue(queue);
    print_queue(queue);

    free_queue(queue);

    return 0;
}