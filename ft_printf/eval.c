/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:27:00 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:35:02 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(t_print	*args, const char *format, int i)
{
	while (!(ft_isalpha(format[i]) || format[i] == '%'))
	{
		if (format[i] == '.')
			i = ft_eval_precision(args, format, i);
		if (format[i] == '-')
			i = ft_eval_dash(args, format, i);
		if (format[i] == '0')
			i = ft_eval_zero(args, format, i);
		if (ft_isdigit(format[i]))
			i = ft_eval_width(args, format, i);
		i++;
	}
	ft_eval_variable(args, format, i);
	return (i);
}

int	ft_eval_variable(t_print *args, const char *format, int i)
{
	if (format[i] == 'c')
		ft_if_char(args);
	else if (format[i] == 's')
		ft_if_str(args);
	else if (format[i] == 'p')
		ft_if_ptr(args);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_if_int(args);
	else if (format[i] == 'u')
		ft_if_uint(args);
	else if (format[i] == 'x')
		ft_if_hex_lower(args);
	else if (format[i] == 'X')
		ft_if_hex_upper(args);
	else if (format[i] == '%')
		ft_if_percent(args);
	reset_args(args);
	return (i);
}
