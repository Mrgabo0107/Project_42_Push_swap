/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a_to_b_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:26:31 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 03:26:33 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See medium_a_b... */
void	medium_a_b_case1(int group, t_ps *ps, int min, int max)
{
	if (ps->stack_a[0].is_high == 1 && ps->stack_a[1].grp == group)
		ps->stack_a[1].is_high = 1;
	if (ps->stack_a[0].is_low == 1 && ps->stack_a[ps->len_a - 1].grp == group)
		ps->stack_a[ps->len_a - 1].is_low = 1;
	ps->stack_a[0].is_high = 1;
	ps->stack_a[0].is_low = 1;
	ps->stack_a[0].c_stack = 2;
	ps->stack_a[0].grp = ps->grp_in_b + 2;
	pb(ps);
	if (ps->len_b >= 2 && ps->stack_b[1].number <= ((3 * min) + max) / 4
		&& check_less_than_half(group, (max + min) / 2, 1, ps) == 1)
		rb(ps);
}

/* See medium_a_b... */
void	medium_a_b_case2_1(int group, t_ps *ps)
{
	if (ps->stack_a[0].is_high == 1 && ps->stack_a[1].grp == group)
		ps->stack_a[1].is_high = 1;
	if (ps->stack_a[0].is_low == 1 && ps->stack_a[ps->len_a - 1].grp == group)
		ps->stack_a[ps->len_a - 1].is_low = 1;
	ps->stack_a[0].is_high = 1;
	ps->stack_a[0].is_low = 0;
	ps->stack_a[0].c_stack = 2;
	ps->stack_a[0].grp = ps->grp_in_b + 2;
	ps->stack_b[0].is_high = 0;
	pb(ps);
}

/* See medium_a_b... */
void	medium_a_b_case2_2(int group, t_ps *ps, int min, int max)
{
	if (ps->stack_a[0].is_high == 1 && ps->stack_a[1].grp == group)
		ps->stack_a[1].is_high = 1;
	if (ps->stack_a[0].is_low == 1 && ps->stack_a[ps->len_a - 1].grp == group)
		ps->stack_a[ps->len_a - 1].is_low = 1;
	ps->stack_a[0].is_high = 0;
	ps->stack_a[0].is_low = 1;
	ps->stack_a[0].c_stack = 2;
	ps->stack_a[0].grp = ps->grp_in_b + 2;
	ps->stack_b[ps->len_b - 1].is_low = 0;
	pb(ps);
	if (check_less_than_half(group, (max + min) / 2, 1, ps) == 1)
		rb(ps);
}

/* This function takes numbers less than a quarter of the original group */
/* and send they at the top of the stack b */
void	small_a_b(int group, t_ps *ps)
{
	if (len_grup(ps->grp_in_b + 1, 2, ps) == 0)
		small_a_b_case1(group, ps);
	else
		small_a_b_case2(group, ps);
}

/* See small_a_b... */
void	small_a_b_case1(int group, t_ps *ps)
{
	if (ps->stack_a[0].is_high == 1 && ps->stack_a[1].grp == group)
		ps->stack_a[1].is_high = 1;
	if (ps->stack_a[0].is_low == 1 && ps->stack_a[ps->len_a - 1].grp == group)
		ps->stack_a[ps->len_a - 1].is_low = 1;
	ps->stack_a[0].is_high = 1;
	ps->stack_a[0].is_low = 1;
	ps->stack_a[0].c_stack = 2;
	ps->stack_a[0].grp = ps->grp_in_b + 1;
	pb(ps);
}
