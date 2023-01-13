#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
	struct node *prev;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not allocated\n");
	}
	return temp;
}

NODE insert_beg(NODE first,int item)
{
	NODE new;
	new=getnode();
	new->value=item;
	new->prev=NULL;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	new->next=first;
	first->prev=new;
	return new;
}

NODE insert_left(NODE first,int key,int item)
{
	NODE temp,new;
	new=getnode();
	new->value=item;
	new->prev=NULL;
	new->next=NULL;
	if(first==NULL)
	{
		printf("List is empty");
		return NULL;
	}
	if(first->next==NULL && first->value!=key)
	{
		printf("key not found.....cant insert!!!");
		return first;
	}
	if(first->next==NULL && first->value==key)
	{
	    first=insert_beg(first,new->value);
	}
	temp=first;
	while(temp->value!=key && temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(temp->value==key)
	{
		new->next=temp;
		new->prev=temp->prev;
		(temp->prev)->next=new;
		temp->prev=new;
		return first;
	}
	if(temp->value!=key)
	{
		printf("value not found\n");
		return first;
	}
}


NODE delete_specific(NODE first,int key)
{
	NODE curr,temp;
	if(first==NULL)
	{
		printf("Linkedlist is empty\n");
		return NULL;
	}
	if(first->next==NULL && first->value==key)
	{
		free(first);
		return NULL;
	}
	if(first->next==NULL && first->value!=key)
	{
		printf("element not found\n");
		return first;
	}
	if(first->value==key)
	{
		(first->next)->prev=NULL;
		temp=first->next;
		free(first);
		return temp;
	}
	while(curr!=NULL)
	{
		if(curr->value==key)
		break;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		printf("Element not found\n");
	}
	(curr->prev)->next=curr->next;
	if(curr->next!=NULL)
	{
		(curr->next)->prev=curr->prev;
	}
}

void display(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("List is empty\n");
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d\n",temp->value);
		temp=temp->next;
	}
}

void main()
{
	NODE first=NULL;
	int choice,key,item;
	while(1)
	{
		printf("\n1.Insert_beg  2.Insert_left  3.Delete_specific  4.Display\n");
		printf("\n enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter the value to be inserted at the begining\n");
			       scanf("%d",&item);
			       first=insert_beg(first,item);
			       break;
			    
			case 2:printf("\nEnter the value to be inserted at the left\n");
			       scanf("%d",&item);
			       printf("\nEnter the key\n");
			       scanf("%d",&key);
			       first=insert_left(first,key,item);
                   break;
                   
            case 3:printf("\nEnter the value to be deleted\n");
			       scanf("%d",&key);
			       first=delete_specific(first,key);
			       break;
			        
			case 4:display(first);
			       break;
			         
		    default:exit(0);
			        
		}
		
	}
}