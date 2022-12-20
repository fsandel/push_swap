/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:31:13 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/20 15:48:07 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void *ptr)
{
	free_struct(ptr);
	ft_putendl_fd("Error", 2);
	if (LEAK)
		system("leaks push_swap");
	exit(1);
}

void	free_struct(void *ptr)
{
	t_ps	*ps;

	if (!ptr)
		return ;
	ps = (t_ps *)ptr;
	free(ps->a);
	free(ps->b);
	free(ps->a_copy);
	free(ps->b_copy);
	free(ps);
	return ;
}

void	free_array(char **array)
{
	int	j;

	j = 0;
	while (array[j])
		free(array[j++]);
	free(array);
}

void	free_exit(char **array)
{
	if (array)
		free_array(array);
	ft_putendl_fd("Error", 2);
	if (LEAK)
		system("leaks push_swap");
	exit(1);
}
