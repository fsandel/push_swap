/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:36:13 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 18:56:11 by fsandel          ###   ########.fr       */
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
				error('2', ps);
			i++;
		}
		j++;
	}
}

int	make_element(char **array, int i)
{
	long	temp;

	if ((array[i][0] == 0) || (ft_strlen_ignore(array[i]) > 10))
		free_exit(array);
	temp = ps_atoi(array[i]);
	if (temp > INT_MAX || temp < INT_MIN)
		free_exit(array);
	return ((int)temp);
}
