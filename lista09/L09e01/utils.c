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

void linked_list_insert(void *new_node, void *list, int node_size)
{
    /* !!!caution!!!
     * function relies on pointer to next node being AT START of node! */

    void **ptr_next;

    ptr_next = new_node;
    *ptr_next = list;
    list = new_node;
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

char *get_string(int min, int max, char * prompt)
{
    /* esta funcao nao esta funcionando ainda, nao sei pq */

    int i = 0;
    char c;
    int length = 128;
    char *string = (char *) malloc(sizeof(char) * length);

    printf("%s", prompt);
    input_flush();

    do
    {
        c = getc(stdin);
        string[i] = c;
        i++;

        if (i > max)
        {
            string[i] = '\0';
            return string;
        }

        if (i == length)
        {
            length *= 2;
            string = (char *) realloc(string, length);
        }
    }
    while (c != '\n');

    string[i - 1] = '\0';
    return string;
}
