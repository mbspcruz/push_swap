/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:40:54 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/17 00:10:22 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !f)
		return (0);
	new = 0;
	first = ft_lstnew(f(lst->content));
	while (lst)
	{
		if (!(first))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, first);
		lst = lst->next;
	}
	return (new);
}
