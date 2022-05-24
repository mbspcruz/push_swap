/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:22:52 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/17 00:05:01 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lsst;

	lsst = *lst;
	if (lst)
	{
		while (*lst)
		{
			lsst = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = lsst;
		}
	}
}
