/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 18:06:49 by fsandel          ###   ########.fr       */
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
	if (ps->size_a == 2)
		sort_2(ps);
	if (ps->size_a == 3)
		sort_3(ps);
	return ;
}

void	sort_2(t_ps *ps)
{
	if (is_finished(ps))
		return ;
	ra(ps);
	return ;
}

void	sort_3(t_ps *ps)
{
	if (is_finished(ps))
		return ;
	if (ps->a[0] == ps->min_a)
	{
		sort_132(ps);
		return ;
	}
	if (ps->a[1] == ps->min_a)
	{
		if (ps->a[0] < ps->a[2])
		{
			ra(ps);
			sort_132(ps);
			return ;
		}
		else
		{
			ra(ps);
			return ;
		}
	}
	if (ps->a[2] == ps->min_a)
	{
		return ;
	}
}

