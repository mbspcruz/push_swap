/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:34:44 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/17 00:13:02 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return (count);
	}
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}
