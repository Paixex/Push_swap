/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:45:32 by digil-pa          #+#    #+#             */
/*   Updated: 2023/06/01 19:46:20 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_a;
	temp = ft_lstlast(temp);
	temp->next = *stack_a;
	new_last = *stack_a;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_a = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_b;
	temp = ft_lstlast(temp);
	temp->next = *stack_b;
	new_last = *stack_b;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_b = temp;
	write(1, "rrb\n", 4);
}

//rra and rrb at the same time
void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_a;
	temp = ft_lstlast(temp);
	temp->next = *stack_a;
	new_last = *stack_a;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_a = temp;
	temp = *stack_b;
	temp = ft_lstlast(temp);
	temp->next = *stack_b;
	new_last = *stack_b;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_b = temp;
	write(1, "rrr\n", 4);
}
