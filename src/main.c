/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/20 10:50:35 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	input_check(argc, argv);
	ps = init_stacks(argc, argv);
	create_stack(argc, argv, ps);
	check_duplicate(ps);
	change_to_index(ps);
	set_maxima(ps);
	copy_stacks(ps);
	sort(ps);
	free_struct(ps);
	if (LEAK)
		system("leaks push_swap");
	return (0);
}
