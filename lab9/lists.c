/**
* @file lists.c
* @brief Does linked lists operations
*
* @author Jeru Sanders
* @date 10/4/15
* @todo none
*/


#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	double x;
	struct node_t *next;
};

void newline();
void print_node_detail(struct node_t *node);
void print_list_detail(struct node_t *head);
struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head , struct node_t *node);
struct node_t *insert_tail(struct node_t *head , struct node_t *node);
struct node_t *insert_middle(struct node_t *head , struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *delete_node(struct node_t *head , double n);
void delete_list(struct node_t *head);

int main()
{
	struct node_t *head = NULL;

	printf("First Node:\n");

	head = create_node(2.0);
	print_node_detail(head);

	head = insert_head(head, create_node(1.0));
	head = insert_middle(head, create_node(1.5), 2);
	head = insert_tail(head, create_node(2));
	printf("Detailed list after inserts:\n");
	print_list_detail(head);

	delete_node(head, 1.5);
	printf("Detailed list after delete:\n");
	print_list_detail(head);

	delete_list(head);

	return 0;
}

/**
* Creates a node
* @param n The value of the double in the node
* @return The node
*/
struct node_t *create_node(double n)
{
	struct node_t *node = malloc(sizeof(struct node_t));
	if (node == NULL)
	{
		printf("Malloc failed");
		return NULL;
	}
	node->x = n;
	node->next = NULL;
	return node;
}

/**
* Prints the value in a node
* @param node The node
*/
void print_node(struct node_t *node)
{
	printf("%lf", node->x);
}

/**
* Prints the values of all the nodes in a list
* @param head The head of the list
*/
void print_list(struct node_t *head)
{
	struct node_t *current_node = head;
	
	while (current_node)
	{
		if (current_node != head)
		{
			printf(", ");
		}

		print_node(current_node);
		current_node = current_node->next;
	}
}

/**
* Adds a node to the start of a linked list
* @param head The head of the list
* @param node The node to add
* @return The new head
*/
struct node_t *insert_head(struct node_t *head , struct node_t *node)
{
	node->next = head;
	return node;
}

/**
* Adds a node to the end of a linked list
* @param head The head of the list
* @param node The node to add
* @return The new head
*/
struct node_t *insert_tail(struct node_t *head , struct node_t *node)
{
	if (!head)
	{
		return node;
	}

	struct node_t *current_node = head;
	
	while (current_node)
	{
		if (!current_node->next)
		{
			current_node->next = node;
			break;
		}

		current_node = current_node->next;
	}

	return head;
}

/**
* Adds a node to the middle of a linked list
* @param head The head of the list
* @param node The node to add
* @param pos The position to add the node
* @return The new head
*/
struct node_t *insert_middle(struct node_t *head , struct node_t *node, int pos)
{
	if (pos < 1)
	{
		printf("Value must be above one");
		return head;
	}

	if (!head)
	{
		return node;
	}

	struct node_t *current_node = head;
	struct node_t *next_node = NULL;
	int i = 1;
	
	while (i < pos - 1)
	{
		current_node = current_node->next;
		i++;
	}

	next_node = current_node->next;
	current_node->next = node;
	if (next_node)
	{
		node->next = next_node;
	}

	return head;
}

/**
* Returns the number of nodes in the list
* @param head The head of the list
* @return The number of nodes
*/
int count_nodes(struct node_t *head)
{
	int count = 1;

	struct node_t *current_node = head;
	while (current_node->next)
	{
		count++;
		current_node = current_node->next;
	}

	return count;
}

/**
* Removes a node from a list and frees it
* @param head The head of the list
* @param n The value of node to be removed
* @return The new head
*/
struct node_t *delete_node(struct node_t *head , double n)
{
	struct node_t *current_node = head;
	struct node_t *prev_node = NULL;
	struct node_t *next_node = NULL;

	while(current_node->x != n)
	{
		prev_node = current_node;
		current_node = current_node->next;

		if (current_node == NULL)
		{
			return head;
		}
	}

	next_node = current_node->next;
	if (prev_node)
	{
		prev_node->next = NULL;
	}

	if (prev_node && next_node)
	{
		prev_node->next = next_node;
	} else if (!prev_node && next_node) {
		head = current_node->next;
	}

	free(current_node);

	return head;
}

/**
* Removes all nodes from a list and frees them
* @param head The head of the list
*/
void delete_list(struct node_t *head)
{
	struct node_t *current_node = head;
	struct node_t *prev_node = NULL;

	while(current_node)
	{
		prev_node = current_node;
		current_node = current_node->next;

		free(prev_node);
	}
}

/**
* Prints a new line
*/
void newline()
{
	printf("\n");
}

/**
* Prints the details of a node
* @param node The node to print
*/
void print_node_detail(struct node_t *node)
{
	if (node->next)
	{
		printf("{ x: %lf, next: %p } at: %p\n", node->x, node->next, node);
	} else {
		printf("{ x: %lf, next: %s } at: %p\n", node->x, "NULL", node);
	}
}

/**
* Runs print_node_detail on every node in a list
* @param head The head of the list
*/
void print_list_detail(struct node_t *head)
{
	struct node_t *current_node = head;
	
	while (current_node)
	{
		print_node_detail(current_node);
		current_node = current_node->next;
	}
}