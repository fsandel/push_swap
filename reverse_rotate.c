/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:29:42 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:45 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int stack_size)
{
	int	temp;
	int	i;

	if (stack_size < 2)
		return ;
	i = 0;
	temp = stack[stack_size - 1];
	while (stack_size--)
	{
		stack[stack_size] = stack[stack_size - 1];
		i++;
	}
	stack[0] = temp;
}

void	rra(t_ps *ps)
{
	reverse_rotate(ps->a, ps->size_a);
	ft_putendl_fd("rra", 2);
	ps->operations++;
}

void	rrb(t_ps *ps)
{
	reverse_rotate(ps->b, ps->size_b);
	ft_putendl_fd("rrb", 2);
	ps->operations++;
}

void	rrr(t_ps *ps)
{
	reverse_rotate(ps->a, ps->size_a);
	reverse_rotate(ps->b, ps->size_b);
	ft_putendl_fd("rrr", 2);
	ps->operations++;
}
