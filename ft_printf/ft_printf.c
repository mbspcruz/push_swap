/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:40:51 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:56:28 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*initialize_args(t_print	*args)
{
	args->width = 0;
	args->precision = 0;
	args->zero = 0;
	args->point = 0;
	args->dash = 0;
	args->percentage = 0;
	args->sign = 0;
	args->is_zero = 0;
	args->total_length = 0;
	return (args);
}

t_print	*reset_args(t_print	*args)
{
	args->width = 0;
	args->precision = 0;
	args->zero = 0;
	args->point = 0;
	args->dash = 0;
	args->percentage = 0;
	args->sign = 0;
	args->is_zero = 0;
	return (args);
}

void	update_args(t_print *args, int len)
{
	if (args->sign)
	{
		if (args->width)
			args->width -= 1;
	}
	if (args->precision > 0)
		args->zero = 0;
	if (args->width && args->width >= args->precision)
	{
		if (args->precision > len)
			args->precision -= len;
		else
			args->precision = 0;
		if (!args->is_zero)
			args->width = args->width - args->precision - len;
	}
	else if (args->precision > args->width)
	{
		args->width = 0;
		args->precision -= len;
	}
}

int	update_args_s(t_print *args, char *s, int len)
{
	if (s)
		len = ft_strlen(s);
	if (args->precision > 0 && len > args->precision)
		len = args->precision;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_print	*args;
	int		i;
	int		res;

	if (!format)
		return (0);
	args = (t_print *)malloc(sizeof(t_print));
	if (!args)
		return (-1);
	initialize_args(args);
	va_start(args->tab, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(args, format, i + 1);
		else
			res += ft_putchar(format[i]);
		i++;
	}
	res += args->total_length;
	va_end(args->tab);
	free(args);
	return (res);
}
