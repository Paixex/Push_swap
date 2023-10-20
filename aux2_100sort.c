/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2_100sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:04:23 by digil-pa          #+#    #+#             */
/*   Updated: 2023/10/20 13:08:15 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mv_cost(int n, t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;

	i = cost_a(stack_a, n);
	if (n > find_max_big(stack_b))
		j = 0;
	else if (n < find_min_big(stack_b))
		j = 0;
	else
		j = (2 * cost_b(stack_b, n, 0, find_max_big(stack_b))) + 1;
	return (i + j + 1);
}

void	mv_to_b(int n, t_node **stack_a, t_node **stack_b)
{
	put_nr_top_a(stack_a, n);
	push_b(stack_a, stack_b);
}

int	cost_a(t_node **stack_a, int n)
{
	t_node	*temp;
	int		i;

	temp = (*stack_a);
	i = 0;
	while (temp->next != NULL)
	{
		if (temp->number == n)
			break ;
		i++;
		temp = temp->next;
	}
	if (i > (ft_lstsize((*stack_a)) / 2))
		return (ft_lstsize((*stack_a)) - i);
	return (i);
}

int	cost_b(t_node **stack_b, int n, int res, int max)
{
	t_node	*temp;
	int		i;
	int		min;

	temp = (*stack_b);
	i = 0;
	max = find_max_big(stack_b);
	min = find_min_big(stack_b);
	if (n > max)
		return (0);
	else if (n < min)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->number == find_n_before(stack_b, n))
			break ;
		i++;
		temp = temp->next;
	}
	if (temp->number == find_n_before(stack_b, n))
		i++;
	res = ft_lstsize((*stack_b)) - i;
	if (i > (ft_lstsize((*stack_b)) / 2))
		return (res);
	return (i);
}

/*int	cost_b(t_node **stack_b, int n)
{
	t_node	*temp;
	int		i;
	int		max;
	int		min;

	temp = (*stack_b);
	i = 0;
	max = find_max_big(stack_b);
	min = find_min_big(stack_b);
	if (n > max)
		return (0);
	else if (n < min)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->number == find_n_before(stack_b, n))
			break;
		i++;
		temp = temp->next;
	}
	if (temp->number == find_n_before(stack_b, n))
		i++;
	if (i > (ft_lstsize((*stack_b)) / 2))
		return (ft_lstsize((*stack_b) - i));
	return (i);
}*/
