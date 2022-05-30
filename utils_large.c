/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:31 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/30 15:15:10 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_a(t_list **stack_a, t_list **stack_b)
{
	int	max;

	max = 0;
	while (ft_lstsize(*stack_b) != 0)
	{
		max = ft_i_max(*stack_b);
		if (max == 0)
			pa_pb(stack_b, stack_a, "pa");
		else if (max >= ft_lstsize(*stack_b) / 2)
			rra_rrb(stack_b, "rrb");
		else if (max < ft_lstsize(*stack_b) / 2)
			ra_rb(stack_b, "rb");
	}
}

void	chunk_to_b(t_list **stack_a, t_list *chunk, int start, int size)
{
	int		hold_first;
	int		hold_second;

	hold_first = 0;
	hold_second = 0;
	hold_second = scan_bottom(*stack_a, chunk, start, size);
	hold_first = scan_top(*stack_a, chunk, start, size);
	if (hold_first <= hold_second)
	{
		while (hold_first > 0)
		{
			ra_rb(stack_a, "ra");
			hold_first--;
		}
	}
	else if (hold_first > hold_second)
	{
		while (hold_second >= 0)
		{
			rra_rrb(stack_a, "rra");
			hold_second--;
		}
	}
}

t_list	*chunk_number(t_list *chunk, int start)
{
	int	bp;

	bp = 0;
	while (bp < start)
	{
		if (chunk->next != NULL)
			chunk = chunk->next;
		bp++;
	}
	return (chunk);
}

int	scan_top(t_list *stack_a, t_list *chunk, int start, int size)
{
	t_list	*tmp;
	int		i;
	int		s;

	chunk = chunk_number(chunk, start);
	i = 0;
	while (stack_a->next != NULL)
	{
		tmp = chunk;
		s = start;
		while (s < size)
		{
			if (tmp->content == stack_a->content)
				return (i);
			tmp = tmp->next;
			s++;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (0);
}

int	scan_bottom(t_list *stack_a, t_list *chunk, int start, int size)
{
	t_list	*reverse_dup;
	int		i;

	i = 0;
	reverse_dup = reverse_dup_stack(stack_a);
	i = scan_top(reverse_dup, chunk, start, size);
	return (i);
}
