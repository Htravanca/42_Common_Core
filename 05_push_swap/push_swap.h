
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
    //struct s_stack_node *prev;
}   t_stack_node;

//FT_SPLIT
char            **ft_split(char const *s, char c);
void	        ft_free(char **arr, size_t atual);

//PARSING
long            ft_atoi(char *str);
int             ft_nb_str_valid(char *str);
void            ft_error_msg(void);
t_stack_node    *ft_argvs_format(int argc, char **argv, t_stack_node *a);
t_stack_node    *ft_str_format(char *str, t_stack_node *a);

//FT_LST
t_stack_node    *ft_lstnew(int content, int index);
void	        ft_lstadd_back(t_stack_node **lst, int content, int index);

//OPERATIONS SS
void            sa(t_stack_node **a, int print);
void            sb(t_stack_node **b, int print);
void            ss(t_stack_node **a, t_stack_node **b);

//OPERATIONS RR
void            ra(t_stack_node **a, int print);
void            rb(t_stack_node **b, int print);
void            rr(t_stack_node **a, t_stack_node **b);

//OPERATIONS RRR
void            rra(t_stack_node **a, int print);
//void            rrb(t_stack_node **b, int print);
//void            rrr(t_stack_node **a, t_stack_node **b);

#endif