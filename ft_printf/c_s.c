/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:32:53 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:48:26 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_char(t_print *args)
{
	char	a;

	a = va_arg(args->tab, int);
	if (args->width && !args->dash)
		ft_right_alpha(args, 0);
	args->total_length += ft_putchar(a);
	if (args->width && args->dash)
		ft_left_alpha(args, 0);
}

void	ft_if_percent(t_print *args)
{
	while (--args->width > 0 && args->zero && !args->dash)
		args->total_length += ft_putchar('0');
	while (--args->width > 0 && !args->dash)
		args->total_length += ft_putchar(' ');
	args->total_length += ft_putchar('%');
	while (--args->width > 0 && args->dash)
		args->total_length += ft_putchar(' ');
}

void	ft_if_str(t_print *args)
{
	char	*a;
	int		len;
	int		i;

	i = 0;
	len = 0;
	a = va_arg(args->tab, char *);
	if (!a)
		a = "(null)";
	if (a && args->point == 1 && args->precision == 0)
		return (print_blank(args));
	len = update_args_s(args, a, len);
	if (args->width > len && !args->dash)
		ft_right_alpha(args, len);
	if (args->precision > 0)
		while (a[i] && args->precision--)
			args->total_length += write(1, &a[i++], 1);
	else
		while (a[i])
			args->total_length += write(1, &a[i++], 1);
	if (args->width && args->dash && a)
		ft_left_alpha(args, len);
}

void	print_blank(t_print *args)
{
	update_args_s(args, NULL, 0);
	while (args->width--)
		args->total_length += ft_putchar(' ');
}
