/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 21:14:14 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_ps *ps)
{
	if (ps->size_a <= 5)
		sort_small(ps);
	return ;
}

void	reset_stacks(t_ps *ps)
{
	ft_memcpy(ps->a, ps->a_copy, ps->size);
	ft_memset(ps->b, 0, ps->size);
	ps->size_a = ps->size;
	ps->size_b = 0;
	ps->operations = 0;
	ps->max_a = ps->size - 1;
	ps->min_a = 0;
	ps->max_b = INT_MIN;
	ps->min_b = INT_MAX;
}

void	sort_small(t_ps *ps)
{
	if (is_finished(ps))
		return ;
	if (ps->size_a == 2)
		return (sort_2(ps, 1));
	if (ps->size_a == 3)
		return (sort_3(ps, 1));
	if (ps->size_a == 4)
		return (sort_4(ps, 1));
	if (ps->size_a == 5)
		return (sort_5(ps, 1));
}