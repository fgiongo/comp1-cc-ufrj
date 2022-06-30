/* utils.c */

#include <stdio.h>
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
     * function relies on pointer to next node being AT END of node! */

    unsigned char *ptr, **ptr_next;


    if (list == NULL)
    {
        ptr_next = (unsigned char **) new_node + (node_size - sizeof(ptr));
        *ptr_next = NULL;

        list = new_node;
        return;
    }

    ptr = list;
    list = new_node;
    ptr_next = (unsigned char **) list + (node_size - sizeof(ptr));
    *ptr_next = ptr;
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

