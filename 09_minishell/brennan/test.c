#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
  Function Declarations for builtin shell commands:
 */
int		ft_cd(char **args);
int		ft_exit(char **args);
int   ft_pwd(void);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char	*builtin_str[] = {"cd",
						"pwd",
						/*"env",
						"export",
						"echo",
						"unset", */
						"exit"};

int		(*builtin_func[])(char **) = {&ft_cd,
									&ft_pwd,
									/*&env,
									&export,
									&echo,
									&unset, */
									&ft_exit};

int	lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int	ft_cd(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		printf("Expected argument to \"cd\"\n");
	else if (i == 2)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1);
		}
		return (0);
	}
	else
		printf("cd: too many arguments\n");
	return (-1);
}

int	ft_exit(char **args)
{
	return (0);
}

#define BUFFER_PWD 4096

int	ft_pwd(void)
{
	char	buffer[BUFFER_PWD];

	if (getcwd(buffer, BUFFER_PWD) != NULL)
  {
		printf("%s\n", buffer);
    return (0);
  }
	else
  {
		perror("pwd");
    return (-1);
  }
}

char	*lsh_read_line(void)
{
	char	*line;

	line = NULL;
	ssize_t bufsize = 0; // have getline allocate a buffer for us
	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS); // We recieved an EOF
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char	**lsh_split_line(char *line)
{
	int		bufsize;
	char	**tokens;
	char	*token;

	bufsize = LSH_TOK_BUFSIZE, position;
	bufsize = LSH_TOK_BUFSIZE, position = 0;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

int	lsh_launch(char **args)
{
	int	status;

	pid_t pid, wpid;
	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// Error forking
		perror("lsh");
	}
	else
	{
		// Parent process
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

int	lsh_execute(char **args)
{
	int	i;

	if (args[0] == NULL)
	{
		// An empty command was entered.
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}
	return (lsh_launch(args));
}

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	do
	{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);
		free(line);
		free(args);
	} while (status);
}

int	main(int argc, char **argv)
{
	// Load config files, if any.
	// Run command loop.
	lsh_loop();
	// Perform any shutdown/cleanup.
	return (EXIT_SUCCESS);
}
