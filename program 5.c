#include<stdio.h> #include<stdlib.h>

struct node{ int info;
struct node* link;
};
struct node* start = NULL; void createList()
{
if (start == NULL) { int n;
printf("\nEnter the number of nodes: "); scanf("%d", &n);

if (n != 0) { int data;
struct node* newnode; struct node* temp;
newnode = malloc(sizeof(struct node)); start = newnode;
temp = start;

printf("\nEnter number to be inserted : "); scanf("%d", &data);
start->info = data;

for (int i = 0; i <= n; i++) {
newnode = malloc(sizeof(struct node)); temp->link = newnode;
printf("\nEnter number to be inserted : "); scanf("%d", &data);
newnode->info = data; temp = temp->link;
}
 
}
printf("\nList Created\n");
}
else
printf("\nThe list is already created\n");
}

void traverse()
{
struct node* temp;

if (start == NULL) printf("\nList is empty\n");

else
{
temp = start;
while (temp != NULL)
{
printf("Element = %d\n", temp->info); temp = temp->link;
}
}
}

void insertFront()
{
int data;
struct node* temp;
temp = malloc(sizeof(struct node)); printf("\nEnter number to be inserted : "); scanf("%d", &data);
temp->info = data;

temp->link = start; start = temp;
}

void insertEnd()
{
int data;
struct node *temp, *head;
temp = malloc(sizeof(struct node));

printf("\nEnter number to be inserted : "); scanf("%d", &data);
 
temp->link = 0; temp->info = data; head = start;
while (head->link != NULL) { head = head->link;
}
head->link = temp;
}


void insertPosition()
{
struct node *temp, *newnode; int pos, data, i = 1;
newnode = malloc(sizeof(struct node));

printf("\nEnter position and data :"); scanf("%d %d", &pos, &data);

temp = start;
newnode->info = data; newnode->link = 0; while (i < pos - 1) {
temp = temp->link; i++;
}
newnode->link = temp->link; temp->link = newnode;
}

int main()
{
printf("Singly Linked List Insertion and Display Operations"); printf("\n1. Insert At First Position");
printf("\n2. Insert At Last Position"); printf("\n3. Insert At Any Position"); printf("\n4. Display Elements"); printf("\n5. Exit");

while(1){ int choice;
printf("\n\nEnter your choice: "); scanf("%d", &choice);

switch (choice)
 
{
case 1: insertFront(); break;

case 2: insertEnd();
break;

case 3: insertPosition();
break;

case 4: traverse();
break;

case 5: exit(1);
break;

default: printf("Wrong choice!!!!!!\n");
}
}
return 0;
}
