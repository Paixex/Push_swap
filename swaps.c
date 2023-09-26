/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:16:39 by digil-pa          #+#    #+#             */
/*   Updated: 2023/07/01 15:02:19 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void	ft_sa(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	write(1, "sa\n", 3);
}

/*Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	ft_sb(t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	write(1, "sb\n", 3);
}

/*sa and sb at the same time*/
void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_a->next = (*stack_a)->next;
	(*stack_a)->next = temp_a;
	temp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_b->next = (*stack_b)->next;
	(*stack_b)->next = temp_b;
	write(1, "ss\n", 3);
}
