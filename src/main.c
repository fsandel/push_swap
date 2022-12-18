/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 21:15:15 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_stacks(t_ps *ps);

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
	int	*temp;
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

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	input_check(argc, argv);
	ps = init_stacks(argc, argv);
	create_stack(argc, argv, ps);
	check_duplicate(ps);
	change_to_index(ps);
	set_maxima(ps);
	copy_stacks(ps);
	sort(ps);
	free_struct(ps);
	return (0);
}

void	copy_stacks(t_ps *ps)
{
	ps->a_copy = ft_calloc(ps->size_a, sizeof(int));
	ps->b_copy = ft_calloc(ps->size_a, sizeof(int));
	ps->size = ps->size_a;
	ft_memcpy(ps->a_copy, ps->a, ps->size_a);
}