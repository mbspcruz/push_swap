/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:25:38 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/30 17:42:13 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include    <limits.h>

void	sa_sb(t_list **stack, char *op);
void	pa_pb(t_list **stack_a, t_list **stack_b, char *op);
void	ra_rb(t_list **stack, char *op);
void	rra_rrb(t_list **stack, char *op);
void	sort_small(t_list **stack_a);
void	sort_medium(t_list **stack_a, t_list **stack_b);
void	sort_large(t_list **stack_a, t_list **stack_b, t_list *chunk);
void	sort_super_large(t_list **stack_a, t_list **stack_b, t_list *chunk);
int		is_max(int n);
void	get_stack(int len, char *av[], t_list **stack_a);
long	is_stack_sorted(t_list *stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	error_exit(int n, t_list **stack_a, t_list **stack_b);
void	sort_b_a(t_list **stack_a, t_list **stack_b);
void	chunk_to_b(t_list **stack_a, t_list *chunk, int start, int size);
t_list	*chunk_number(t_list *chunk, int start);
int		scan_top(t_list *stack_a, t_list *chunk, int start, int size);
int		scan_bottom(t_list *stack_a, t_list *chunk, int start, int size);
int		is_it_digit(char **av);
int		is_duplicate(t_list *stack_a);
long	ft_lst_min_int(t_list *stack);
long	ft_lst_max_int(t_list *stack);
long	ft_i_min(t_list *stack);
long	ft_i_max(t_list *stack);
t_list	*dup_stack(t_list *stack_a);
t_list	*reverse_dup_stack(t_list *stack_a);
int		cmp(int a, int b);
void	lst_swap(t_list *b);
void	sort_chunk(t_list **dup, int (*cmp)(int, int));

#endif