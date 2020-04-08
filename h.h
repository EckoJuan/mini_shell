#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/**
 * struct path_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct path_s
{
	char *full_path_name;
	unsigned int len_path_name;
	struct path_s *next;
} path_node;

path_node *add_node_end(path_node **head, const char *str);
int _strlen(const char *s);
void add_path_to_list(path_node **head, char *current_path);
char *_getenv(const char *name, char **current_env);
size_t print_list(const path_node *h);
char *linked_path(char *av, char **env);

#endif
