#include<stdio.h> #include<stdlib.h> #define qsize 3
int count=0;
void insert_rear(int q[],int item,int*r)
{
if (count==qsize) printf("overflow\n"); else
{
(*r)++;
(*r)=(*r)%qsize; q[*r]=item; count++;
}
}
int delete_front (int q[],int*f,int*r)
{
int del_item; if (count==0)
{
printf("underflow");
 
}
else
{
del_item=q[*f];
*f=((*f)++)%qsize; count--;
return del_item;
}
}
void display(int q[],int * f)
{
int i,temp; temp=*f;
for(i=0;i<count;i++)
{
printf("%d\n",q[temp]); temp=(temp+1)%qsize;
}
}
void main()
{
int r=-1; int f=0;
int item,q[qsize]; int n,i;
while(1)
{
printf("choose from the following\n1.Insert\n2.Delete\n3.Display\n4.Exit\n"); scanf("%d",&n);
 
switch(n)
{
case 1:printf("enter the item to be inserted in queue\n"); scanf("%d",&item);
insert_rear(q,item,&r); break;
case 2:i=delete_front(q,&f,&r); printf("item being deleted is %d\n",i); break;
case 3:display(q,&f); break;
case 4:exit(0);
default:printf("enter correct option number\n"); break;
}
}


}
