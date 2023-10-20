/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:56:47 by digil-pa          #+#    #+#             */
/*   Updated: 2023/10/20 13:09:59 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*------------------------------------------------------------*/

# define FALSE 0
# define TRUE 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*------------------------------------------------------------*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

/*------------------------------------------------------------*/

typedef struct node_t
{
	int				number;
	struct node_t	*next;
}				t_node;

/*------------------------------------------------------------*/

//LISTS

int					ft_lstsize(t_node *lst);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_lstadd_back(t_node **lst, t_node *new);
void				ft_lstadd_front(t_node **lst, t_node *new);
t_node				*ft_lstnew(int content);
void				ft_clean_lst(t_node **stack);

//SORT

void				sort_small_3(t_node **stack_a);
void				sort_small_5(t_node **stack_a, t_node **stack_b);
void				sort_all(t_node	**stack_a, t_node **stack_b);
void				sort_big(t_node **stack_a, t_node **stack_b);
void				sort_b(t_node **stack_a, t_node **stack_b, int max);
void				sortsmall_b(t_node **stack_a, int val_2, int val_3);
void				sortsmall_a(t_node **stack_a, int val_1, int val_3);
void				sort_2(t_node **stack_a);
void				sort(t_node **stack_a, t_node **stack_b, int ac);
//CHECKERS

int					ft_isdigit(int k);
int					signal_check(int ac, char **av);
int					digit_checker(int ac, char **av);
int					check_int_val(int ac, char **av);
int					check_if_ok(t_node **stack);
int					check_for_rep(int ac, char **av);
int					check_input(int ac, char **av);
int					okok(t_node **stack);

//MOVES

void				push_back_to_a(t_node **stack_a, t_node **stack_b);
void				best_mv(t_node **stack_a, t_node **stack_b);
void				mv_to_b(int n, t_node **stack_a, t_node **stack_b);
void				put_nr_top_a(t_node **stack, int nr_to_mv);
void				put_nr_top_b(t_node **stack, int nr_to_mv);
void				put_on_top(t_node **stack, int i);
void				push_b(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_a, t_node **stack_b);
void				ft_ra(t_node **stack_a);
void				ft_rb(t_node **stack_b);
void				ft_rr(t_node **stack_a, t_node **stack_b);
void				ft_sa(t_node **stack_a);
void				ft_sb(t_node **stack_b);
void				ft_ss(t_node **stack_a, t_node **stack_b);
void				ft_rra(t_node **stack_a);
void				ft_rrb(t_node **stack_b);
void				ft_rrr(t_node **stack_a, t_node **stack_b);

//PRINTS

t_node				*insert_stack_a(char **av);
void				print_stack(t_node *head);

//FINDS

int					find_min(t_node **stack_a);
long long			ft_atoi(const char *str);
int					find_max_big(t_node **stack);
int					find_min_big(t_node **stack);
int					find_n_before(t_node **stack_b, int number);
int					cost_a(t_node **stack_a, int n);
int					cost_b(t_node **stack_b, int n, int res, int max);
int					find_n_after(t_node **stack, int n);
int					mv_cost(int n, t_node **stack_a, t_node **stack_b);

#endif