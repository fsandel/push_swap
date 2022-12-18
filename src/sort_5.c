/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:40:29 by florian           #+#    #+#             */
/*   Updated: 2022/12/18 20:33:07 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	min_to_other_side(t_ps *ps, int print);

void	sort_5(t_ps *ps, int print)
{
	if (is_finished(ps))
		return ;
	min_to_other_side(ps, print);
	sort_3(ps, print);
	pa(ps, print);
	pa(ps, print);
	return ;
}

void	min_to_other_side(t_ps *ps, int print)
{
	a_min_to_top(ps, print);
	pb(ps, print);
	a_min_to_top(ps, print);
	pb(ps, print);
	return ;
}

