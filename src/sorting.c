/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 19:15:40 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	choose_sort(t_ps *ps)
{
	int	radix;
	int	chunk;

	reset_stacks(ps);
	sort_radix(ps, ps->size, 0);
	radix = ps->operations;
	reset_stacks(ps);
	sort_chunk(ps, ps->parts, ps->size, 0);
	chunk = ps->operations;
	reset_stacks(ps);
	if (chunk < radix)
		sort_chunk(ps, ps->parts, ps->size, 1);
	else
		sort_radix(ps, ps->size, 1);
}

void	sort(t_ps *ps)
{
	if (ps->size_a <= 5)
		return (sort_small(ps, 1));
	get_chunks(ps, 20);
	choose_sort(ps);
}

void	sort_small(t_ps *ps, int print)
{
	if (is_finished(ps))
		return ;
	if (ps->size_a == 2)
		return (sort_2(ps, print));
	if (ps->size_a == 3)
		return (sort_3(ps, print));
	if (ps->size_a == 4)
		return (sort_4(ps, print));
	if (ps->size_a == 5)
		return (sort_5(ps, print));
}
