/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 11:25:36 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_and_overwrite(t_ps *ps);
void	change_to_index(t_ps *ps);

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	input_check(argc, argv);
	ps = init_stacks(argc, argv);
	create_stack(argc, argv, ps);
	check_duplicate(ps);
	change_to_index(ps);
	set_maxima(ps);
	//ft_printf("%d %d\n", ps->max_a, ps->max_b);
	sort(ps);
	//ft_putstr_fd("----------", 1);
	//print_stacks(ps);
	//print_stacks(ps);
	//if (is_finished(ps))
	//	ft_printf("sorted\n");
	//ft_printf("Needed %d operations\n", ps->operations);
	free_struct(ps);
	//system("leaks push_swap");
	return (0);
}

void	change_to_index(t_ps *ps)
{
	int	*temp;
	int	i;

	temp = ft_calloc(ps->size_a, sizeof(int));
	i = 0;
	while (i < ps->size_a)
		temp[i++] = get_min_and_overwrite(ps);
	i = 0;
	while (i < ps->size_a)
	{
		ps->a[i] = temp[i];
		i++;
	}
	free(temp);
}

int	get_min_and_overwrite(t_ps *ps)
{
	int	i;
	int	index;
	int	min;

	index = 0;
	min = ps->a[index];
	i = 0;
	while (i < ps->size_a)
	{
		if (min > ps->a[i])
		{
			index = i;
			min = ps->a[i];
		}
		i++;
	}
	ps->a[index] = INT_MAX;
	return (index);
}
