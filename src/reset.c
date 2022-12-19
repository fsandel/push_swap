/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:58:27 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 18:59:14 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_stacks(t_ps *ps)
{
	int	i;

	ps->size = ps->size_a;
	i = 0;
	while (i < ps->size_a)
	{
		ps->a_copy[i] = ps->a[i];
		i++;
	}
}

void	reset_stacks(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->size)
	{
		ps->a[i] = ps->a_copy[i];
		ps->b[i] = 0;
		i++;
	}
	ps->size_a = ps->size;
	ps->size_b = 0;
	ps->operations = 0;
	ps->max_a = ps->size - 1;
	ps->min_a = 0;
	ps->max_b = INT_MIN;
	ps->min_b = INT_MAX;
}
