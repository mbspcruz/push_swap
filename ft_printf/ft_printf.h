/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 22:36:11 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/16 23:59:22 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_print
{
	va_list	tab;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		percentage;
	int		sign;
	int		is_zero;
	int		total_length;
}	t_print;

t_print		*initialize_args(t_print	*args);
t_print		*reset_args(t_print	*args);
void		print_blank(t_print *args);
void		ft_check_width(t_print *args);
int			ft_check_sign(t_print *args, int i);
void		ft_check_precision(t_print *args);
int			ft_check_flag(char c);
void		update_args(t_print *args, int len);
void		ft_if_char(t_print *args);
void		print_null_p(t_print *args);
int			update_args_s(t_print *args, char *s, int len);
int			ft_eval_variable(t_print *args, const char *format, int i);
int			ft_eval_format(t_print	*args, const char *format, int i);
int			ft_printf(const char *format, ...);
void		ft_right_alpha(t_print	*args, int len);
void		ft_right_num(t_print *args);
void		ft_left_num(t_print *args);
void		ft_if_hex_lower(t_print *args);
void		ft_if_hex_upper(t_print *args);
void		ft_if_int(t_print	*args);
void		ft_if_uint(t_print	*args);
void		ft_left_alpha(t_print *args, int len);
void		ft_if_str(t_print *args);
void		ft_if_percent(t_print *args);
void		ft_if_ptr(t_print *args);
int			ft_eval_width(t_print *args, const char *format, int i);
int			ft_eval_precision(t_print *args, const char *format, int i);
int			ft_eval_dash(t_print *args, const char *format, int i);
int			ft_eval_zero(t_print *args, const char *format, int i);
void		ft_right_zero(t_print *args);
void		ft_zero_point(t_print *args);
void		ft_print_zero(t_print *args);
int			ft_check_sign(t_print *args, int i);
#endif
