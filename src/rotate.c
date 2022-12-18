/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:22:34 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 20:19:34 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(int *stack, int stack_size)
{
	int	temp;
	int	i;

	if (stack_size < 2)
		return ;
	i = 0;
	temp = stack[0];
	while (i < stack_size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = temp;
}

void	ra(t_ps *ps, int print)
{
	if (ps->size_a < 2)
		return ;
	rotate(ps->a, ps->size_a);
	if (print)
		ft_putendl_fd("ra", 1);
	ps->operations++;
}

void	rb(t_ps *ps, int print)
{
	if (ps->size_b < 2)
		return ;
	rotate(ps->b, ps->size_b);
	if (print)
		ft_putendl_fd("rb", 1);
	ps->operations++;
}

void	rr(t_ps *ps, int print)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return ;
	rotate(ps->a, ps->size_a);
	rotate(ps->b, ps->size_b);
	if (print)
		ft_putendl_fd("rr", 1);
	ps->operations++;
}
