/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:04 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/23 19:33:44 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Work with lists: First sort lists
//start sort with 3

long	is_stack_sorted(t_list *stack_a)
{
	long next_node;
	while (stack_a->next)
	{
		next_node = (long)stack_a->content;
		stack_a = stack_a->next;
		if ((long)stack_a->content <= next_node)
			return 0;
	}
	return 1;
}

//if it is sorted dont print anything

void	error_exit(char *file)
{
	ft_printf("Error\n%s\n", file);
	exit(EXIT_FAILURE);
}

void	sort_three(t_list **stack_a)
{
	long max;

	max = ft_lst_max_int(*stack_a);

	while(!is_stack_sorted(*stack_a))
	{
		if((long)(*stack_a)->content == max)
			ra_rb(stack_a, "ra");
		else
			sa_sb(stack_a, "sa");
	}	
}

// sort between 4 and 5

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	while(ft_lstsize(*stack_a) > 3)
	{
		long mid = ft_lstsize(*stack_a) / 2;
		long i_min = ft_i_min(*stack_a);
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

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	int	lst_size = ft_lstsize(stack_a) / 5;


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
	t_list *stack_a;
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