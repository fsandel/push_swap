/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:30 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 19:27:17 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_min_to_top(t_ps *ps);
void	b_max_to_top(t_ps *ps);

static void sort_132(t_ps *ps)
{
		pb(ps);
		sa(ps);
		pa(ps);
}

void	sort(t_ps *ps)
{
	new_algorithm(ps);
	return ;
}

void	sort_2(t_ps *ps)
{
	if (ps->a[0] < ps->a[1])
		return ;
	ra(ps);
	return ;
}

void	sort_3(t_ps *ps)
{
	return ;	
}

void	algorithm(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->size_a)
	{
		a_min_to_top(ps);
		pb(ps);
	}
	while(ps->size_b)
		pa(ps);
}

void	b_max_to_top(t_ps *ps)
{
	int	i;
	int	direction;

	i = 0;
	while (ps->b[i] != ps->max_b)
	{
		i++;
	}
	while (ps->b[0] != ps->max_b)
	{
		if (i > ps->size_b / 2)
			rrb(ps);
		else
			rb(ps);
	}
}

void	a_min_to_top(t_ps *ps)
{
	int	i;
	int	direction;

	i = 0;
	while (ps->a[i] != ps->min_a)
	{
		i++;
	}
	while (ps->a[0] != ps->min_a)
	{
		if (i > ps->size_a / 2)
			rra(ps);
		else
			ra(ps);
	}
}
int	alternating_rb(t_ps *ps, int j)
{
	if (j == 0)
		j++;
	else
		j = 0;
	if (j == 0)
		rb(ps);
	return (j);
}
int	choose_up_down(t_ps *ps, int size, int part)
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
void	new_algorithm(t_ps *ps)
{
	int	i;
	int	part;
	int	cutoff;
	int	max_part;
	int	size;
	int	j = 0;
	int	trigger;
	int	g = 0;

	size = ps->size_a;
	max_part = 10;
	i = 0;
	part = 1;
	while (ps->size_a)
	{
		while (ps->min_a < size / ps->parts * part && ps->size_a)
		{
			//trigger = choose_up_down(ps, size, part);
			trigger = 1;
			while (ps->a[0] > size / ps->parts * part && ps->size_a > 1)
			{
				if (trigger > 0)
					ra(ps);
				else
					rra(ps);
			}
			pb(ps);
			j = alternating_rb(ps, j);
			
		}
		part+=1;
	}
	while (ps->size_b)
	{
		b_max_to_top(ps);
		pa(ps);
	}
}
