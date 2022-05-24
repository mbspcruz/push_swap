/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:37:26 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:43:36 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_alpha(t_print	*args, int len)
{
	while (args->zero && args->width-- > len)
		args->total_length += ft_putchar('0');
	if (!args->zero && args->precision && args->precision < len)
	{
		while (args->width-- > args->precision)
			args->total_length += ft_putchar(' ');
	}
	else
	{
		while (!args->zero && args->width-- > len)
			args->total_length += ft_putchar(' ');
	}
}

void	ft_left_alpha(t_print *args, int len)
{
	while (args->zero && args->width-- > len)
		args->total_length += ft_putchar('0');
	while (args->width-- > len && !args->zero)
		args->total_length += ft_putchar(' ');
}

void	ft_right_num(t_print *args)
{
	if (args->sign && (args->zero || args-> dash
			|| (!args->width && !args->precision)))
	{
		args->total_length += ft_putchar('-');
		args->sign = 0;
	}
	if (!args->dash)
	{
		while (args->width-- > 0 && !args->zero)
			args->total_length += ft_putchar(' ');
		while (args->width-- > -1 && args->zero)
			args->total_length += ft_putchar('0');
		if (args->sign)
			args->total_length += ft_putchar('-');
	}
	while (args->precision-- > 0)
		args->total_length += ft_putchar('0');
}

void	ft_left_num(t_print *args)
{
	if (args->dash)
	{
		while (args->zero && args->precision-- > 0)
			args->total_length += ft_putchar('0');
		while (args->width-- > 0)
			args->total_length += ft_putchar(' ');
	}
}
