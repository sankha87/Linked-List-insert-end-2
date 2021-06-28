//insertion at the end of the LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// A linked list node
struct Node
{
	int data;
	struct Node *next;
}*head = NULL, *first = NULL;

struct Node* push(struct Node *head_ref, int new_data)						//insertion in the beginning of the LinkedList
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

void append(int new_data)							//insertion at the end of the LinkedList
{													// Time complexity of append is O(n) where n is the number of nodes in linked list.
	struct Node *head_ref2 = head;
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = NULL;
		while (head_ref2->next != NULL)
			head_ref2 = head_ref2->next;
		head_ref2->next = new_node;
	}
}

void printList(struct Node *node)		// This function prints contents of linked list starting from head
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	head = push(head, 9);
	first = push(head, 7);
	first = push(first, 5);
	// while(1)  - for checking Stack Overflow condition
	first = push(first, 3);

	printf("\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	append(12);
	append(15);
	// while(1)  - for checking Stack Overflow condition
	append(18);
	printf("\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	_getch();
}