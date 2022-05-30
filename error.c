/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:05:23 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/30 17:53:20 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	ft_del(void *data)
{
	(void)data;
}

void	error_exit(int n, t_list **stack_a, t_list **stack_b)
{
	if (n == 0)
	{
		ft_lstclear(stack_a, ft_del);
		ft_lstclear(stack_b, ft_del);
		exit(EXIT_SUCCESS);
	}
	else if (n == 1)
	{
		ft_lstclear(stack_a, ft_del);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}