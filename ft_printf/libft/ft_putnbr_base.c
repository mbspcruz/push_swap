/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:36:34 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 18:38:33 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	baselen;
	int				numlen;

	numlen = 1;
	baselen = ft_strlen(base);
	if (n == 0)
	{
		ft_putchar('0');
		return (numlen);
	}
	if (n >= baselen)
	{
		numlen += ft_putnbr_base(n / baselen, base);
		write(1, &base[n % baselen], 1);
	}
	else if (n < baselen)
		write(1, &base[n], 1);
	return (numlen);
}
