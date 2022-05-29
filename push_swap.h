/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:38 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/28 17:32:38 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>

void		get_stack(int len, char *av[], t_list **stack_a);
void		pa_pb(t_list **stack_a, t_list **stack_b, char *op);
void		sa_sb(t_list **stack, char *op);
void		ra_rb(t_list **stack, char *op);
void		rra_rrb(t_list **stack, char *op);
int			is_it_digit(char **av);
int			is_duplicate(t_list *stack_a);
void		error_exit(char *file);
long		ft_lst_min_int(t_list *stack);
long		ft_lst_max_int(t_list *stack);
void		sort_three(t_list **stack_a);
void		sort_stack(t_list **stack_a, t_list **stack_b);
long		ft_i_min(t_list *stack);
void		sort_medium(t_list **stack_a, t_list **stack_b);
void		sort_large(t_list **stack_a, t_list **stack_b);
long		is_stack_sorted(t_list *stack_a);
void		sort_chunk(t_list **dup, int (*cmp)(int, int));
t_list		*dup_stack(t_list *stack_a);
int			cmp(int a, int b);
void		lst_swap(t_list *b);
t_list		*reverse_dup_stack(t_list *stack_a);
long	ft_i_max(t_list *stack);

#endif