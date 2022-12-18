/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:14:20 by florian           #+#    #+#             */
/*   Updated: 2022/12/18 20:29:46 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_3_perm(t_ps *ps, int print);
static void	sort_3_no_perm(t_ps *ps, int print);
static int	sort_3_finished(t_ps *ps);

void	sort_3(t_ps *ps, int print)
{
	if (sort_3_finished(ps))
		return ;
	sort_3_perm(ps, print);
	sort_3_no_perm(ps, print);	
}

static void	sort_3_perm(t_ps *ps, int print)
{
	if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2] && ps->a[2] > ps->a[0])
		{
			sa(ps, print);
			ra(ps, print);
			return ;
		}
	if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
	{
		sa(ps, print);
		rra(ps, print);
		return ;
	}
	if (ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2] && ps->a[2] > ps->a[0])
	{
		sa(ps, print);
		return ;
	}
}

static void	sort_3_no_perm(t_ps *ps, int print)
{
	if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
	{
		rra(ps, print);
		return ;
	}
	if (ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2] && ps->a[0] > ps->a[2])
	{
		ra(ps, print);
		return ;
	}
}

static int	sort_3_finished(t_ps *ps)
{
	if (ps->a[0] < ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] < ps->a[2])
		return (1);
	else
	return (0);
}