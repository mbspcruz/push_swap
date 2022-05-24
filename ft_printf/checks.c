/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:31:47 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:48:54 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(t_print *args)
{
	if (args->width < 0)
	{
		args->width *= -1;
		args->dash = 1;
		args->zero = 0;
	}
}

int	ft_check_sign(t_print *args, int i)
{
	args->sign = 1;
	return (i * -1);
}

void	ft_check_precision(t_print *args)
{
	if (args->precision == 0 && args->zero == 1)
	{
		args->zero = 0;
		args->percentage = 1;
	}
	if (args->precision < 0)
	{
		args->precision = 0;
		args->point = 0;
	}
}

int	ft_check_flag(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}
