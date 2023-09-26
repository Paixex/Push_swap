/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:49:50 by digil-pa          #+#    #+#             */
/*   Updated: 2023/06/01 18:54:21 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate a - Shift all elements of a by 1 - first becomes last
void	ft_ra(t_node **stack_a)
{
	t_node	*last_node;
	t_node	*new_second;

	last_node = *stack_a;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	new_second = *stack_a;
	*stack_a = (*stack_a)->next;
	last_node->next = new_second;
	new_second->next = NULL;
	write(1, "ra\n", 3);
}

//rb - rotate b - Shift all elements of a by 1 - first becomes last
void	ft_rb(t_node **stack_b)
{
	t_node	*last_node;
	t_node	*new_second;

	last_node = *stack_b;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	new_second = *stack_b;
	*stack_b = (*stack_b)->next;
	last_node->next = new_second;
	new_second->next = NULL;
	write(1, "rb\n", 3);
}

//rr - rotate a and b at the same time
void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_node_a;
	t_node	*new_second_a;
	t_node	*last_node_b;
	t_node	*new_second_b;

	last_node_a = *stack_a;
	while (last_node_a->next != NULL)
	{
		last_node_a = last_node_a->next;
	}
	new_second_a = *stack_a;
	*stack_a = (*stack_a)->next;
	last_node_a->next = new_second_a;
	new_second_a->next = NULL;
	last_node_b = *stack_b;
	while (last_node_b->next != NULL)
	{
		last_node_b = last_node_b->next;
	}
	new_second_b = *stack_b;
	*stack_b = (*stack_b)->next;
	last_node_b->next = new_second_b;
	new_second_b->next = NULL;
	write(1, "rr\n", 3);
}
