/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:23:57 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 12:38:27 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct ps
{
	int		*a;
	int		*b;
	int		size;
}			t_ps;

//error.c
void	input_check(int argc, char *argv[]);
void	error(char c, void *ptr);
void	free_struct(void *ptr);
void	free_array(char **array);

//stacks.c
t_ps	*init_stacks(int argc, char *argv[]);
void	create_stack(int argc, char *argv[], t_ps *ps);
void	from_string(int argc, char *argv[], t_ps *ps);
void	from_numbers(int argc, char *argv[], t_ps *ps);

//check_element.c
int		check_element_char(char *str);
int		check_element_length(char *str);
void	check_duplicate(t_ps *ps);
int		check_element(char *str, t_ps *ps);

//utils.c
int		count_char(char *str, char c);
void	print_stack(int *stack);
long	ps_atoi(const char *str);

#endif
