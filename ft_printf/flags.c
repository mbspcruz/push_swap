/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:30:28 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:51:24 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_precision(t_print *args, const char *format, int i)
{
	int	res;

	res = 0;
	args->point = 1;
	if (ft_isalpha(format[i] || format[i] == '%'))
		ft_check_precision(args);
	while (format[i] == '0' || ft_check_flag(format[i]))
	{
		i++;
		ft_check_precision(args);
	}
	if (ft_isdigit(format[i]))
	{
		res = ft_atoi(&format[i]);
		i += ft_numlen(res);
	}
	args->precision = res;
	return (i);
}

int	ft_eval_dash(t_print *args, const char *format, int i)
{
	if (args->dash == 1)
	{
		while (format[i] == '0' || format[i] == '-')
			i++;
		return (i);
	}
	args->dash = 1;
	args->zero = 0;
	while (format[i] == '-')
		i++;
	return (i);
}

int	ft_eval_zero(t_print *args, const char *format, int i)
{
	args->zero = 1;
	while (format[i] == '0')
		i++;
	return (i);
}

int	ft_eval_width(t_print *args, const char *format, int i)
{
	int	res;

	res = 0;
	if (ft_isdigit(format[i]))
	{
		res = ft_atoi(&format[i]);
		i += ft_numlen(res);
	}
	args->width = res;
	return (i);
}
