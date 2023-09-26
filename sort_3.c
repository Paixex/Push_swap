/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:22:05 by digil-pa          #+#    #+#             */
/*   Updated: 2023/07/01 14:23:27 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	int	val_1;
	int	val_2;

	val_1 = (*stack_a)->number;
	val_2 = (*stack_a)->next->number;
	if (val_1 > val_2)
		ft_sa(stack_a);
	return ;
}

void	sortsmall_a(t_node **stack_a, int val_1, int val_3)
{
	if (val_1 > val_3)
		ft_rra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	sortsmall_b(t_node **stack_a, int val_2, int val_3)
{
	if (val_2 < val_3)
		ft_ra(stack_a);
	else
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	sort_small_3(t_node **stack_a)
{
	int	val_1;
	int	val_2;
	int	val_3;

	if (ft_lstsize((*stack_a)) < 3)
	{
		sort_2(stack_a);
		return ;
	}
	val_1 = (*stack_a)->number;
	val_2 = (*stack_a)->next->number;
	val_3 = (*stack_a)->next->next->number;
	if (check_if_ok(stack_a) == TRUE)
		return ;
	if (val_1 < val_2)
	{
		sortsmall_a(stack_a, val_1, val_3);
	}
	else if (val_1 > val_2 && val_1 > val_3)
	{
		sortsmall_b(stack_a, val_2, val_3);
	}
	else
		ft_sa(stack_a);
}
