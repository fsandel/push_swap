/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:45:40 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 20:31:13 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(t_ps *ps)
{
	int	i;
	int	j;
	int	size;

	size = ps->size_a;
	j = 0;
	while (!is_finished(ps))
	{
		i = 0;
		while (i < size)
		{
			if (((ps->a[0]>>j)&1) == 0)
				pb(ps);
			else
				ra(ps);
			i++;
		}
		while (ps->size_b)
			pa(ps);
		j++;
	}
}
