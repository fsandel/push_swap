/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:48:38 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 19:24:33 by fsandel          ###   ########.fr       */
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
	ps->a_copy = (int *)ft_calloc(ps->size_a, sizeof(int));
	ps->b_copy = (int *)ft_calloc(ps->size_a, sizeof(int));
	ps->operations = 0;
	ps->parts = 1;
	return (ps);
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

int	check_whitespace_digit(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_iswhitespace(str[i])
			|| ft_strchr("+-", str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
