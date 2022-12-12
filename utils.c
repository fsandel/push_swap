/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:41 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 12:35:58 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_char(char *str, char c)
{
	int	i;
	int	counter;

	if (ft_strlen(str) < 3)
		error('s', NULL);
	i = 0;
	counter = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] != c)
			counter++;
		i++;
	}
	if (counter < 1)
		error('e', NULL);
	return (counter);
}

void	print_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_putnbr_fd(stack[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}

long	ps_atoi(const char *str)
{
	int		i;
	long	out;
	int		vz;

	i = 0;
	out = 0;
	vz = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			vz = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out += str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			out *= 10;
		i++;
	}
	return (out * vz);
}
