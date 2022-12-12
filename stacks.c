/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:48:38 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 12:38:47 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*init_stacks(int argc, char *argv[])
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps) * 1);
	if (argc == 2)
		ps->size = count_char(argv[1], ' ') + 1;
	else
		ps->size = argc - 1;
	ps->a = (int *)ft_calloc(ps->size + 1, sizeof(int));
	ps->b = (int *)ft_calloc(ps->size + 1, sizeof(int));
	return (ps);
}

void	create_stack(int argc, char *argv[], t_ps *ps)
{
	if (argc == 2)
		from_string(argc, argv, ps);
	else
		from_numbers(argc, argv, ps);
}

void	from_string(int argc, char *argv[], t_ps *ps)
{
	char	**array;
	int		j;

	array = ft_split(argv[1], ' ');
	j = 0;
	while (array[j])
	{
		ps->a[j] = check_element(array[j], ps);
		j++;
	}
	free_array(array);
}

void	from_numbers(int argc, char *argv[], t_ps *ps)
{
	int		i;
	long	temp;

	i = 0;
	while (i < ps->size && argv[i + 1])
	{
		ps->a[i] = check_element(argv[i + 1], ps);
		i++;
	}
}
