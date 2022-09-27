/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a_to_b_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:26:38 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 16:49:19 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See small_a_b... */
void	small_a_b_case2(int group, t_ps *ps)
{
	if (ps->stack_a[0].is_high == 1 && ps->stack_a[1].grp == group)
		ps->stack_a[1].is_high = 1;
	if (ps->stack_a[0].is_low == 1 && ps->stack_a[ps->len_a - 1].grp == group)
		ps->stack_a[ps->len_a - 1].is_low = 1;
	ps->stack_a[0].is_high = 1;
	ps->stack_a[0].is_low = 0;
	ps->stack_a[0].c_stack = 2;
	ps->stack_a[0].grp = ps->grp_in_b + 1;
	ps->stack_b[0].is_high = 0;
	pb(ps);
}

/* This function sorts the element of a group of lenght minor or equal to */
/* three when the group is in the stack a.*/
void	final_case_a(int group, t_ps *ps)
{
	if (len_grup(group, 1, ps) == 1)
		final_case_a_1(group, ps);
	else if (len_grup(group, 1, ps) == 2)
		final_case_a_2(group, ps);
	else if (len_grup(group, 1, ps) == 3)
		final_case_a_3(group, ps);
	if (ps->grp_in_a == 2)
		low_grade_a(ps);
	ps->grp_in_a--;
}

/* See final_case_a */
void	final_case_a_1(int group, t_ps *ps)
{
	set_zero(group, 1, ps);
}

/* See final_case_a */
void	final_case_a_2(int group, t_ps *ps)
{
	if (ps->stack_a[0].number > ps->stack_a[1].number)
		sa(ps);
	set_zero(group, 1, ps);
}

/* See final_case_a */
void	final_case_a_3(int group, t_ps *ps)
{
	if (ps->stack_a[0].number > ps->stack_a[1].number
		&& ps->stack_a[0].number < ps->stack_a[2].number)
		sa(ps);
	else if (ps->stack_a[2].number < ps->stack_a[1].number
		&& ps->stack_a[2].number > ps->stack_a[0].number)
		final_case_a_3_1(ps);
	else if (ps->stack_a[0].number < ps->stack_a[1].number
		&& ps->stack_a[0].number > ps->stack_a[2].number)
		final_case_a_3_2(ps);
	else if (ps->stack_a[2].number > ps->stack_a[1].number
		&& ps->stack_a[2].number < ps->stack_a[0].number)
		final_case_a_3_3(ps);
	else if (ps->stack_a[0].number > ps->stack_a[1].number
		&& ps->stack_a[1].number > ps->stack_a[2].number)
		final_case_a_3_4(ps);
	set_zero(group, 1, ps);
}
