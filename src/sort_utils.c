/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:56:00 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 20:27:16 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_finished(t_ps *ps)
{
	int	i;

	if (ps->size_a < 2)
		return (1);
	i = 1;
	while (i < ps->size_a)
	{
		if (ps->a[i - 1] > ps->a[i])
			return (0);
		i++;
	}
	return (1);
}


void	b_max_to_top(t_ps *ps, int print)
{
	int	i;
	int	direction;

	i = 0;
	while (ps->b[i] != ps->max_b)
		i++;
	while (ps->b[0] != ps->max_b)
	{
		if (i > ps->size_b / 2)
			rrb(ps, print);
		else
			rb(ps, print);
	}
}

void	a_min_to_top(t_ps *ps, int print)
{
	int	i;

	i = 0;
	while (ps->a[i] != ps->min_a)
		i++;
	while (ps->a[0] != ps->min_a)
	{
		if (i > ps->size_a / 2)
			rra(ps, print);
		else
			ra(ps, print);
	}
}