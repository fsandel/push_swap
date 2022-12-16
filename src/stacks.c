/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:48:38 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 13:32:20 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps	*init_stacks(int argc, char *argv[])
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps) * 1);
	ps->size_a = get_array_size(argc, argv);
	ps->size_b = 0;
	ps->a = (int *)ft_calloc(ps->size_a, sizeof(int));
	ps->b = (int *)ft_calloc(ps->size_a, sizeof(int));
	ps->operations = 0;
	ps->parts = 3;
	
	return (ps);
}

void	set_maxima(t_ps *ps)
{
	ps->max_a = get_maximum(ps->a, ps->size_a);
	ps->min_a = get_minimum(ps->a, ps->size_a);
	ps->max_b = INT_MIN;
	ps->min_b = INT_MAX;
}

int	get_array_size(int argc, char *argv[])
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < argc)
		len += count_words(argv[i++]);
	return (len);
}

void	create_stack(int argc, char *argv[], t_ps *ps)
{
	int		j;
	char	**array;
	int		i;
	int		index;
	long	temp;

	index = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		if (argv[j][0] == 0 || !check_whitespace_digit(argv[j]))
			free_exit(NULL);
		array = ft_split(argv[j], ' ');
		while (array[i])
			ps->a[index++] = make_element(array, i++);
		free_array(array);
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

int	check_whitespace_digit(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_iswhitespace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_exit(char **array)
{
	if (array)
		free_array(array);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ft_iswhitespace(char c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	else
		return (0);
}
