#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node * left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

struct node *build123()
{
	struct node *root = newnode(2);
	struct node *leftchild = newnode(1);
	struct node *rightchild = newnode(3);
	root -> left = leftchild;
	root -> right = rightchild;
	return root;
}
void printtree(struct node *treenode)
{
	if(treenode -> left != NULL)
		printtree(treenode -> left);
	printf("%d\t",treenode -> data);
	if(treenode -> right != NULL)
		printtree(treenode -> right);
}
main()
{
	struct node *treenode;
	treenode = build123();
	printtree(treenode);
}


