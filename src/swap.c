/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:22:37 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/20 15:49:37 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(int *stack, int size_stack)
{
	int	temp;

	if (size_stack < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa(t_ps *ps, int print)
{
	if (ps->size_a < 2)
		return ;
	swap(ps->a, ps->size_a);
	if (print)
		ft_putendl_fd("sa", 1);
	ps->operations++;
}

void	sb(t_ps *ps, int print)
{
	if (ps->size_b < 2)
		return ;
	swap(ps->b, ps->size_b);
	if (print)
		ft_putendl_fd("sb", 1);
	ps->operations++;
}

void	ss(t_ps *ps, int print)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return ;
	swap(ps->a, ps->size_a);
	swap(ps->b, ps->size_b);
	if (print)
		ft_putendl_fd("ss", 1);
	ps->operations++;
}
