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

struct node *insert(struct node *node, int data)
{
	if(node == NULL) 
		return (newnode(data));
	else {
		if(data <= node -> data)
			node -> left = insert(node -> left, data);
		else
			node -> right = insert(node -> right, data);
		return node;
	}
}

struct node *build123()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root , 1);
	root = insert(root , 3);
	return root;
}
void printtree(struct node *node)
{
	if(node -> left != NULL)
		printtree(node -> left);
	printf("%d\t",node -> data);
	if(node -> right != NULL)
		printtree(node -> right);
}
main()
{
	struct node *treenode;
	treenode = build123();
	printtree(treenode);
}


