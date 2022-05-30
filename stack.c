/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:44:21 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/30 18:54:09 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(int len, char *av[], t_list **stack_a)
{
	t_list		*node;
	long long	tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		tmp = ft_atoi(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_exit(1, stack_a, 0);
		node = ft_lstnew((long *)tmp);
		if (!node)
			error_exit(1, stack_a, 0);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (is_duplicate(*stack_a))
		error_exit(1, stack_a, 0);
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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		lst_size;
	t_list	*chunk;

	lst_size = ft_lstsize(*stack_a);
	if (lst_size <= 3)
		sort_small(stack_a);
	else if (lst_size <= 25)
		sort_medium(stack_a, stack_b);
	else if (lst_size <= 100)
	{
		chunk = dup_stack(*stack_a);
		sort_chunk(&chunk, cmp);
		sort_large(stack_a, stack_b, chunk);
	}
	else if (lst_size <= 500)
	{
		chunk = dup_stack(*stack_a);
		sort_chunk(&chunk, cmp);
		sort_super_large(stack_a, stack_b, chunk);
	}
}

t_list	*dup_stack(t_list *stack_a)
{
	t_list	*dup;
	t_list	*tmp;

	dup = 0;
	while (stack_a)
	{
		tmp = ft_lstnew(stack_a->content);
		if (!tmp)
			return (0);
		ft_lstadd_back(&dup, tmp);
		stack_a = stack_a->next;
	}
	return (dup);
}

