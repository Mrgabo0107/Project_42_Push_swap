/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a_to_b_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:26:15 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 16:33:58 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See split... */
void	split_a_b(int group, t_ps *ps)
{
	while (len_grup(group, 1, ps) > 3)
	{
		attract_high(ps->grp_in_b, 2, ps);
		one_split_a_to_b(group, ps);
		if (len_grup(group, 1, ps) > 3)
			attract_near(group, 1, ps);
	}
	if (len_grup(group, 1, ps) <= 3)
	{
		attract_high(group, 1, ps);
		final_case_a(group, ps);
	}
}

/* This function split once the group passed as parameter from the stack a */
/* to the stack b. */
void	one_split_a_to_b(int group, t_ps *ps)
{
	if (ps->stack_a[0].is_high == 1)
	{
		one_split_a_b_high(group, ps);
		ps->grp_in_b += 2;
	}
	else if (ps->stack_a[0].is_low == 1)
	{
		one_split_a_b_low(group, ps);
		ps->grp_in_b += 2;
	}
}

/* If the index of the highest element of a group in t eh stack a is zero */
/* this fuction will do "ra" until there won't be smaller numbers than a */
/* middle value of the group, these values will be send to the stack b */
/* separated in two groups */
void	one_split_a_b_high(int group, t_ps *ps)
{
	int	max;
	int	min;

	max = grup_max(group, 1, ps);
	min = grup_min(group, 1, ps);
	while (check_less_than_half(group, (max + min) / 2, 1, ps) == 1)
	{
		if (ps->stack_a[0].number > (max + min) / 2)
			ra(ps);
		else if (((3 * min) + max) / 4 < ps->stack_a[0].number
			&& ps->stack_a[0].number <= (max + min) / 2)
			medium_a_b(group, ps, min, max);
		else if (ps->stack_a[0].number <= ((3 * min) + max) / 4)
			small_a_b(group, ps);
	}
}

/* If the index of the lowest element of a group in t eh stack a is zero */
/* this fuction will do "rra" until there won't be smaller numbers than a */
/* middle value of the group, these values will be send to the stack b */
/* separated in two groups */
void	one_split_a_b_low(int group, t_ps *ps)
{
	int	max;
	int	min;

	max = grup_max(group, 1, ps);
	min = grup_min(group, 1, ps);
	while (check_less_than_half(group, (max + min) / 2, 1, ps) == 1)
	{
		if (ps->stack_a[0].number > (max + min) / 2)
			rra(ps);
		else if (((3 * min) + max) / 4 < ps->stack_a[0].number
			&& ps->stack_a[0].number <= (max + min) / 2)
			medium_a_b(group, ps, min, max);
		else if (ps->stack_a[0].number <= ((3 * min) + max) / 4)
			small_a_b(group, ps);
	}
}

/* This function takes the numbers between one quarter and a half of the */
/* original group and send they below the stack b */
void	medium_a_b(int group, t_ps *ps, int min, int max)
{
	if (len_grup(ps->grp_in_b + 2, 2, ps) == 0)
		medium_a_b_case1(group, ps, min, max);
	else
	{
		if (ps->grp_in_b == 0 && ps->stack_b[0].number > ((3 * min) + max) / 4)
			medium_a_b_case2_1(group, ps);
		else
			medium_a_b_case2_2(group, ps, min, max);
	}
}
