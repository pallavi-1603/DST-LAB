#include<stdio.h>
#include"list.h"

typedef struct Queue {
    int head;
    List* container;
} Queue;

void initialize(Queue* vec) {
    vec->head = 0;
    list_constructor_heap(&(vec->container));
}

void push(Queue* vec, int val) {
    list_push_back(vec->container, val);
    vec->head++;
}

void pop(Queue* vec) {
    if(vec->head == 0){
        printf("Queue Underflow\n");
        return;
    }

    list_pop_front(vec->container);
    vec->head--;
}

void display(Queue* vec) {
    list_print(vec->container);
}

int main() {
    Queue vec;
    initialize(&vec);
    
    push(&vec, 5);
    push(&vec, 10);
    push(&vec, 15);

    pop(&vec);

    display(&vec);
}