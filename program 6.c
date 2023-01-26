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

void deleteFirst()
{
struct node* temp; if (start == NULL)
printf("\nList is empty\n");

else
{
temp = start;
start = start->link; free(temp);
}
}

void deleteLast()
{
struct node *temp, *prevnode; if (start==NULL) printf("\nList is Empty\n");

else
{
temp=start; while(temp->link!=0)
{
prevnode=temp; temp=temp->link;
}

free(temp); prevnode->link = 0;
}
}
 
void deletePosition()
{
struct node *temp, *position; int i=1, pos;

if(start==NULL) printf("\nList is Empty\n");

else
{
printf("Enter Position: "); scanf("%d", &pos); position=malloc(sizeof(struct node)); temp=start;

while(i<pos-1)
{
temp=temp->link; i++;
}
position = temp->link;
temp->link = position->link; free(position);
}
}

void display()
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
 
int main()
{
printf("Singly Linked List Deletion and Display Operations"); printf("\n1. Insert At First Position");
printf("\n2. Insert At Last Position"); printf("\n3. Insert At Any Position"); printf("\n4. Delete At First Position"); printf("\n5. Delete At Last Position"); printf("\n6. Delete At Any Position"); printf("\n7. Display Elements"); printf("\n8. Exit\n");

while(1){ int choice;
printf("\nEnter your choice: "); scanf("%d", &choice);

switch (choice)
{
case 1: insertFront(); break;

case 2: insertEnd();
break;

case 3: insertPosition();
break;

case 4: deleteFirst();
display(); break;

case 5: deleteLast();
display(); break;

case 6: deletePosition(); display();
break;

case 7: display();
break;

case 8: exit(1);
break;
 
default: printf("Wrong choice!!!!!!\n");
}
}
return 0;
}
