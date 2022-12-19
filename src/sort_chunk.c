/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:30:12 by florian           #+#    #+#             */
/*   Updated: 2022/12/19 19:25:04 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_swap(t_ps *ps, int print);
static void	chunk_rotate(t_ps *ps, int print);

void	sort_chunk(t_ps *ps, int chunks, int size, int print)
{
	int	part;

	part = 1;
	while (ps->size_a > 3)
	{
		while (ps->min_a < size / chunks * part && ps->size_a)
		{
			while (ps->a[0] > size / chunks * part)
				chunk_rotate(ps, print);
			check_swap(ps, print);
			if (ps->a[0] < ps->b[0])
				rb(ps, print);
			pb(ps, print);
		}
		part += 1;
	}
	sort_small(ps, print);
	while (ps->size_b)
	{
		b_max_to_top(ps, print);
		pa(ps, print);
	}
}

static void	chunk_rotate(t_ps *ps, int print)
{
	if (ps->a[0] < ps->b[0])
		rr(ps, print);
	else
		ra(ps, print);
}

void	get_chunks(t_ps *ps, int max_chunks)
{
	int	chunks;
	int	min_operations;
	int	return_chunks;
	int	size;

	size = ps->size;
	chunks = 2;
	min_operations = 100000;
	return_chunks = chunks;
	while (chunks < max_chunks && ps->size > chunks)
	{
		reset_stacks(ps);
		sort_chunk(ps, chunks, size, 0);
		if (ps->operations < min_operations)
		{
			return_chunks = chunks;
			min_operations = ps->operations;
		}
		chunks++;
	}
	ps->parts = return_chunks;
}

static void	check_swap(t_ps *ps, int print)
{
	if (ps->size_b > 1 && ps->b[0] < ps->b[1])
		sb(ps, print);
}
