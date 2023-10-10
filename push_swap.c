/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:27 by digil-pa          #+#    #+#             */
/*   Updated: 2023/10/10 14:18:44 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*insert_stack_a(char **av)
{
	t_node		**stack_a;
	t_node		*temp;
	t_node		*head;
	int			i;
	int			number;

	i = 0;
	while (av[++i])
	{
		number = ft_atoi(av[i]);
		if (i == 1)
			head = ft_lstnew(number);
		else
		{
			temp = ft_lstnew(number);
			ft_lstadd_back(stack_a, temp);
		}
		stack_a = &head;
	}
	return (head);
}

void	ft_clean_lst(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free (*stack);
		*stack = temp;
	}
}

void	sort_all(t_node	**stack_a, t_node **stack_b)
{
	if (ft_lstsize((*stack_a)) > 5)
		sort_big(stack_a, stack_b);
	else
		sort_small_5(stack_a, stack_b);
	return ;
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_node	*head_a;
	t_node	*head_b;

	if (ac < 2)
		return (0);
	if (check_input(ac, av) == FALSE)
		exit(write(2, "Error\n", 6));
	head_a = insert_stack_a(av);
	head_b = NULL;
	stack_a = &head_a;
	stack_b = &head_b;
	if (check_if_ok(stack_a) == TRUE)
	{
		ft_clean_lst(stack_a);
		return (0);
	}
	if (ac > 2)
		sort(stack_a, stack_b, ac);
	ft_clean_lst(stack_a);
	ft_clean_lst(stack_b);
	return (0);
}

/*int main(int ac, char **av)  ORIGINAL
{
    t_node  **stack_a;
	t_node	**stack_b;
    t_node  *head_a;
	t_node 	*head_b;

    if (ac < 2)
		return (0);
	if (check_input(ac, av) == FALSE)
		exit(write(2, "Error\n", 6));
	head_a = insert_stack_a(av);
	head_b = NULL;
	stack_a = &head_a;
	stack_b = &head_b;
	if (check_if_ok(stack_a) == TRUE)
	{
		ft_clean_lst(stack_a);
		return (0);
	}
	print_stack((*stack_a), 'A');
	ft_clean_lst(stack_a);
	ft_clean_lst(stack_b);
	return (0);
}*/
