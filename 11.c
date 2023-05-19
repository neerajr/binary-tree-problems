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

/*int minvalue(struct node *node)
{
	if(node -> left == NULL)
		return node -> data;
	return minvalue(node -> left);
}
*/
void printtree(struct node *node)
{
	if(node -> left != NULL)
		printtree(node -> left);
	printf("%d\t",node -> data);
	if(node -> right != NULL)
		printtree(node -> right);
}

int sametree(struct node *a, struct node *b)
{
	if(a == NULL && b == NULL)
		return(1);
	else if(a != NULL && b != NULL)
		return(a -> data == b -> data && sametree(a -> left, b -> left) && sametree(a -> right, b -> right));
	else
		return(0);
}

main()
{
	struct node *root1 = NULL;
	struct node *root2 = NULL;
	int ch = 1, data;
	printf("Enter 1 to isert into first tree\n");
	scanf("%d", &ch);
	while(ch == 1){
		printf("Enter data\t");
		scanf("%d",&data);
		root1 = insert(root1,data);
		printf("Press 1 to insert more\n");
		scanf("%d",&ch);
	}
	ch =1;
	printf("Enter 1 to insert into second tree\n");
	scanf("%d",&ch);
	while(ch == 1)
	{
		printf("Enter data\t");
		scanf("%d",&data);
		root2 = insert(root2, data);
		printf("press 1 to insert more\n");
		scanf("%d",&ch);
	}
	printtree(root1);
	printf("\n");
	printtree(root2);
	if(sametree(root1, root2))
		printf("same tree\n");
	else
		printf("not same\n");
}


