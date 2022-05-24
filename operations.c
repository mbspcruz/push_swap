/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:45:48 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/24 13:30:58 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **stack, char *op)
{
	t_list	*tmp;

	if (!stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	printf("%s\n", op);
}

void	pa_pb(t_list **stack_a, t_list **stack_b, char *op)
{
	t_list	*tmp;

	if (stack_a)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
	}
	printf("%s\n", op);
}

void	ra_rb(t_list **stack, char *op)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	tmp->next = 0;
	ft_lstadd_back(stack, tmp);
	printf("%s\n", op);
}

void	rra_rrb(t_list **stack, char *op)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(stack, last_node);
	printf("%s\n", op);
}
