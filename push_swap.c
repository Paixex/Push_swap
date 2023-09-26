/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:13:27 by digil-pa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/25 22:58:40 by digil-pa         ###   ########.fr       */
=======
/*   Updated: 2023/09/25 14:08:30 by digil-pa         ###   ########.fr       */
>>>>>>> d9b33a9275aab92bda6a6b8298699b0b7b0da12a
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

void	print_stack(t_node *head)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = head;
<<<<<<< HEAD
	printf("STACK:\n");
	while (temp->next != NULL)
	{
		printf("%i\n", i);
		printf("%i\n", temp->number);
		temp = temp->next;
		i++;
	}
	printf("%i\n", temp->number);
=======
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
>>>>>>> d9b33a9275aab92bda6a6b8298699b0b7b0da12a
	return ;
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
