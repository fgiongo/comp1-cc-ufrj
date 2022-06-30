/* utils.c */

#include <stdio.h>
#include "utils.h"

void input_flush()
{
	char c;
	c = fgetc(stdin);
	while(c != '\n') c = fgetc(stdin);
}

int linked_list_insert(void *new_node, void *list, int node_size)
{
    /* !!!caution!!!
     * function relies on pointer to next node being AT END of node! */

    unsigned char *ptr, **ptr_next, *ptr_end;


    if (list == NULL)
    {
        ptr_next = (unsigned char **) new_node + (node_size - sizeof(ptr));
        ptr_end = (unsigned char *) new_node + node_size;

        write_zeroes(ptr_next, ptr_end);

        list = new_node;
        return 1;
    }

    ptr = list;
    list = new_node;
    ptr_next = (unsigned char **) list + (node_size - sizeof(ptr));
    *ptr_next = ptr;

    return 1;
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

void write_zeroes(void *start, void *end)
{
    int i;
    char *_start, *_end;

    _start = start;
    _end = end;

    for (i = 0; (_start + i) < _end; i++)
    {
        *(_start + i) = 0x00;
    }
}
