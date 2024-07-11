/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:17:01 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:38:12 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cost
{
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					total_cost;
}						t_cost;

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					bf;
	t_cost				*cost;
	struct s_stack_node	*next;
}						t_stack_node;

// CLEAN
void					ft_cost_clean(t_stack_node **b);
void					ft_error_msg(t_stack_node **a, t_stack_node **b);
void					ft_clean_lst(t_stack_node **lst);

// COST
void					ft_total_cost_calc(t_stack_node **lst);
void					ft_best_cost(t_stack_node **lst);
void					ft_cost_calc_auxb(t_stack_node **b,
							t_stack_node *temp_b);
void					ft_cost_calc_auxa(t_stack_node **a,
							t_stack_node *temp_a, t_stack_node *temp_b);
void					ft_cost_calc(t_stack_node **a, t_stack_node **b);

// FT_SPLIT
char					**ft_split(char const *s, char c);
void					ft_free(char **arr, size_t atual);

// LST
t_stack_node			*ft_lstnew(int content, int index);
void					ft_lstadd_back(t_stack_node **lst, int content,
							int index);
int						ft_lsta_nok(t_stack_node *a);
int						ft_is_lst_sorted(t_stack_node *a);
int						ft_lst_size(t_stack_node *a);

// OPERATIONS P
void					ft_update_index(t_stack_node **lst);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);

// OPERATIONS RR
void					ra(t_stack_node **a, int print);
void					rb(t_stack_node **b, int print);
void					rr(t_stack_node **a, t_stack_node **b);

// OPERATIONS RRR
void					rra(t_stack_node **a, int print);
void					rrb(t_stack_node **b, int print);
void					rrr(t_stack_node **a, t_stack_node **b);

// OPERATIONS SS
void					sa(t_stack_node **a, int print);
void					sb(t_stack_node **b, int print);
void					ss(t_stack_node **a, t_stack_node **b);

// PARSING
long					ft_atoi(char *str);
int						ft_nb_str_valid(char *str);
int						ft_parsing_aux(t_stack_node **a, char *arr, int pos);
t_stack_node			*ft_argvs_format(int argc, char **argv, t_stack_node *a,
							t_stack_node *b);
t_stack_node			*ft_str_format(char *str, t_stack_node *a,
							t_stack_node *b);

// SORT AUX
int						ft_index_bg(t_stack_node *lst);
int						ft_index_sm(t_stack_node *lst);
int						ft_mean_val(t_stack_node *a);
void					ft_exec_aux(t_stack_node **a, t_stack_node **b,
							t_stack_node *temp_b);
void					ft_exec(t_stack_node **a, t_stack_node **b,
							t_stack_node *temp_b);

// SORT 3
void					ft_sort_three(t_stack_node **a);
void					ft_put_top_a(t_stack_node **a, int index_sm, int size);
void					ft_sort_four(t_stack_node **a, t_stack_node **b);
void					ft_sort_five(t_stack_node **a, t_stack_node **b);
void					ft_sort_main(t_stack_node **a, t_stack_node **b,
							int nodes);

// SORT
void					ft_first_step(t_stack_node **a, t_stack_node **b);
void					ft_bf_finder(t_stack_node **a, t_stack_node **b);
void					ft_find_and_exec(t_stack_node **a, t_stack_node **b);
void					ft_rotate_a(t_stack_node **a);
void					ft_sort(t_stack_node **a, t_stack_node **b);

#endif