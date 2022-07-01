/* utils.c */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void input_flush()
{
	char c;
	c = fgetc(stdin);
	while(c != '\n') c = fgetc(stdin);
}

void linked_list_insert(void **new_node, void **list, int node_size)
{
    /* !!!caution!!!
     * function relies on pointer to next node being AT START of node! */

    void *temp;
    unsigned char **ptr_next;

    temp = *list;
    *list = *new_node;

    ptr_next = *new_node;
    *ptr_next = temp;
}

void *linked_list_remove(void **list)
{
    /* !!! caution !!!
     * function relies on pointer to next node being AT START of node! */

    void *temp, **next;

    temp = *list;
    next = *list;
    *list = *next;

    return temp;
}

int get_int(int min, int max, char * prompt)
{
	int i;
	do
	{
		printf("%s", prompt);
		if(!(scanf("%d", &i)))
		{
			input_flush();
			continue;
		}
	}
	while(i < min || i > max);

	return i;
}

long get_long(long min, long max, char * prompt)
{
	long i;
	do
	{
		printf("%s", prompt);
		if(!(scanf("%li", &i)))
		{
			input_flush();
			continue;
		}
	}
	while(i < min || i > max);

	return i;
}

char *get_string(int length, char * prompt)
{
    int i;
    char *c;
    printf("%s", prompt);
    c = calloc(length, sizeof(char));
    fgets(c, length, stdin);

    for (i = 0; c[i] != '\0'; i++)
        if (c[i] == '\n') c[i] = '\0';

    return c;
}