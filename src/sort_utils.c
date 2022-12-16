/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:56:00 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 14:32:32 by fsandel          ###   ########.fr       */
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

int	is_sorted(int *stack, int stack_size)
{
	int	i;

	if (stack_size < 2)
		return (0);
	i = 1;
	while (i < stack_size)
	{
		if (stack[i - 1] > stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_finished(t_ps *ps)
{
	if (is_sorted(ps->a, ps->size_a) && (ps->size_b == 0))
		return (1);
	else
		return (0);
}
