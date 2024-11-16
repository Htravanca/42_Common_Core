
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

#endif