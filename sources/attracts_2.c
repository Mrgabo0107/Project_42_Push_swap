/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attracts_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:58:22 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 20:25:14 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* Do "r" in the stack defined by the c_stack value, "steps" times */
void	attract_up(int steps, int c_stack, t_ps *ps)
{
	int	i;

	i = steps;
	while (i > 0)
	{
		if (c_stack == 1)
			ra(ps);
		if (c_stack == 2)
			rb(ps);
		i--;
	}
}

/* Check which operation takes fewer steps between attract the higher or the */
/* lower element of a group to the index zero, in the stack defined by the */
/* c_stack value, and then attracts it. */
void	attract_near(int group, int c_stack, t_ps *ps)
{
	int	s_high;
	int	s_low;

	s_high = ft_abs(to_attract_high(group, c_stack, ps));
	s_low = ft_abs(to_attract_low(group, c_stack, ps));
	if (s_high < s_low)
		attract_high(group, c_stack, ps);
	else
		attract_low(group, c_stack, ps);
}
