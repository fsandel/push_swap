/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 20:00:38 by fsandel          ###   ########.fr       */
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
	//sort(ps);
	radix(ps);
	//print_stacks(ps);
	free_struct(ps);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_ps	*ps;
// 	int	i;

// 	i = 1;
// 	while (i < 100)
// 	{
// 		input_check(argc, argv);
// 		ps = init_stacks(argc, argv);
// 		create_stack(argc, argv, ps);
// 		check_duplicate(ps);
// 		change_to_index(ps);
// 		set_maxima(ps);
// 		ps->parts = i;
// 		sort(ps);
// 		free_struct(ps);
// 		ft_printf("max_parts: %d, \t operations: %d\n", i, ps->operations);
// 		i++;
// 	}
// 	return (0);
// }
