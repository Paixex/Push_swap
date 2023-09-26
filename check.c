/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:40:41 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/25 22:44:09 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int k)
{
	if (k >= '0' && k <= '9')
		return (1);
	else
		return (0);
}

int	signal_check(int ac, char **av)
{
	int	i;
	int	k;
	int	x;

	i = 1;
	k = 1;
	while (i < ac)
	{
		x = 0;
		if (av[k][x] == '-')
		{
			x += 1;
			if (!(av[k][x] >= '0' && av[k][x] <= '9'))
				return (FALSE);
		}
		i++;
		k++;
	}
	return (TRUE);
}

int	digit_checker(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '\0' || ft_isdigit(av[i][1]) == 0)
				return (FALSE);
			k = 2;
		}
		else
			k = 0;
		while (av[i][k] != '\0')
		{
			if (ft_isdigit(av[i][k]) == 0)
				return (FALSE);
			k++;
		}
		i++;
	}
	return (TRUE);
}

int	check_int_val(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > 2147483647)
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	sort(t_node **stack_a, t_node **stack_b, int ac)
{
	if (ac <= 4)
		sort_small_3(stack_a);
	else if (ac > 4 && ac <= 6)
		sort_small_5(stack_a, stack_b);
	else if (ac > 6 && ac <= 501)
		sort_big(stack_a, stack_b);
}
