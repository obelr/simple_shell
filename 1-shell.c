#include "shell.h"
#define TOKEN_DELIM " \t\r\n"
/**
* execute - A function that executes a process
* @argv: argument variables
* Return: (1) on success
*/
int execute(char **argv);

int execute(char **argv)
{
	pid_t main_id;

	main_id = fork();
	if (main_id == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell: ");
		}
	}
	else if (main_id < 0)
	{
		printf("Error in forking");
	}
	else
	{
		wait(&main_id);
	}
	return (1);
}
/**
* main- a function that returns path entered by user
* Return: 0 on success.
*/
int main(void)
{
	int i = 1;
	char *token;

	do {
		char *str;
		ssize_t num;
		char *argv[] = {NULL, NULL};
		size_t n = NULL;

		printf("$ ");
		str = malloc(sizeof(char) * n);
		if (!str)
		{
			return (0);
		}
		num = getline(&str, &n, stdin);
		printf("%ld", num);
		token = strtok(str, TOKEN_DELIM);
		printf("\ntoken - %s\n", token);

		if (token == NULL)
		{
			argv[0] = "";
		}
		else
		{
			argv[0] = strdup(token);
		}

		printf("argv[0] - %s\n", argv[0]);
		token = strtok(NULL, TOKEN_DELIM);
		printf("token - %s\n", token);
		printf("argv[0] - %s\n", argv[0]);
		i = execute(argv);
		free(str);
	}

	while (i);

	return (0);
}
