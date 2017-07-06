#include <stdio.h>
#include <stdlib.h>

typedef struct btree
{
	struct btree * left;
	struct btree * right;
	int value;
} btree;

void insert(btree ** root, int value)
{
	if( ! (*root) ) // base case
	{
		*root = (struct btree*) malloc(sizeof(struct btree));
		(*root)->right = NULL;
		(*root)->right = NULL;
		(*root)->value = value;
		return;
	}
	if(value < (*root)->value)
		insert( &(*root)->left, value);
	else if(value > (*root)->value)
		insert( &(*root)->right, value);
	else
		printf("Error, value alrady exist=%d \n", value);
}

void traversePreorder(btree * root)
{
	
	if(!root)
		return;
	printf("%d ", root->value);
	traversePreorder(root->left);
	traversePreorder(root->right);
}

void BST(btree * root, int value)
{
	if(!root)
	{
		printf("NOT Found in the tree: %d\n", value);
		return;
	}
	if(value < root->value)
		BST(root->left, value);
	else if(value > root->value)
		BST(root->right, value);
	else
		printf("Found in the tree: %d\n", value);
}

int getMaxHight(btree * root)
{
	if(!root) 
		return 0;
	int left = getMaxHight(root->left);
	int right = getMaxHight(root->right);
	return left > right ? 1+left : 1+right;
}

int LowestCommonAncestor(btree * root, int v1, int v2)
{
	while(root!=NULL)
	{
		if(root->value > v1 && root->value > v2)
			root = root->left, v1, v2;
		else if(root->value < v1 && root->value < v2)
			root = root->right, v1, v2;
		else
			return root->value;
	}
	return -1;
}

int main()
{
	btree * root = malloc(sizeof(struct btree));
	root -> value = 50;
	insert( &root, 40);
	insert( &root, 20);
	insert( &root, 10);
	insert( &root, 25);
	insert( &root, 30);
	insert( &root, 35);
	insert( &root, 60);
	insert( &root, 90);
	insert( &root, 95);
	insert( &root, 100);
	insert( &root, 50);
	traversePreorder( root); printf("\n");
	BST(root,30);
	BST(root,31);
	printf("Hight is %d\n", getMaxHight(root));
	printf("LowestCommonAncestor is %d\n",LowestCommonAncestor(root, 10, 35));
	printf("LowestCommonAncestor is %d\n",LowestCommonAncestor(root, 65, 100));
	return 0;
}