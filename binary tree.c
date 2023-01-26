#include <stdio.h> #include <conio.h> #include <malloc.h>

struct node
{
int data;
struct node *left; struct node *right;
};

struct node *tree;

void create_tree(struct node *);
struct node *insertElement(struct node *, int); void preorderTraversal(struct node *);
void inorderTraversal(struct node *); void postorderTraversal(struct node *);

int main()
{
int option, val; struct node *ptr; create_tree(tree);

printf("Binary Search Tree Operations:\n"); printf("1. Insert Element");
printf("\n2. Preorder Traversal"); printf("\n3. Inorder Traversal"); printf("\n4. Postorder Traversal"); printf("\n5. Exit");

do
{
printf("\n\n Enter your option : "); scanf("%d", &option);
 
switch(option)
{
case 1:
printf("\n Enter the value of the new node : "); scanf("%d", &val);
tree = insertElement(tree, val); break;
case 2:
printf("\n The elements of the tree are : \n"); preorderTraversal(tree);
break; case 3:
printf("\n The elements of the tree are : \n"); inorderTraversal(tree);
break; case 4:
printf("\n The elements of the tree are : \n"); postorderTraversal(tree);
break;
}
}
while(option!=14); getch();
return 0;
}

void create_tree(struct node *tree)
{
tree = NULL;
}

struct node *insertElement(struct node *tree, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr = (struct node*)malloc(sizeof(struct node)); ptr->data = val;
ptr->left = NULL; ptr->right = NULL;

if(tree==NULL)
{
tree=ptr;
tree->left=NULL; tree->right=NULL;
}
 
else
{



{
 


parentptr=NULL; nodeptr=tree; while(nodeptr!=NULL)
parentptr=nodeptr; if(val<nodeptr->data)
nodeptr=nodeptr->left;
 

 
else

}
 
nodeptr = nodeptr->right; if(val<parentptr->data)
parentptr->left = ptr;
 

 


}
return tree;
}
 
else
 

parentptr->right = ptr;
 

void preorderTraversal(struct node *tree)
{
if(tree != NULL)
{
printf("%d\t", tree->data); preorderTraversal(tree->left); preorderTraversal(tree->right);
}

}

void inorderTraversal(struct node *tree)
{
if(tree != NULL)
{
inorderTraversal(tree->left); printf("%d\t", tree->data); inorderTraversal(tree->right);
}
}
 
void postorderTraversal(struct node *tree)
{
if(tree != NULL)
{
postorderTraversal(tree->left); postorderTraversal(tree->right); printf("%d\t", tree->data);
}

}

