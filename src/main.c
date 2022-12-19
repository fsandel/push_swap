/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/19 19:23:22 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
