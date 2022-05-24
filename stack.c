/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:44:21 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/24 13:31:40 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_max(long n)
// {
// 	if (n > 2147483647 || n < -2147483648)
// 		return (0);
// 	return (1);
// }

void	get_stack(int len, char *av[], t_list **stack_a)
{
	t_list	*node;
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		tmp = ft_atoi(av[i]);
		// if (!is_max(tmp))
		// 	exit(EXIT_FAILURE);
		node = ft_lstnew((long *)tmp);
		if (!node)
			error_exit("Node creation failed!");
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (is_duplicate(*stack_a))
		error_exit("No duplicate numbers!");
}

long	is_stack_sorted(t_list *stack_a)
{
	long	next_node;

	while (stack_a->next)
	{
		next_node = (long)stack_a->content;
		stack_a = stack_a->next;
		if ((long)stack_a->content <= next_node)
			return (0);
	}
	return (1);
}

void	error_exit(char *file)
{
	ft_printf("Error\n%s\n", file);
	exit(EXIT_FAILURE);
}
