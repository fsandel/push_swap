/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:59:50 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 19:23:44 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_smaller(int value, int *temp, int size)
{
	int	i;
	int	amount;

	amount = 0;
	i = 0;
	while (i < size)
	{
		if (value > temp[i])
			amount++;
		i++;
	}
	return (amount);
}

void	change_to_index(t_ps *ps)
{
	int		*temp;
	int		i;

	temp = ft_calloc(ps->size_a, sizeof(int));
	i = 0;
	while (i < ps->size_a)
	{
		temp[i] = ps->a[i];
		i++;
	}
	i = 0;
	while (i < ps->size_a)
	{
		ps->a[i] = count_smaller(ps->a[i], temp, ps->size_a);
		i++;
	}
	free(temp);
}
