/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:34 by florian           #+#    #+#             */
/*   Updated: 2022/12/19 19:22:15 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4(t_ps *ps, int print)
{
	a_min_to_top(ps, print);
	pb(ps, print);
	sort_3(ps, print);
	pa(ps, print);
}
