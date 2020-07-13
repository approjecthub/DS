#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree
{
     int data;
     struct tree* left;
     struct tree* right;
};

struct tree* newtree(int data)
{
     struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
     tree->data = data;
     tree->left = NULL;
     tree->right = NULL;
     return(tree);
}

int search(struct tree* t, int data)
{
	int i=0;
	struct tree* t1 = t;
	while(t1 != NULL)
	{
		if(t1->data == data)
		{
			i++;
			return i;
		}
		 if(t1->data > data)
		{
			t1 = t1->left;
		}
		 if(t1->data < data)
		{
			t1 = t1->right;
		}
	}
	return i;
}

struct tree* nodeInsert(struct tree* t, int data)
{
	if(t == NULL)
	{
		t = newtree(data);
		return t;
	}
	else if( data <= t->data )
	{
		t->left = nodeInsert(t->left, data);
		return t;
	}
	else if(data >= t->data)
	{
		t->right = nodeInsert(t->right, data);
		return t;
	}
}

struct tree* delet(struct tree* t, int d)
{
	if(t == NULL) 
	{
		printf("\nNothing to delete\n");
		return t;
	}
	struct tree* t1 = t, *r=t;
	while(t1 != NULL)
	{
		if(t1->data == d)
		{
			//No child
			if(t1->left == NULL && t1->right == NULL)
			{
				if(r->left == t1)
				{
					r->left = NULL;
				}
				else if(r->right == t1)
				{
					r->right = NULL;
				}
				free(t1);
				return t;
			}
			//One child
			else if(t1->left == NULL )
			{
				if(r->left == t1)
				{
					r->left = t1->right;
				}
				else if(r->right == t1)
				{
					r->right = t1->right;
				}
				free(t1);
				printf("shit1");
				return t;
			}
			else if(t1->right == NULL )
			{
				if(r->left == t1)
				{
					r->left = t1->left;
				}
				else if(r->right == t1)
				{
					r->right = t1->left;
				}
				free(t1);	
				printf("shit2");
				return t;
			}
			//2 childs
			else
			{
				//printf("\nt1 data= %d", t1->data);
				struct tree* t2 = t1->right, *c=t2;
				//printf("\nt2 data = %d", t2->data);
				//printf("\nr data = %d", r->data);
				//printf("c data = %d ", c->data);
				while(t2->left != NULL)
				{
					//printf("bull");
					c = t2;
					t2 = t2->left;
				}
				if(c != t2)
				{
					//printf("ccccc");
					if(t2->right != NULL)
					{
						c->left = t2->right;
					}
					else
					{
						c->left = NULL;
					}
				}
				//printf("\nt2 = %d", t2->data);
				//printf("\nt1 = %d", t1->data);
				//printf("\nr = %d", r->data);
				if(r->data > t1->data)
				{
					printf("shit1");
					r->left = t2;
					//t2->right = t1->right;
					t2->left = t1->left;
					free(t1);
				}
				else if(r->data < t1->data)
				{
					//printf("shit2");
					r->right = t2;
					t2->left = t1->left;
					//t2->right = t1->right;
				free(t1);
				}
				else if(r->data == t1->data)
				{
					//printf("yo");
					t2->left = r->left;
					t2->right = r->right;
					t=t2;
					free(r);
				}
				return t;
			}	
		}
		 else if(t1->data > d)
		{
			r = t1;
			t1 = t1->left;
		}
		 else if(t1->data < d)
		{
			r = t1;
			t1 = t1->right;
		}
	}
	//printf("return = %d", t->data);
	return t;
}

struct tree* FindMin(struct tree* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct tree* Delete(struct tree *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free (root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct tree *temp = root;
			root = root->right;
			free( temp);
		}
		else if(root->right == NULL) {
			struct tree *temp = root;
			root = root->left;
			free( temp);
		}
		// case 3: 2 children
		else { 
			struct tree *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void printInorder(struct tree* tree)
{
     if (tree == NULL)
          return;
     printInorder(tree->left);
     printf(" %d ", tree->data);
     printInorder(tree->right);
}

main()
{
    struct tree* root = NULL;
	root = nodeInsert(root, 15);
	root = nodeInsert(root, 7);
	root = nodeInsert(root, 26);
	root = nodeInsert(root, 3);
	root = nodeInsert(root, 9);
	root = nodeInsert(root, 17);
	root = nodeInsert(root, 42);
	root = nodeInsert(root, 1);
	root = nodeInsert(root, 4);
	root = nodeInsert(root, 8);
	root = nodeInsert(root, 13);
	root = delet(root, 9);
	root = delet(root, 8);
	root = delet(root, 13);
	root = delet(root, 7);
	//root = delet(root, 15);
	//root = Delete(root, 7);
	printInorder(root);
	getch();
}
