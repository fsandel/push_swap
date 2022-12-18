/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:40:22 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 20:23:16 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(int *from, int size_from, int *to, int size_to)
{
	int	i;

	i = 0;
	while (size_to--)
	{
		to[size_to + 1] = to[size_to];
		i++;
	}
	to[0] = from[0];
	i = 0;
	while (i < size_from - 1)
	{
		from[i] = from[i + 1];
		i++;
	}
	from[i] = 0;
}

void	pa(t_ps *ps, int print)
{
	if (ps->size_b < 1)
		return ;
	push(ps->b, ps->size_b, ps->a, ps->size_a);
	ps->size_a++;
	ps->size_b--;
	if (ps->a[0] == ps->max_b)
		ps->max_b = get_maximum(ps->b, ps->size_b);
	if (ps->a[0] == ps->min_b)
		ps->min_b = get_minimum(ps->b, ps->size_b);
	if (ps->a[0] > ps->max_a)
		ps->max_a = ps->a[0];
	if (ps->a[0] < ps->min_a)
		ps->min_a = ps->a[0];
	if (print)
		ft_putendl_fd("pa", 1);
	ps->operations++;
}

void	pb(t_ps *ps, int print)
{
	if (ps->size_a < 1)
		return ;
	push(ps->a, ps->size_a, ps->b, ps->size_b);
	ps->size_a--;
	ps->size_b++;
	if (ps->b[0] == ps->max_a)
		ps->max_a = get_maximum(ps->a, ps->size_a);
	if (ps->b[0] == ps->min_a)
		ps->min_a = get_minimum(ps->a, ps->size_a);
	if (ps->b[0] > ps->max_b)
		ps->max_b = ps->b[0];
	if (ps->b[0] < ps->min_b)
		ps->min_b = ps->b[0];
	if (print)
		ft_putendl_fd("pb", 1);
	ps->operations++;
}
