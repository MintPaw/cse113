#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	double x;
	struct node_t *next;
};

void newline();
struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head , struct node_t *node);
struct node_t *insert_tail(struct node_t *head , struct node_t *node);
struct node_t *insert_middle(struct node_t *head , struct node_t *node, int pos);
// int count_nodes(struct node_t *head);
// struct node_t *delete_node(struct node_t *head , double n);
// void delete_list(struct node_t *head);

int main()
{
	struct node_t *head = NULL, *tail = NULL;

	head = create_node(1);
	head = insert_tail(head, create_node(2));
	head = insert_tail(head, create_node(4));
	head = insert_tail(head, create_node(5));

	head = insert_middle(head, create_node(3), 2);
	print_list(head);
	newline();

	return 0;
}

void newline()
{
	printf("\n");
}

struct node_t *create_node(double n)
{
	struct node_t *node = malloc(sizeof(struct node_t));
	node->x = n;
	return node;
}

void print_node(struct node_t *node)
{
	printf("%lf", node->x);
}

void print_list(struct node_t *head)
{
	struct node_t *currentNode = head;
	
	while (currentNode)
	{
		if (currentNode != head)
		{
			printf(", ");
		}

		print_node(currentNode);
		currentNode = currentNode->next;
	}
}

struct node_t *insert_head(struct node_t *head , struct node_t *node)
{
	node->next = head;
	return node;
}

struct node_t *insert_tail(struct node_t *head , struct node_t *node)
{
	struct node_t *currentNode = head;
	
	while (currentNode)
	{
		if (!currentNode->next)
		{
			currentNode->next = node;
			break;
		}

		currentNode = currentNode->next;
	}

	return head;
}

struct node_t *insert_middle(struct node_t *head , struct node_t *node, int pos)
{
	struct node_t *currentNode = head;
	struct node_t *nextNode = head;
	int i;
	
	for (i = 0; i < pos - 1; i++)
	{
		currentNode = currentNode->next;
		if (currentNode->next)
		{
			nextNode = currentNode->next->next;
		}
	}

	currentNode->next = node;
	if (nextNode)
	{
		node->next = nextNode;
	}

	return head;
}