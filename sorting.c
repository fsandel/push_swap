/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/15 10:12:55 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_132(t_ps *ps)
{
		pb(ps);
		sa(ps);
		pa(ps);
}

void	sort(t_ps *ps)
{
	algorithm(ps);
	return ;
}

void	sort_2(t_ps *ps)
{
	if (ps->a[0] < ps->a[1])
		return ;
	ra(ps);
	return ;
}

void	sort_3(t_ps *ps)
{
	return ;	
}

void	algorithm(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->size_a)
	{
		while (ps->a[0] != ps->min_a)
			ra(ps);
		pb(ps);
	}
	while(ps->size_b)
		pa(ps);
}

void	new_algorithm(t_ps *ps)
{
	int	i;
	int	part;
	int	cutoff;

	i = 0;
	part = 1;
	while (ps->size_a)
	{
		if (ps->a[0] > ps->size_a * part / ps->parts)
			ra(ps);
		if (ps->a[0] <= ps->size_a * part / ps->parts)
			pb(ps);
		if (ps->min_a > ps->size_a * part / ps->parts)
			part++;
	}
	while (ps->size_b)
	{
		while (ps->size_b && ps->b[0] != ps->max_b)
			rrb(ps);
		pa(ps);
	}
}
