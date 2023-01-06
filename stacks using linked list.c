#include<stdio.h>
#include"list.h"

typedef struct Stack {
    int head;
    List* container;
} Stack;

void initialize(Stack* vec) {
    vec->head = 0;
    list_constructor_heap(&(vec->container));
}

void push(Stack* vec, int val) {
    list_push_front(vec->container, val);
    vec->head++;
}

void pop(Stack* vec) {
    if(vec->head == 0){
        printf("Stack Underflow\n");
        return;
    }

    list_pop_front(vec->container);
    vec->head--;
}

void display(Stack* vec) {
    list_print(vec->container);
}

int main() {
    Stack vec;
    initialize(&vec);
    
    push(&vec, 5);
    push(&vec, 10);
    push(&vec, 15);

    pop(&vec);

    display(&vec);
}