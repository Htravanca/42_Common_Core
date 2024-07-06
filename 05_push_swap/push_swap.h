
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
//# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_cost
{
	int		        ra;
	int		        rb;
	int		        rr;
	int		        rra;
	int		        rrb;
	int		        rrr;
	int		        total_cost;
}	t_cost;

typedef struct s_stack_node
{
    int                 data;
    int                 index;
    int                 bf;
    t_cost              *cost;
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

//LST
t_stack_node    *ft_lstnew(int content, int index);
void	        ft_lstadd_back(t_stack_node **lst, int content, int index);
int             ft_lsta_nok(t_stack_node *a);
int             ft_is_lst_sorted(t_stack_node *a);
int             ft_lst_size(t_stack_node *a);

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
void            rrb(t_stack_node **b, int print);
void            rrr(t_stack_node **a, t_stack_node **b);

//OPERATIONS PP
void            ft_update_index(t_stack_node **lst);
void            pa(t_stack_node **a, t_stack_node **b);
void            pb(t_stack_node **a, t_stack_node **b);

//SORT 3
void            ft_sort_three(t_stack_node **a);
int             ft_index_bg(t_stack_node *a);
int             ft_index_sm(t_stack_node *a);
void            ft_put_top_a(t_stack_node **a, int index_sm, int size);
void            ft_sort_four(t_stack_node **a, t_stack_node **b);
void            ft_sort_five(t_stack_node **a, t_stack_node **b);

//SORT
int				ft_mean_val(t_stack_node *a);
void            ft_first_step(t_stack_node **a, t_stack_node **b);
void    		ft_bf_finder(t_stack_node **a, t_stack_node **b);
void			ft_find_and_exec(t_stack_node **a, t_stack_node **b);
void            ft_sort(t_stack_node **a, t_stack_node **b);

//COST
void 			ft_total_cost_calc(t_stack_node **lst);
void 			ft_best_cost(t_stack_node **lst);
void			ft_cost_calc(t_stack_node **a, t_stack_node **b);
void    		ft_cost_clean(t_stack_node **b);


#endif