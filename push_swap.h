/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:23:57 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/12 18:07:14 by fsandel          ###   ########.fr       */
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
	int		size_a;
	int		size_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		operations;
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
void	print_stacks(t_ps *ps);

//sort_utils.c
int		size(int *stack);
int		get_maximum(int *stack, int stack_size);
int		get_minimum(int *stack, int stack_size);
int		is_sorted(int *stack, int stack_size);
int		is_finished(t_ps *ps);

//swap.c
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

//push.c
void	pa(t_ps *ps);
void	pb(t_ps *ps);

//rotate.c
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);

//reverse_rotate.c
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

//sorting.c
void	sort(t_ps *ps);
void	sort_2(t_ps *ps);
void	sort_3(t_ps *ps);

#endif
