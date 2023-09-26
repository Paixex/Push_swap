/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:40:56 by digil-pa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/25 21:46:18 by digil-pa         ###   ########.fr       */
=======
/*   Updated: 2023/09/25 14:15:38 by digil-pa         ###   ########.fr       */
>>>>>>> d9b33a9275aab92bda6a6b8298699b0b7b0da12a
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_ok(t_node **stack)
{
	t_node	*temp;

	temp = (*stack);
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	check_for_rep(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		k = i + 1;
		while (k < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[k]))
				return (FALSE);
			k++;
		}
		i++;
	}
	return (TRUE);
}

int	check_input(int ac, char **av)
{
	if (digit_checker(ac, av) == FALSE)
		return (FALSE);
	if (check_for_rep(ac, av) == FALSE)
		return (FALSE);
	else if (check_int_val(ac, av) == FALSE)
		return (FALSE);
	else if (signal_check(ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
