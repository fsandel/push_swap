/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:30:12 by florian           #+#    #+#             */
/*   Updated: 2022/12/18 21:19:40 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	choose_up_down(t_ps *ps, int size, int part);
static int	alternating_rb(t_ps *ps, int j, int print);

int	get_chunks(t_ps *ps, int max_chunks)
{
	int	chunks;
	int	min_operations;
	int	return_chunks;

	chunks = 2;
	min_operations = 100000;
	return_chunks = 2;
	while (chunks <= max_chunks)
	{
		reset_stacks(ps);
		if (ps->operations < min_operations)
		{
			return_chunks = chunks;
			min_operations = ps->operations;
		}
		chunks++;
	}
	return (return_chunks);
}

void	sort_chunk(t_ps *ps, int chunks, int size, int print)
{
	int	part;

	part = 1;
	while (ps->size_a)
	{
		while (ps->min_a < size / chunks * part && ps->size_a)
		{
			while (ps->a[0] > size / chunks * part && ps->size_a > 1)
				ra(ps, print);
			pb(ps, print);
		}
		part+=1;
	}
	while (ps->size_b)
	{
		b_max_to_top(ps, print);
		pa(ps, print);
	}
}

static int	choose_up_down(t_ps *ps, int size, int part)
{
	int	from_top = 0;;
	int	from_bottom = 0;
	int	i;
	
	i = 0;
	while (i < size / ps->parts)
	{
		if (ps->a[i] < size / ps->parts * part)
			from_top++;
		i++;
	}
	i = ps->size_a - 1;
	while (i > ps->size_a - size / ps->parts)
	{
		if (ps->a[i] < size / ps->parts * part)
			from_top--;
		i--;
	}
	return (from_top - from_bottom);
}

static int	alternating_rb(t_ps *ps, int j, int print)
{
	if (j == 0)
		j++;
	else
		j = 0;
	if (j == 0)
		rb(ps, print);
	return (j);
}