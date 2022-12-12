/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:22:34 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:58 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_ps *ps)
{
	rotate(ps->a, ps->size_a);
	ft_putendl_fd("ra", 2);
	ps->operations++;
}

void	rb(t_ps *ps)
{
	rotate(ps->b, ps->size_b);
	ft_putendl_fd("rb", 2);
	ps->operations++;
}

void	rr(t_ps *ps)
{
	rotate(ps->a, ps->size_a);
	rotate(ps->b, ps->size_b);
	ft_putendl_fd("rr", 2);
	ps->operations++;
}
