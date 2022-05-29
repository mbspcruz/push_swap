/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:04 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/29 15:16:01 by mda-cruz         ###   ########.fr       */
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
//Run stack a from top to bottom and check if there's a number in stack a from chunk, check index
//Run stack bottom to top and check if theres numer in chunck, check index
//if i_check_top < i_check_bottom ra
//if i_check_top > i_check_bottom rra
//pb
//organize b
//Do the same until all chunk is in b

int	scan_top(t_list *stack_a, t_list *chunk, int start, int size)
{
	t_list *tmp;
	int i;
	int s;

	i = 0;
	while(stack_a)
	{
		tmp = chunk;
		s = start;
		while(s < size)
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

int	scan_bottom(t_list **stack_a, t_list *chunk, int start, int size)
{
	t_list *reverse_dup;
	int i;
	
	reverse_dup = reverse_dup_stack(*stack_a);
	i = scan_top(reverse_dup, chunk, start, size);
	return (i);
}
	

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	t_list	*chunk;
	int		size;
	int		hold_first = 0;
	int		hold_second = 0;
	int bp;
	int start = 0;
	int k = 0;
	long max = 0;
	int i = 0;
	int min;
	
	chunk = dup_stack(*stack_a);
	sort_chunk(&chunk, cmp);
	size = ft_lstsize(chunk) / 10;
	bp = size;
	start = 0;

	while(i < 10)
	{
		while (k < size)
		{
			hold_second = scan_bottom(stack_a, chunk, start, size);
			hold_first = scan_top(*stack_a, chunk, start, size);
			if (hold_first <= hold_second)
			{
				while(hold_first > 0)
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
			k++;
		}
		while(ft_lstsize(*stack_b) != size)
		{
			min = ft_i_min(*stack_a);
			if (min == 0)
				pa_pb(stack_a, stack_b, "pb");
			else if(min == 1)
				sa_sb(stack_a, "sa");
			else if(min >= ft_lstsize(*stack_a) / 2)
				rra_rrb(stack_a, "rra");
			else if (max < ft_lstsize(*stack_a) / 2)
				ra_rb(stack_a, "ra");
		}
		start += bp;
		size += bp;
		i++;
	}
		while(ft_lstsize(*stack_b) > 0)
		{
			pa_pb(stack_b, stack_a, "pa");
		}		
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
	 	sort_large(stack_a, stack_b);
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
	//printf("%ld", (long)stack_a->content);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
}
