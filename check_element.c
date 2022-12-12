/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:36:13 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 12:39:11 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_element(char *str, t_ps *ps)
{
	long	temp;

	if (check_element_char(str) == -1)
		error('d', ps);
	if (check_element_length(str) > 10)
		error('i', ps);
	temp = ps_atoi(str);
	if (temp > INT_MAX || temp < INT_MIN)
		error('i', ps);
	return ((int)temp);
}

int	check_element_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (-1);
	}
	return (0);
}

int	check_element_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			break ;
		i++;
	}
	len = ft_strlen(str);
	return (len - i);
}

void	check_duplicate(t_ps *ps)
{
	int	j;
	int	i;
	int	temp;

	j = 0;
	while (ps->a[j])
	{
		temp = ps->a[j];
		i = 0;
		while (ps->a[i])
		{
			if (temp == ps->a[i] && i != j)
				error('2', ps);
			i++;
		}
		j++;
	}
}
