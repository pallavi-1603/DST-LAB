#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 50

typedef struct Stack{
    int head;
    char* container;
} Stack;

void stackConstructor(Stack *s){
    s->head = -1;
    s->container = (char*)malloc(sizeof(char)*STACK_SIZE);
}

void push(Stack *s, char ele){
        s->head++;
        s->container[s->head] = ele;
}

void pop(Stack *s){
    if(s->head == -1){
        printf("STACKUNDERFLOW\n\n");
		return;
    }
    
    s->head--;
}

void display(Stack *s, int len){
    if(s->head == -1){
        printf("The empty is empty, lol\n\n");
    }
    
    for(int i = 0; i < len; i++){
        printf("%c", s->container[i]);
    }
    printf("\n\n");
}

int empty(Stack *s){
	if(s->head == -1)
		return 1;
	else
		return 0;
}

char top(Stack *s){
	return s->container[s->head];
}

//using this also to check if the symbol is operator or operand
int givePrecedence(char c){
	switch(c){
		case ')':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '^':
			return 4;
		case '(':
			return 5;
		default:
			return 0;
	}
}

int isRightAssociative(char c){
	switch (c) {
		case '^': return 1;
		default: return 0;
	}
}

int main(){
	Stack postS;
	stackConstructor(&postS);

	Stack opeS;
	stackConstructor(&opeS);

	char inputExp[STACK_SIZE];
	printf("Enter the Infix Expression: ");
	fgets(inputExp, 50, stdin);
	
	int len = strlen(inputExp);

	for(int i = 0; i < len - 1; i++){
		if(!givePrecedence(inputExp[i]))
			push(&postS, inputExp[i]);
		else{
			if(empty(&opeS)){
				push(&opeS, inputExp[i]);
				continue;
			}
			if(isRightAssociative(inputExp[i]))
				push(&opeS, inputExp[i]);
			else if(inputExp[i] == ')'){
				while(top(&opeS) != '('){
					push(&postS, top(&opeS));
					pop(&opeS);
				}
				pop(&opeS);
			}
			else{
				while(givePrecedence(top(&opeS)) >= givePrecedence(inputExp[i]) && top(&opeS) != '('){
					push(&postS, top(&opeS));
					pop(&opeS);
				}
				push(&opeS, inputExp[i]);
			}
		}
	}

	while (!empty(&opeS)) {
		push(&postS, top(&opeS));
		pop(&opeS);
	}

	display(&postS, len);

	return 0;
}