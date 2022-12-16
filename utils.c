/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:41 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/13 15:02:23 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_ps *ps)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < ps->size_a || b < ps->size_b)
	{
		if (a < ps->size_a)
			ft_putnbr_fd(ps->a[a++], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("\t", 1);
		if (b < ps->size_b)
			ft_putnbr_fd(ps->b[b++], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
	}
}

int	ft_strlen_ignore(char *str)
{
	int	i;
	char const skip[] = {9, 10, 11, 12, 13, 32, '0', 0};
	int	len;

	i = 0;
	while (str[i] && ft_strchr(skip, str[i]))
		i++;
	len = i;
	while (str[len] && ft_isdigit(str[len]))
		len++;
	return (len - i);
}

int	count_words(char const *s)
{
	int		i;
	int			count;
	char const	c = ' ';

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count + 1);
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
