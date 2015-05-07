/**
* @file reverse.c
* @brief Reverses a linked list
* @details Reverses a linked list from a file passed in
* @author Jeru Sanders
* @date 5/7/15
* @todo None
* @bug None
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 256

struct list_t {
        int count;
        struct node_t *head;
};


struct node_t {
        int n;
        struct node_t *next;
};

/**
* Creates a list
* @return The created list
*/
struct list_t *create_list(void)
{
	struct list_t *list = malloc(sizeof(struct list_t));
	list->count = 0;
	list->head = NULL;

	return list;
}

/**
* Creates a new node, an element of the the list
* @param n The value of the node
* @return The created node
*/
struct node_t *create_node(int n)
{
	struct node_t *node = malloc(sizeof(struct node_t));
	node->n = n;
	node->next = NULL;

	return node;
}

/**
* Push a node onto the front of list
* @param list The list to push into
* @param node The node to push into the list
*/
void push(struct list_t *list, struct node_t *node)
{
	list->count++;
	node->next = list->head;
	list->head = node;
}

/**
* Prints a node
* @param node The node to print
*/
void print_node(struct node_t *node)
{
	printf("%d", node->n);
}

/**
* Prints a list
* @param list The list to print
*/ 
void print_list(struct list_t *list)
{
	struct node_t *current_node = list->head;

	if (list->count == 0){
		printf("(empty)\n");
		return;
	}

	int i;
	for (i = 0;; i++)
	{
		if (current_node == NULL) {
			break;
		}

		print_node(current_node);

		printf("\n");
		current_node = current_node->next;
	}

	//printf("\nCount: %d\n", list->count);
	printf("\n");
}

/**
* Frees a list
* @param list The list to free
*/
void free_list(struct list_t *list)
{
	struct node_t *current_node = list->head;
	struct node_t *prev_node = list->head;

	if (list->count == 0){
		return;
	}

	int i;
	for (i = 0;; i++)
	{
		if (current_node == NULL) {
			break;
		}

		prev_node = current_node;
		current_node = current_node->next;
		list->count--;

		free(prev_node);
	}

	free(list);
}

/**
* Pushes the head of one list onto another
* @param src The first list
* @param dest The second list
*/ 
void move_node(struct list_t *dest, struct list_t *src)
{
	struct node_t *taken_node = src->head;

	src->head = src->head->next;
	
	push(dest, taken_node);
}

/**
* Reverses a list
* @param list The list to reverse
*/ 
void reverse(struct list_t *list)
{
	struct list_t *new_list = create_list();

	int i;
	for (i = 0; i < list->count; i++) {
		move_node(new_list, list);
	}

	*list = *new_list;
	free(new_list);
}


int main(int argc, char *argv[])
{
	struct list_t *list = create_list();

	FILE *file = fopen(argv[1], "r");

	char file_string[4];
	while(!feof(file))
	{
		fscanf(file, "%[^\n]\n", file_string);
		push(list, create_node(atoi(file_string)));
	}

	fclose(file);

	printf("list");
	print_list(list);

	reverse(list);

	printf("list reversed");
	print_list(list);

	free_list(list);

	return 0;
}
