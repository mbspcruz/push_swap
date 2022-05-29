/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:48:33 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/28 17:40:53 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_digit(char **av)
{
	int	i;
	int	x;

	i = 1;
	while (av[i])
	{
		x = 0;
		if (av[i][x] == '-')
			x++;
		while (av[i][x])
		{
			if (!ft_isdigit(av[i][x]))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

long	ft_lst_min_int(t_list *stack)
{
	long	min;

	min = (long)stack->content;
	while (stack)
	{
		if ((long)stack->content < min)
			min = (long)stack->content;
		stack = stack->next;
	}
	return (min);
}

long	ft_lst_max_int(t_list *stack)
{
	long	max;

	max = (long)stack->content;
	while (stack)
	{
		if ((long)stack->content > max)
			max = (long)stack->content;
		stack = stack->next;
	}
	return (max);
}

long	ft_i_min(t_list *stack)
{
	long	min;
	long	i;
	t_list	*tmp;

	i = 0;
	min = (long)stack->content;
	tmp = stack;
	while (tmp)
	{
		if ((long)tmp->content < min)
			min = (long)tmp->content;
		tmp = tmp->next;
	}
	free(tmp);
	while ((long)stack->content != min)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

long	ft_i_max(t_list *stack)
{
	long	max;
	long	i;
	t_list	*tmp;

	i = 0;
	max = (long)stack->content;
	tmp = stack;
	while (tmp)
	{
		if ((long)tmp->content > max)
			max = (long)tmp->content;
		tmp = tmp->next;
	}
	free(tmp);
	while ((long)stack->content != max)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_list	*dup_stack(t_list *stack_a)
{
	t_list	*dup;
	t_list	*tmp;

	dup = 0;
	while(stack_a)
	{
		tmp = ft_lstnew(stack_a->content);
		if (!tmp)
			return (0);
		ft_lstadd_back(&dup, tmp);
		stack_a = stack_a->next;
	}
	return (dup);
}

t_list	*reverse_dup_stack(t_list *stack_a)
{
	t_list	*dup;
	t_list	*tmp;

	dup = 0;
	while(stack_a)
	{
		tmp = ft_lstnew(stack_a->content);
		if (!tmp)
			return (0);
		ft_lstadd_front(&dup, tmp);
		stack_a = stack_a->next;
	}
	return (dup);
}