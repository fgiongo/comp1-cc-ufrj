#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 10

void input_flush()
{
	char c;
	c = fgetc(stdin);
	while(c != '\n') c = fgetc(stdin);
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

int main (void)
{
    char *c;
    int i;
    c = get_string(STR_MAX, "String: ");
    printf("%s", c);

    return 0;
}