
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
//# include "libft/libft.h"
//# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
    int                 data;
    int                 index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;

char    **ft_split(char const *s, char c);
long    ft_atoi(char *str);
int     ft_nb_str_valid(char *str);
int     ft_nb_limit(long nb);

#endif