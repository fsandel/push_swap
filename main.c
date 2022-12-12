/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:20:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 12:19:58 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	input_check(argc, argv);
	ps = init_stacks(argc, argv);
	create_stack(argc, argv, ps);
	print_stack(ps->a);
	print_stack(ps->b);
	check_duplicate(ps);
	return (0);
}
