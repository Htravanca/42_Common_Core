
//fprintf(stderr, "path2:%s\n", path);
//fprintf(stderr, "path1:%s\n", path);


/* char	*ft_path(char **cmdsarr, char **envp)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	options = ft_split(envp[i] + 5, ':');
	if (!options)
		return (NULL);
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
} */


/* char	*ft_path(char **cmdsarr, char **envp)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	if (!*envp)
		options = ft_options();
	else
	{
		while (!ft_strnstr(envp[i], "PATH", 4))
			i++;
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
} */


/* static void	ft_wait(int *pid, int i)
{
	int	j;
	int	status;

	j = 0;
	while (j <= i)
	{
		//fprintf(stderr, "j:%d\n", j);
		if (waitpid(pid[j], &status, 0) < 0)
		{
			perror("Error waiting for child process");
			exit(1);
		}
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		j++;
	}
} */

/* static void	ft_wait(void)
{
	int	status;

	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
} */

	/* waitpid(-1, &status, 0);
	fprintf(stderr, "error:%d\n", WEXITSTATUS(status));
	if (WEXITSTATUS(status) != 0)
	{
		waitpid(-1, NULL, 0);
		exit(WEXITSTATUS(status));
	}  */


/* static void	ft_loop_process(int argc, char **argv, char **envp)
{
	int	pid[10000];
	int	i;
	int	wfd;

	i = 2;
	while (i < (argc - 2))
	{
		pid[i - 2] = ft_execute_child(argv[i], envp);
		i++;
	}
	wfd = ft_handle_error(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644), "Error opening file2");
	dup2(wfd, STDOUT_FILENO);
	close(wfd);
	pid[i - 2] = ft_handle_error(fork(), "Fork error");
	if (pid[i - 2] == 0)
		ft_execute(argv[argc - 2], envp);
	ft_wait(i);
} */

/* int	ft_execute_child(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	ft_handle_error(pipe(fd), "Pipe Error");
	pid = ft_handle_error(fork(), "Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		//dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		//close(fd[0]);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		//close(fd[1]);
	}
	return (pid);
} */

/* static void	ft_wait(int i)
{
	int	status;
	int	statusf;

	statusf = 0;
	while ((i - 2) >= 0)
	{
		waitpid(-1, &status, 0);
		fprintf(stderr, "path2:%d\n", WEXITSTATUS(status));
		if (WEXITSTATUS(status) != 0)
			statusf = WEXITSTATUS(status);
		i--;
	}
	exit(statusf);
} */

/* static void	ft_wait(int *pid, int i)
{
	int	j;
	int	status;

	j = 0;
	while (j <= i)
	{
		fprintf(stderr, "j:%d\n", j);
		if (waitpid(pid[j], &status, 0) < 0)
		{
			perror("Error waiting for child process");
			exit(1);
		}
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		j++;
	}
} */

/* char	*ft_path(char **cmdsarr, char **envp, char *path)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	while (*envp && envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (i == 0 || envp[i] == NULL || !ft_strnstr(envp[i], "/usr/bin",
			ft_strlen(envp[i])))
	{
		if (ft_check_path(path))
			options = ft_abs_path(path);
		else
			options = ft_options();
	}
	else
	{
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
} */



/* char	*ft_path(char **cmdsarr, char **envp, char *path)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	options = NULL;
	while (*envp && envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	fprintf(stderr, "i:%d\n", i);
	fprintf(stderr, "PATH:%s\n",envp[i]);
	if (ft_check_path(path))
		return (path);
	else if (i == 0)// || envp[i] == NULL) || !ft_strnstr(envp[i], "/usr/bin", ft_strlen(envp[i])))
			options = ft_options();
	else if (envp[i] && ft_strnstr(envp[i], "/usr/bin", ft_strlen(envp[i])))
	{
		fprintf(stderr, "Entrei normal\n");
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	//LEAKS no find paths!!!!
	fprintf(stderr, "PATH:%s\n",envp[i]);
	fprintf(stderr, "options:%s\n", options[0]);
	if (options != NULL)
	{
		pfinal = ft_find_path(options, cmdsarr[0]);
		ft_free_arr(options);
		fprintf(stderr, "Final:%s\n", pfinal);
	}
	return (pfinal);
} */


/* NAME			= pipex
LIBFT			= libft/libft.a

SRC = pipex.c pipex_aux.c pipex_aux2.c split_adapt.c split_adapt2.c
OBJ = $(SRC:.c=.o)
SRC_B = pipex_bonus.c pipex_aux_bonus.c pipex_aux2_bonus.c split_adapt_bonus.c split_adapt2_bonus.c
OBJ_B = $(SRC_B:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

bonus: $(NAME)_bonus

#bonus: $(OBJ_B) $(LIBFT)
#		@${CC} ${CFLAGS} $(OBJ_B) $(LIBFT) -o $(NAME)
#		@echo "$(NAME) (bonus) created"

$(NAME):	$(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

$(NAME)_bonus: $(OBJ_B) $(LIBFT)
		@${CC} ${CFLAGS} $(OBJ_B) $(LIBFT) -o $(NAME)
		@echo "$(NAME) (bonus) created"

$(LIBFT):
	@make -s -C ./libft

clean:
	@$(RM) $(OBJ) $(OBJ_B)
	@make clean -s -C ./libft
	@echo "$(NAME) cleaned"


fclean:			clean
					@$(RM) $(NAME)
					@make fclean -s -C ./libft

re: fclean all

.PHONY: all clean fclean re */
