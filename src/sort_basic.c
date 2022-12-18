/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <florian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:58 by florian           #+#    #+#             */
/*   Updated: 2022/12/18 20:24:05 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_basic(t_ps *ps, int print)
{
	while (ps->size_a)
	{
		a_min_to_top(ps, print);
		pb(ps, print);
	}
	while(ps->size_b)
		pa(ps, print);
}