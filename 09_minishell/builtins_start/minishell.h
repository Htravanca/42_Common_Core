
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_envc
{
	char			*var;
	char			*value;
	int				visible;
	struct s_envc	*next;
}					t_envc;

typedef struct s_token
{
	char			**token;
	short			type;
	struct s_token	*next;
}					t_token;
// token = {"ls", "-l", NULL};

typedef struct s_shell
{
	t_token			*token;
	int				command_status;
}					t_shell;

// NEW ENV
void				ft_lstadd_back_env(t_envc **env_new, char *env);
t_envc				*ft_env_cpy(char **env, t_envc *env_new);

// NEW ENV2
void				ft_lstclear_env(t_envc **env_new);
void				print_env_list(t_envc *env);

// CD
int					ft_cd(char **args, t_envc *env);

// ECHO
int					ft_echo(char **args);

// env
int					ft_env(t_envc *env);

// EXPORT
int					ft_export(char **args, t_envc **env);
char				**ft_sep_args(char *args);
void				ft_free_sep(char **arg_sep);
void				ft_print_env_sorted(t_envc *head);

// PWD
int					ft_pwd(void);

// UNSET
int					ft_unset(char **args, t_envc **env);

// RUN CMD
void				ft_runcmd(t_shell *shell, t_envc *head);

// ENV TO ARRAY
char				**ft_convert_array(t_envc *head);
void				ft_free_env_arr(char **env);

void				free_shell(t_shell *shell);

#endif