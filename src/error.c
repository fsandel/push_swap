/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:31:13 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/16 13:31:45 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	input_check(int argc, char *argv[])
{
	if (argc < 2)
		error('a', NULL);
}

void	error(char c, void *ptr)
{
	free_struct(ptr);
	ft_putendl_fd("Error", 2);
	if (c == 'a')
		ft_putendl_fd("Not enough erguments", 2);
	else if (c == 'd')
		ft_putendl_fd("Non digit found in input", 2);
	else if (c == 's')
		ft_putendl_fd("Inputstring too small", 2);
	else if (c == 'e')
		ft_putendl_fd("Not enough elements in input string", 2);
	else if (c == 'i')
		ft_putendl_fd("number bigger that an integer", 2);
	else if (c == '2')
		ft_putendl_fd("duplicate found", 2);
	else
		ft_putendl_fd("Random error", 2);
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
