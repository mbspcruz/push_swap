/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   H_h_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:36:16 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:39:54 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_hex_upper(t_print *args)
{
	unsigned int	a;
	int				len;

	a = va_arg(args->tab, unsigned int);
	if (!a)
	{
		return (ft_print_zero(args));
	}
	len = ft_numlen_base(a, 16);
	update_args(args, len);
	ft_right_num(args);
	args->total_length += ft_putnbr_base(a, "0123456789ABCDEF");
	ft_left_num(args);
}

void	ft_if_hex_lower(t_print *args)
{
	unsigned int	a;
	int				len;

	a = va_arg(args->tab, unsigned int);
	if (!a)
	{
		return (ft_print_zero(args));
	}
	len = ft_numlen_base(a, 16);
	update_args(args, len);
	ft_right_num(args);
	args->total_length += ft_putnbr_base(a, "0123456789abcdef");
	ft_left_num(args);
}

void	ft_if_ptr(t_print *args)
{
	unsigned long long	a;
	int					len;

	len = 2;
	a = (unsigned long)va_arg(args->tab, void *);
	if (!a && args->point && args->precision > 0)
	{
		return (ft_print_zero(args));
	}
	if (!(!a && args->point))
		len += ft_numlen_base(a, 16);
	if (!args->precision || args->width > args->precision)
	{
		update_args(args, len);
		ft_right_num(args);
	}
	else
		args->precision = args->precision + 2 - len;
	args->total_length += ft_putstr("0x");
	while (args->precision-- > 0)
		args->total_length += ft_putchar('0');
	if (!(!a && args->point))
		args->total_length += ft_putnbr_base(a, "0123456789abcdef");
	ft_left_num(args);
}

void	print_null_p(t_print *args)
{
	if (args->width > args->precision)
	{
		while (args->width-- > (args->precision + 2))
			args->total_length += ft_putchar(' ');
	}
	args->total_length += ft_putstr("0x");
	while (args->precision-- > 0)
		args->total_length += ft_putchar('0');
}
