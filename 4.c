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

/*int size(struct node *node)
{
	if(node == NULL)
		return 0;
	return (size(node -> left) + 1 + size(node -> right));
}
*/

/*int maxdepth(struct node *node)
{
	int leftheight = 0 , rightheight = 0;
	if(node == NULL)
		return 0;
	else {
		leftheight = maxdepth(node -> left);
		rightheight = maxdepth(node -> right);
		if(leftheight > rightheight)
			return leftheight + 1;
		else
			return rightheight + 1;
	}
}
*/

int minvalue(struct node *node)
{
	if(node -> left == NULL)
		return node -> data;
	return minvalue(node -> left);
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
	struct node *root = NULL;
	int ch = 1, data;
	printf("Enter 1 to isert into tree\n");
	scanf("%d", &ch);
	while(ch == 1){
		printf("Enter data\t");
		scanf("%d",&data);
		root = insert(root,data);
		printf("Press 1 to insert more\n");
		scanf("%d",&ch);
	}
	printtree(root);
	printf("minvalue = %d\n",minvalue(root));
}


