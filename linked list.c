#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* nextNode;
    int data;
} Node;

typedef struct List {
    struct Node* head;
    int size;
} List;

void listConstructor(List* list) {
    list->size = 0;
    list->head = (Node*)0;
}

void listConstructorHeap(List** list) {
    *list = (List*)malloc(sizeof(List));
    (*list)->size = 0;
    (*list)->head = (Node*)0;
}

void push_front(List* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->nextNode = list->head;

    list->head = newNode;
    list->size++;
}

// void push_back(List* list, int val) {
//     Node* currentNode = list->head;
//     Node* prevNode = (Node*)list;
//     while(currentNode != (Node*)0){
//         prevNode = currentNode;
//         currentNode = currentNode->nextNode;
//     }
//     currentNode = (Node*)malloc(sizeof(Node));
//     prevNode->nextNode = currentNode;
//     currentNode->data = val;
//     currentNode->nextNode = (Node*)0;
//     list->size++;
// }

void push_back(List* list, int val) {
    Node* currentNode = (Node*)list;
    while(currentNode->nextNode != (Node*)0)
        currentNode = currentNode->nextNode;
    currentNode->nextNode = (Node*)malloc(sizeof(Node));
    currentNode = currentNode->nextNode;
    currentNode->data = val;
    currentNode->nextNode = (Node*)0;
    list->size++;
}

void push_at(List* list, int pos, int val) {
    Node* currentNode = (Node*)list;

    for(int i = 0; i < pos; i++)
        currentNode = currentNode->nextNode;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
}

int at(List* list, int pos) {
    Node* currentNode = list->head;

    for(int i = 0; i < pos; i++)
        currentNode = currentNode->nextNode;

    return currentNode->data;
}

int front(List* list) {
    return list->head->data;
}

int back(List* list) {
    Node* currentNode = (Node*)list;

    while(currentNode->nextNode != (Node*)0)
        currentNode = currentNode->nextNode;

    return currentNode->data;    
}

void pop_front(List* list) {
    Node* temp = list->head;
    list->head = temp->nextNode;
    free(temp);
}

void pop_back(List* list) {
    Node* currentNode = list->head;
    Node* prevNode = (Node*)list;

    while(currentNode->nextNode != (Node*)0) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    prevNode->nextNode = (Node*)0;
    free(currentNode);
}

void pop_at(List* list, int pos) {
    Node* currentNode = list->head;
    Node* prevNode = (Node*)list;

    for(int i = 0; i < pos; i++) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    prevNode->nextNode = currentNode->nextNode;
    free(currentNode);
}

void print(List* list) {
    if(list->size == 0){
        printf("The list is empty\n");
        return;
    }

    Node* currentNode = list->head;

    printf("The contents of the list are: ");
    while(currentNode != (Node*)0) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    printf("\n");
}

int main() {
    // List list;
    // listConstructor(&list);

    // push_back(&list, 6);
    // push_back(&list, 10);
    // push_back(&list, 20);

    // print(&list);

    List* list;
    listConstructorHeap(&list);

    push_back(list, 6);
    push_back(list, 10);
    push_back(list, 20);
    push_front(list, 20);
    push_front(list, 30);
    push_front(list, 40);
    push_at(list, 1, 100);

    print(list);

    pop_front(list);
    pop_front(list);
    pop_front(list);
    
    print(list);

    pop_back(list);
    pop_back(list);

    print(list);

    push_back(list, 6);
    push_back(list, 10);

    print(list);

    push_front(list, 20);
    push_front(list, 30);

    print(list);

    pop_at(list, 0);
    pop_at(list, 2);

    print(list);

    return 0;
}