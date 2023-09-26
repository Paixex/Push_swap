/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:11:48 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/25 22:44:59 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node **stack)
{
	t_node	*temp;
	t_node	*smallest;
	int		i;	

	temp = (*stack);
	smallest = (*stack);
	i = 0;
	while (temp)
	{
		if (smallest->number > temp->number)
			smallest = temp;
		temp = temp->next;
	}
	temp = (*stack);
	while (temp != smallest)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	put_on_top(t_node **stack, int i)
{
	t_node	**temp;

	temp = stack;
	if (i <= ft_lstsize(*temp) / 2)
	{
		while (i--)
			ft_ra(temp);
	}
	else
	{
		while (i++ < ft_lstsize((*temp)))
			ft_rra(temp);
	}
	return ;
}

void	sort_small_5(t_node **stack_a, t_node **stack_b)
{
	int	i;

	while (ft_lstsize(*stack_a) > 3)
	{
		i = find_min(stack_a);
		put_on_top(stack_a, i);
		push_b(stack_a, stack_b);
	}
	sort_small_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	return ;
}

long long	ft_atoi(const char *str)
{
	int			k;
	int			sinal;
	long long	num;

	sinal = 1;
	num = 0;
	k = 0;
	while ((str[k] >= 9 && str[k] <= 13) || str[k] == 32)
		k++;
	if ((str[k] == '+') || (str[k] == '-'))
	{
		if (str[k] == '-')
			sinal *= -1;
		k++;
	}
	while (str[k] >= '0' && str[k] <= '9')
	{
		num = (num * 10) + (str[k] - '0');
		k++;
	}
	return (sinal * num);
}
