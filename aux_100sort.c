/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_100sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:21:25 by digil-pa          #+#    #+#             */
/*   Updated: 2023/10/20 13:10:16 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_big(t_node **stack)
{
	t_node	*temp;
	int		max;

	temp = (*stack);
	max = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number > max)
			max = temp->number;
		temp = temp->next;
	}
	if (temp->number > max)
		max = temp->number;
	return (max);
}

int	find_min_big(t_node **stack)
{
	t_node	*temp;
	int		min;

	temp = (*stack);
	min = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	if (temp->number < min)
		min = temp->number;
	return (min);
}

void	put_nr_top_a(t_node **stack, int nr_to_mv)
{
	t_node	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp->number != nr_to_mv)
	{
		temp = temp->next;
		i++;
	}
	if (i >= ft_lstsize((*stack)) / 2)
	{
		while (i++ < ft_lstsize((*stack)))
			ft_rra(stack);
	}
	else
	{
		while (i-- > 0)
			ft_ra(stack);
	}
}

void	put_nr_top_b(t_node **stack, int nr_to_mv)
{
	t_node	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp->number != nr_to_mv)
	{
		temp = temp->next;
		i++;
	}
	if (i >= ft_lstsize((*stack)) / 2)
	{
		while (i++ < ft_lstsize((*stack)))
			ft_rrb(stack);
	}
	else
	{
		while (i-- > 0)
			ft_rb(stack);
	}
}

int	find_n_before(t_node **stack_b, int number)
{
	t_node	*temp;
	int		target;

	temp = (*stack_b);
	target = find_min_big(stack_b);
	while (temp->next != NULL)
	{
		if (temp->number > target && temp->number < number)
			target = temp->number;
		temp = temp->next;
	}
	if (temp->number > target && temp->number < number)
		target = temp->number;
	return (target);
}
