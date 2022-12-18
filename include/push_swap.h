/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:23:57 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/18 21:14:29 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define OUTPUT	1

typedef struct ps
{
	int		*a;
	int		*b;
	int		*a_copy;
	int		*b_copy;
	int		size;
	int		size_a;
	int		size_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		operations;
	int		parts;
}			t_ps;

//sort_2.c
void	sort_2(t_ps *ps, int print);

//sort_3.c
void	sort_3(t_ps *ps, int print);

//sort_4.c
void	sort_4(t_ps *ps, int print);

//sort_5.c
void	sort_5(t_ps *ps, int print);

//sort_basic.c
void	sort_basic(t_ps *ps, int print);

//sort_chunk.c
void	sort_chunk(t_ps *ps, int chunks, int size, int print);

//sort_radix.c
void	sort_radix(t_ps *ps, int size, int print);

//extreme.c
void	update_extreme(t_ps *ps);
int		get_maximum(int *stack, int stack_size);
int		get_minimum(int *stack, int stack_size);

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
void	free_exit(char **array);
int		ft_iswhitespace(char c);
int		check_whitespace_digit(char *str);
int		make_element(char **array, int i);
void	set_maxima(t_ps *ps);

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
int		count_words(char const *s);
int		get_array_size(int argc, char *argv[]);
int		ft_strlen_ignore(char *str);

//sort_utils.c
int		is_finished(t_ps *ps);
void	b_max_to_top(t_ps *ps, int print);
void	a_min_to_top(t_ps *ps, int print);

//swap.c
void	sa(t_ps *ps, int print);
void	sb(t_ps *ps, int print);
void	ss(t_ps *ps, int print);

//push.c
void	pa(t_ps *ps, int print);
void	pb(t_ps *ps, int print);

//rotate.c
void	ra(t_ps *ps, int print);
void	rb(t_ps *ps, int print);
void	rr(t_ps *ps, int print);

//reverse_rotate.c
void	rra(t_ps *ps, int print);
void	rrb(t_ps *ps, int print);
void	rrr(t_ps *ps, int print);

//sorting.c
void	sort(t_ps *ps);
void	sort_small(t_ps *ps);
void	reset_stacks(t_ps *ps);


#endif
