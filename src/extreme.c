/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extreme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:34:25 by florian           #+#    #+#             */
/*   Updated: 2022/12/19 18:57:48 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_extreme(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->size_a)
	{
		if (ps->max_a < ps->a[i])
			ps->max_a = ps->a[i];
		if (ps->min_a > ps->a[i])
			ps->min_a = ps->a[i];
		i++;
	}
	i = 0;
	while (i < ps->size_b)
	{
		if (ps->max_b < ps->b[i])
			ps->max_b = ps->b[i];
		if (ps->min_b > ps->b[i])
			ps->min_b = ps->b[i];
		i++;
	}
}

int	get_maximum(int *stack, int stack_size)
{
	int	max;
	int	i;

	max = stack[0];
	i = 0;
	while (i < stack_size)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

int	get_minimum(int *stack, int stack_size)
{
	int	min;
	int	i;

	min = stack[0];
	i = 0;
	while (i < stack_size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}

void	set_maxima(t_ps *ps)
{
	ps->max_a = get_maximum(ps->a, ps->size_a);
	ps->min_a = get_minimum(ps->a, ps->size_a);
	ps->max_b = INT_MIN;
	ps->min_b = INT_MAX;
}
