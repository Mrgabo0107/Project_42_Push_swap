/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b_to_a_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:52:35 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 17:52:31 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See split... */
void	split_b_a(int group, t_ps *ps)
{
	attract_near(ps->grp_in_b, 2, ps);
	if (len_grup(group, 2, ps) > 3)
		one_split_b_to_a(group, ps);
	else
	{
		attract_high(ps->grp_in_b, 2, ps);
		final_case_b(group, ps);
	}
}

/* This function split once the group passed as parameter from the stack b */
/* to the stack a. */
void	one_split_b_to_a(int group, t_ps *ps)
{
	if (ps->stack_b[0].is_high == 1)
	{
		one_split_b_a_high(group, ps);
		ps->grp_in_a += 2;
	}
	else if (ps->stack_b[0].is_low == 1)
	{
		one_split_b_a_low(group, ps);
		ps->grp_in_a += 2;
	}
}

/* If the index of the highest element of a group in t eh stack b is zero */
/* this fuction will do "rb" until there will be only greater numbers */
/* than three quarters between the minumum and maximum value of the group */
/* in the stack b, these numbers will be send to the stack a separated in */
/* two groups */
void	one_split_b_a_high(int group, t_ps *ps)
{
	int	max;
	int	min;

	max = grup_max(group, 2, ps);
	min = grup_min(group, 2, ps);
	while (check_more_than_three_quarters(group,
			((3 * min) + max) / 4, 2, ps) == 1)
	{
		if (ps->stack_b[0].number > (max + min) / 2)
			big_b_a(group, ps);
		else if (((3 * min) + max) / 4 < ps->stack_b[0].number
			&& ps->stack_b[0].number <= (max + min) / 2)
			medium_b_a(group, ps);
		else if (ps->stack_b[0].number <= ((3 * min) + max) / 4)
			rb(ps);
	}
}

/* If the index of the lowest element of a group in t eh stack b is zero */
/* this fuction will do "rrb" until there will be only greater numbers */
/* than three quarters between the minumum and maximum value of the group */
/* in the stack b, these numbers will be send to the stack a separated in */
/* two groups */
void	one_split_b_a_low(int group, t_ps *ps)
{
	int	max;
	int	min;

	max = grup_max(group, 2, ps);
	min = grup_min(group, 2, ps);
	while (check_more_than_three_quarters(group,
			((3 * min) + max) / 4, 2, ps) == 1)
	{
		if (ps->stack_b[0].number > (max + min) / 2)
			big_b_a(group, ps);
		else if (((3 * min) + max) / 4 < ps->stack_b[0].number
			&& ps->stack_b[0].number <= (max + min) / 2)
			medium_b_a(group, ps);
		else if (ps->stack_b[0].number <= ((3 * min) + max) / 4)
			rrb(ps);
	}
}

/* This fuctiond send the numbers grather than a middle of the original */
/* group at the top of the stack b */
void	big_b_a(int group, t_ps *ps)
{
	if (len_grup(ps->grp_in_a + 2, 1, ps) == 0)
		big_b_a_case1(group, ps);
	else
		big_b_a_case2(group, ps);
}
