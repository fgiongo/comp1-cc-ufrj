/* utils.h */

void input_flush();
int linked_list_insert(void *new_node, void **list);
void *linked_list_remove(void **list);
int get_int(int min, int max, char * prompt);
long get_long(long min, long max, char * prompt);
char *get_string(int length, char * prompt);
