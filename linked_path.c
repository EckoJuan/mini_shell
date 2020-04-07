#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
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

/**
 * _strlen - returns the length of a string.
 * @s: pointer to String
 * Return: Nothing
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * _strcat - concatenates two strings.
 * @dest: string to destiny
 * @src: string to source
 * Return: Return a concatenate string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, lenght = 0;

	while (*(dest + lenght) != '\0')
		lenght++;
	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + lenght) = *(src + i);
		lenght++;
	}
	*(dest + lenght) = *(src + i);

	return (dest);
}
/**
 * add_node_end - function that adds a node
 * @head: head of the list
 * @str: String of the instance
 * Return: new list
 */
path_node *add_node_end(path_node **head, const char *str)
{
	path_node *new_node, *tmp;

	new_node = malloc(sizeof(path_node));
	if (new_node != NULL)
	{
		new_node->full_path_name = strdup(str);
		new_node->len_path_name = _strlen(str);
		new_node->next = NULL;
	} else
	{
		return (NULL);
	}

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;

	return (new_node);
}


void add_path_to_list(path_node **head, char *current_path)
{
	char *token = strtok(current_path, ":");

	while (token != NULL)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}

char *_getenv(const char *name, char **current_env)
{
	char *token1, *token2;
	int i = 0;


	while (current_env[i])
	{
		token1 = strtok(current_env[i], "=");
		token2 = strtok(NULL, "=");
		if (strcmp(name, token1) == 0)
			return (token2);
		i++;
	}
	return (NULL);
}

size_t print_list(const path_node *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->full_path_name == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->full_path_name);
		h = h->next;
		count++;
	}

	return (count);
}

void validate_file(const path_node *h, char *file)
{
	char *full_path_name;
    struct stat st;
    int found;

	while (h != NULL )
	{
		full_path_name = malloc(sizeof(char) * (h->len_path_name + _strlen(file) + 1));
        if (full_path_name == NULL)
            return;
        /*_strcat("/",file);*/
		full_path_name = _strcat(h->full_path_name, file);
        /*printf("concat: %s\n",full_path_name);*/
		
        if (stat(full_path_name, &st) == 0)
		{
			printf("Found: %s\n", full_path_name);
			/*return (full_path_name);*/
		}
		else
		{
            printf("Not Found\n");
            free(full_path_name);
		}
        h = h->next;
	}
    /*return (NULL);*/
}


int main(int ac, char **av, char **env)
{
	path_node *head;
	head = NULL;

	char *directories = _getenv("PATH", env);
	add_path_to_list(&head, directories);
	/*print_list(head);*/
    printf("\n\n");
    validate_file(head,av[1]);
	return (0);
}
