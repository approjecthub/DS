#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>

struct tree
{
     int data;
     struct tree* left;
     struct tree* right;
};
 
struct node
{
	struct tree *data;
	struct node *next;
};

struct node *head = NULL;
struct tree *root = NULL;

bool isEmpty()
{
	return !head;
}

void push(struct tree *l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = head;
	head = link;
}

struct tree* pop()
{
	struct tree* popped = head->data;
	struct node *ptr = head;
	if(isEmpty())
	{
		return ;
	}
	head = head->next;
	return popped;
	free(ptr);
}
 
struct tree* newNode(int data)
{
     struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
     tree->data = data;
     tree->left = NULL;
     tree->right = NULL;
     return(tree);
}
 
void printInorder(struct tree* tree)
{
     if (tree == NULL)
          return;
     printInorder(tree->left);
     printf(" %d ", tree->data);
     printInorder(tree->right);
}

/*void inorderTraversal(struct tree* t)
{
	push(NULL);
	struct tree* s = t;
	l: while(s != NULL)
	{
		push(s);
		s = s->left;
	}
	s = pop();
	while(s != NULL)
	{
		printf(" %d ", s->data);
		if(s->right != NULL)
		{
			s = s->right;
			goto l;
		}
	}
	s = pop();
} */

void inorderTraversal(struct tree* t)
{
	int i=0;
	struct tree *t1 = t;
	while(t1 != NULL || !isEmpty())
	{
		while(t1 != NULL){
		push(t1);
		t1 = t1->left;
		i++;
	}
	t1 = pop();
	printf(" %d ", t1->data);
	t1 = t1->right;
	i++;
}
printf("No. of iteration = %d", i);
}

main()
{
	//creation of a sample tree
     /*struct tree *root  = newNode(1);
	 root->left =  newNode(2);
	 root->left->left = newNode(4);
	 root->left->right = newNode(5);
	 root->left->right->left = newNode(6);
	 root->right = newNode(3);
	 root->right->right = newNode(7);
	 root->right->right->right = newNode(8);*/
	 
	   /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tree *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
     printf("\nRecursive Inorder traversal of binary tree is \n");
     printInorder(root);
     printf("\nIterative Inorder traversal of binary tree is \n");
	 inorderTraversal(root);
    
     getch();
}
