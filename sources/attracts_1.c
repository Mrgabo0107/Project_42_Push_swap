/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attracts_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:58:15 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 20:23:39 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* Returns the lowest number of rotations to attract the lowest element */
/* of a group to the index 0, if the return is positive do "r", if is */
/* negative do "rr" in the corresponding stack. Unexpected behavior if the */
/* group isn't on the stack. */
int	to_attract_low(int group, int c_stack, t_ps *ps)
{
	int	steps1;
	int	steps2;

	steps1 = indx_grup_l(group, c_stack, ps);
	if (c_stack == 1)
	{
		steps2 = ps->len_a - indx_grup_l(group, c_stack, ps);
		if (steps2 < steps1)
			return (-steps2);
	}
	if (c_stack == 2)
	{
		steps2 = ps->len_b - indx_grup_l(group, c_stack, ps);
		if (steps2 < steps1)
			return (-steps2);
	}
	return (steps1);
}

/* Returns the lowest number of rotations to attract the higher element */
/* of a group to the index 0, if the return is positive do "r", if is */
/* negative do "rr" in the corresponding stack. Unespected behavior if the */
/* group isn't on the stack. */
int	to_attract_high(int group, int c_stack, t_ps *ps)
{
	int	steps1;
	int	steps2;

	steps1 = indx_grup_h(group, c_stack, ps);
	if (c_stack == 1)
	{
		steps2 = ps->len_a - indx_grup_h(group, c_stack, ps);
		if (steps2 < steps1)
			return (-steps2);
	}
	if (c_stack == 2)
	{
		steps2 = ps->len_b - indx_grup_h(group, c_stack, ps);
		if (steps2 < steps1)
			return (-steps2);
	}
	return (steps1);
}

/* Do the minimum number of "r" or "rr" to attract the lower group's */
/* element to the top of the stack defined by the c_stack value. */
void	attract_low(int group, int c_stack, t_ps *ps)
{
	int	steps;

	steps = to_attract_low(group, c_stack, ps);
	if (steps < 0 && len_grup(group, c_stack, ps) > 0)
		attract_down(steps, c_stack, ps);
	if (steps > 0 && len_grup(group, c_stack, ps) > 0)
		attract_up(steps, c_stack, ps);
}

/* Do the minimum number of "r" or "rr" to attract the higher group's */
/* element to the top of the stack defined by the c_stack value. */
void	attract_high(int group, int c_stack, t_ps *ps)
{
	int	steps;

	steps = to_attract_high(group, c_stack, ps);
	if (steps < 0 && len_grup(group, c_stack, ps) > 0)
		attract_down(steps, c_stack, ps);
	if (steps > 0 && len_grup(group, c_stack, ps) > 0)
		attract_up(steps, c_stack, ps);
}

/* Do "rr" in the stack defined by the c_stack value, "steps" times */
void	attract_down(int steps, int c_stack, t_ps *ps)
{
	int	i;

	i = -steps;
	while (i > 0)
	{
		if (c_stack == 1)
			rra(ps);
		if (c_stack == 2)
			rrb(ps);
		i--;
	}
}
