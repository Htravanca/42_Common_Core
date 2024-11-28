
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct env_copy
{
	char			*var;
	char			*value;
	int				visible;
	struct env_copy	*next;
}					envc;

// NEW ENV
void				ft_lstadd_back_env(envc **env_new, char *env);
envc				*ft_env_cpy(char **env, envc *env_new);

// NEW ENV2
void				ft_lstclear_env(envc **env_new);
void				print_env_list(envc *env);

// CD
int					ft_cd(char **args, envc *env);

// ECHO
int					ft_echo(char **args);

// env
int					ft_env(envc *env);

// EXPORT
int 				ft_export(char **args, envc **env);
char 				**ft_sep_args(char *args);
void				ft_print_env_sorted(envc *head);

// PWD
int					ft_pwd(void);

// UNSET
int					ft_unset(char **args, envc **env);

#endif