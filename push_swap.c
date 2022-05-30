/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:04 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/30 18:18:53 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **stack_a)
{
	long	max;

	max = ft_lst_max_int(*stack_a);
	while (!is_stack_sorted(*stack_a))
	{
		if ((long)(*stack_a)->content == max)
			ra_rb(stack_a, "ra");
		else
			sa_sb(stack_a, "sa");
	}	
}

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	long	mid;
	long	i_min;

	while (ft_lstsize(*stack_a) > 3)
	{
		mid = ft_lstsize(*stack_a) / 2;
		i_min = ft_i_min(*stack_a);
		if (ft_i_min(*stack_a) == 0)
			pa_pb(stack_a, stack_b, "pb");
		else if (mid > i_min)
			ra_rb(stack_a, "ra");
		else if (mid <= i_min)
			rra_rrb(stack_a, "rra");
	}
	sort_small(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		pa_pb(stack_b, stack_a, "pa");
}

void	sort_large(t_list **stack_a, t_list **stack_b, t_list *chunk)
{
	int		size;
	int		bp;
	int		start;
	int		k;
	int		i;

	i = 0;
	size = ft_lstsize(*stack_a) / 5;
	bp = size;
	start = 0;
	k = 0;
	while (i < 5)
	{
		while (k < size)
		{
			chunk_to_b(stack_a, chunk, start, size);
			pa_pb(stack_a, stack_b, "pb");
			k++;
		}	
		i++;
		start += bp;
		size += bp;
	}
	sort_b_a(stack_a, stack_b);
	free(chunk);
}

void	sort_super_large(t_list **stack_a, t_list **stack_b, t_list *chunk)
{
	int		size;
	int		bp;
	int		start;
	int		k;
	int		i;

	i = 0;
	size = ft_lstsize(*stack_a) / 10;
	bp = size;
	start = 0;
	k = 0;
	while (i < 10)
	{
		while (k < size)
		{
			chunk_to_b(stack_a, chunk, start, size);
			pa_pb(stack_a, stack_b, "pb");
			k++;
		}	
		i++;
		start += bp;
		size += bp;
	}
	sort_b_a(stack_a, stack_b);
	free(chunk);
}

int	main(int ac, char *av[])
{	
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (!is_it_digit(av))
		error_exit(1, &stack_a, &stack_b);
	if (ac <= 1)
		error_exit(1, &stack_a, &stack_b);
	get_stack(ac - 1, av + 1, &stack_a);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	error_exit(0, &stack_a, &stack_b);
}
