/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_ui.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:34:41 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:54:33 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_int(t_print	*args)
{
	int		a;
	int		len;
	char	*num;

	len = 0;
	a = va_arg(args->tab, int);
	if (a == 0)
		return (ft_print_zero(args));
	if (a < 0)
	{
		a = ft_check_sign(args, a);
	}
	if (a == -2147483648)
		num = ft_strdup("2147483648");
	else
		num = ft_itoa(a);
	update_args(args, ft_strlen(num));
	ft_right_num(args);
	while (num[len])
		args->total_length += write(1, &num[len++], 1);
	if (args->dash)
		ft_left_num(args);
	free (num);
}

void	ft_if_uint(t_print	*args)
{
	unsigned int	a;
	int				len;
	char			*num;
	int				i;

	i = 0;
	a = va_arg(args->tab, int);
	if (!a)
		return (ft_print_zero(args));
	num = ft_uitoa(a);
	if (!num)
		return ;
	len = ft_numlen_ui(a);
	update_args(args, len);
	ft_right_num(args);
	while (num[i])
	{
		args->total_length += write (1, &num[i++], 1);
	}
	ft_left_num(args);
	free (num);
}

void	ft_print_zero(t_print *args)
{
	args->is_zero = 1;
	if ((args->width && args->zero) || args->point)
	{
		ft_right_zero(args);
		return ;
	}
	update_args(args, 1);
	while (!args->dash && --args->width > 0)
		args->total_length += ft_putchar(' ');
	args->total_length += ft_putchar('0');
	while (args->dash && --args->width > 0)
		args->total_length += ft_putchar(' ');
}

void	ft_right_zero(t_print *args)
{
	if (args->width && (args->point || args->zero))
	{
		if (!args->precision)
		{
			while (args->zero && args->width-- > 0)
				args->total_length += ft_putchar('0');
			while (!args->zero && args->width-- > 0)
				args->total_length += ft_putchar(' ');
		}
		else
		{
			args->width -= args->precision;
			while (args->dash && args->precision-- > 0)
				args->total_length += ft_putchar('0');
			while (args->width-- > 0)
				args->total_length += ft_putchar(' ');
			while (!args->dash && args->precision-- > 0)
				args->total_length += ft_putchar('0');
		}
	}
	else if (args->point)
		ft_zero_point(args);
}

void	ft_zero_point(t_print *args)
{
	if (args->precision < 0)
		args->total_length += ft_putchar('0');
	while (!args->width && args->precision-- > 0)
		args->total_length += ft_putchar('0');
}
