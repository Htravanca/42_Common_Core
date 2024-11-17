
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
char				*ft_env_var(char *env);
char				*ft_env_value(char *env);
envc				*ft_lstnew_env(char *env);
void				ft_lstadd_back_env(envc **env_new, char *env);
envc				*ft_env_cpy(char **env, envc *env_new);

// NEW ENV2
void				ft_lstclear_env(envc **env_new);
void				print_env_list(envc *env);

// env
int					ft_env(envc *env);

// PWD
int					ft_pwd(void);

#endif