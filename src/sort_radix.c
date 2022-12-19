/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:45:40 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 19:24:44 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_radix(t_ps *ps, int size, int print)
{
	int	i;
	int	j;

	j = 0;
	while (!is_finished(ps))
	{
		i = 0;
		while (i < size)
		{
			if (((ps->a[0] >> j) & 1) == 0)
				pb(ps, print);
			else
				ra(ps, print);
			i++;
		}
		while (ps->size_b)
			pa(ps, print);
		j++;
	}
}
