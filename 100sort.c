/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:14:00 by digil-pa          #+#    #+#             */
/*   Updated: 2023/07/01 14:13:27 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_mv(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		cost;
	int		nr_to_mv;

	temp = (*stack_a);
	cost = INT_MAX;
	while (temp->next != NULL)
	{
		if (mv_cost(temp->number, stack_a, stack_b) < cost)
		{
			cost = mv_cost(temp->number, stack_a, stack_b);
			nr_to_mv = temp->number;
		}
		temp = temp->next;
	}
	if (mv_cost(temp->number, stack_a, stack_b) < cost)
	{
		cost = mv_cost(temp->number, stack_a, stack_b);
		nr_to_mv = temp->number;
	}
	put_nr_top_b(stack_b, find_n_before(stack_b, nr_to_mv));
	mv_to_b(nr_to_mv, stack_a, stack_b);
}

int	find_n_after(t_node **stack, int n)
{
	t_node	*temp;
	int		target;

	temp = (*stack);
	target = find_max_big(stack);
	while (temp->next != NULL)
	{
		if (temp->number > n && temp->number < target)
			target = temp->number;
		temp = temp->next;
	}
	if (temp->number > n && temp->number < target)
		target = temp->number;
	return (target);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int	nr_to_top;
	int	min;

	while (ft_lstsize((*stack_b)) > 0)
	{
		if ((*stack_b)->number > find_max_big(stack_a))
		{
			nr_to_top = find_min_big(stack_a);
			put_nr_top_a(stack_a, nr_to_top);
		}
		else
		{
			nr_to_top = find_n_after(stack_a, (*stack_b)->number);
			put_nr_top_a(stack_a, nr_to_top);
		}
		push_a(stack_a, stack_b);
	}
	min = find_min_big(stack_a);
	put_nr_top_a(stack_a, min);
}

void	sort_b(t_node **stack_a, t_node **stack_b, int max)
{
	int	min;

	min = find_min_big(stack_b);
	while (ft_lstsize((*stack_a)) > 3)
	{
		if ((*stack_a)->number > max)
		{
			max = (*stack_a)->number;
			push_b(stack_a, stack_b);
		}
		else if ((*stack_a)->number < min)
		{
			min = (*stack_a)->number;
			push_b(stack_a, stack_b);
			ft_rb(stack_b);
		}
		else
			best_mv(stack_a, stack_b);
	}
	sort_small_3(stack_a);
	push_back_to_a(stack_a, stack_b);
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	max;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	max = find_max_big(stack_b);
	if ((*stack_b)->number != max)
		ft_sb(stack_b);
	sort_b(stack_a, stack_b, max);
	return ;
}
