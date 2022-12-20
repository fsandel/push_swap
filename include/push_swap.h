/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:23:57 by fsandel           #+#    #+#             */
/*   Updated: 2022/12/20 11:03:48 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define LEAK 0

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

//utils.c
void	print_stacks(t_ps *ps);
int		ft_strlen_ignore(char *str);
int		count_words(char const *s);
long	ps_atoi(const char *str, t_ps *ps);
int		ft_iswhitespace(char c);

//swap.c
void	sa(t_ps *ps, int print);
void	sb(t_ps *ps, int print);
void	ss(t_ps *ps, int print);

//stacks.c
t_ps	*init_stacks(int argc, char *argv[]);
int		get_array_size(int argc, char *argv[]);
void	create_stack(int argc, char *argv[], t_ps *ps);
int		check_whitespace_digit(char *str);

//sorting.c
void	choose_sort(t_ps *ps);
void	sort(t_ps *ps);
void	sort_small(t_ps *ps, int print);

//sort_chunk.c
void	sort_chunk(t_ps *ps, int chunks, int size, int print);
void	get_chunks(t_ps *ps, int max_chunks);

//sort_radix.c
void	sort_radix(t_ps *ps, int size, int print);

//sort_utils.c
int		is_finished(t_ps *ps);
void	b_max_to_top(t_ps *ps, int print);
void	a_min_to_top(t_ps *ps, int print);

//sort_5.c
void	sort_5(t_ps *ps, int print);

//sort_4.c
void	sort_4(t_ps *ps, int print);

//sort_3.c
void	sort_3(t_ps *ps, int print);

//sort_2.c
void	sort_2(t_ps *ps, int print);

//rotate.c
void	ra(t_ps *ps, int print);
void	rb(t_ps *ps, int print);
void	rr(t_ps *ps, int print);

//reverse_rotate.c
void	rra(t_ps *ps, int print);
void	rrb(t_ps *ps, int print);
void	rrr(t_ps *ps, int print);

//reset.c
void	copy_stacks(t_ps *ps);
void	reset_stacks(t_ps *ps);

//push.c
void	pa(t_ps *ps, int print);
void	pb(t_ps *ps, int print);

//index.c
int		count_smaller(int value, int *temp, int size);
void	change_to_index(t_ps *ps);

//extreme.c
void	update_extreme(t_ps *ps);
int		get_maximum(int *stack, int stack_size);
int		get_minimum(int *stack, int stack_size);
void	set_maxima(t_ps *ps);

//error.c
void	input_check(int argc, char *argv[]);
void	error(char c, void *ptr);
void	free_struct(void *ptr);
void	free_array(char **array);
void	free_exit(char **array);

//check_element.c
void	check_duplicate(t_ps *ps);
int		make_element(char **array, int i, t_ps *ps);

#endif
