#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	struct node* next;
	int data;
} node;

int insert(node* head, int data)
{
	if(head==NULL)
		return 0;
	while(head->next)
		head = head->next;

	struct node* obj = malloc(sizeof(node));
	obj->next = NULL;
    obj->data = data;
    head->next = obj;
    return 1;

}

void traverse(struct node* head)
{
	if(head==NULL)
	{
		printf("Error, head is NULL\n");
		return;
	}
	while(head->next)
	{
		printf("%d->", head->data);
		head = head->next;
	}
	printf("%d->end\n",head->data);
}

void delete(struct node** head, int order)
{
	if( !head || !*head )
		return;
	if(order<=0)
		return;
	node* curr = malloc(sizeof(node));
	curr = *head;

	if(order == 1)
	{
		if(curr->next)
		{
			curr=*head;
			(*head) = (*head)->next;
			free(curr);
			
		}
		else
		{
			*head = NULL;
			
		}
	}
	else
	{
		int steps = 1;
		while(curr->next)
		{
			if(steps+1 == order)
			{
				node* temp = malloc(sizeof(node));
				temp = curr;
				curr = curr->next;
				temp->next = curr->next;
				free(curr);

			}
			else
			{
				steps++;
				curr = curr->next;
			}

		}
		return;
	}

}

void reverse(node** head)
{
	if( !(head) || ! (*head) || ! (*head)->next)
		return;

	node* next = NULL;
	node* prev = NULL;

	while((*head))
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;
	return;
}

int main()
{
	struct node* head = malloc(sizeof(node));
	//traverse(head);

	head->next=NULL;
	head->data = 1;

	//traverse(head);

	if(insert(head,2))
	{
		//traverse(head);
	}
	if(insert(head,3))
	{
		//traverse(head);
	}
	if(insert(head,4))
	{
		//traverse(head);
	}
	traverse(head);
	reverse(&head);
	traverse(head);
	return 0;
}