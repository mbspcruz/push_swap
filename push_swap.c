/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:04 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/24 17:54:43 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
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

// sort between 4 and 5

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
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		pa_pb(stack_b, stack_a, "pa");
}

//sort > 5

void	sort_large(t_list **stack_a)
{
	t_list	*sorted_chunk;
	//int		begin_chunk;
	//int		len_chunk;
	int size;
	sorted_chunk = sort_chunk(stack_a);
	size = ft_lstsize(sorted_chunk);
	printf("%d\n", size);

}

int	*sort_chunk(t_list **stack_a)
{
	int	*tab;
	t_list	*chunk;

	chunk = *stack_a;
	while (chunk->next != 0)
	{
		if (chunk->content > chunk->next->content)
		{
			tab = (long)chunk->content;
			chunk->content = chunk->next->content;
			chunk->next->content = tab;
		}
		chunk = chunk->next;
	}
	return (chunk);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	long	lst_size;

	lst_size = ft_lstsize(*stack_a);
	if (lst_size <= 3)
		sort_three(stack_a);
	else if (lst_size <= 5 && lst_size >= 4)
		sort_medium(stack_a, stack_b);
	else
	 	sort_large(stack_a);
}

int	main(int ac, char *av[])
{	
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (!is_it_digit(av))
		error_exit("Only digits allowed!");
	if (ac <= 2)
		error_exit("At least two numbers must be given!");
	get_stack(ac - 1, av + 1, &stack_a);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
}
