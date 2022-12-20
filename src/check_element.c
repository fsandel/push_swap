/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:36:13 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/20 15:55:28 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_duplicate(t_ps *ps)
{
	int	j;
	int	i;
	int	temp;

	j = 0;
	while (j < ps->size_a)
	{
		temp = ps->a[j];
		i = 0;
		while (i < ps->size_a)
		{
			if (temp == ps->a[i] && i != j)
				error(ps);
			i++;
		}
		j++;
	}
}

int	make_element(char **array, int i, t_ps *ps)
{
	long	temp;

	if ((array[i][0] == 0) || (ft_strlen_ignore(array[i]) > 10))
	{
		free_struct(ps);
		free_exit(array);
	}
	temp = ps_atoi(array[i], ps, array);
	if (temp > INT_MAX || temp < INT_MIN)
	{
		free_struct(ps);
		free_exit(array);
	}
	return ((int)temp);
}
