/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:53:20 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/25 15:54:51 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(int a, int b)
{
	return(a > b);
}

void	lst_swap(t_list *b)
{
	void *data;

	data = b->content;
	b->content = b->next->content;
	b->next->content = data;
}


void	sort_chunk(t_list **dup, int (*cmp)(int, int))
{
	t_list *a;
	t_list *b; 

	a = *dup;
	while (a != NULL)
	{
		b = *dup;
		while(b->next != NULL)
		{
			if ((*cmp)((long)b->content, (long)b->next->content) > 0)
				lst_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}