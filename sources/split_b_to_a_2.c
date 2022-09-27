/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b_to_a_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:52:51 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:09:51 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/*See big_b_a...*/
void	big_b_a_case1(int group, t_ps *ps)
{
	if (ps->stack_b[0].is_high == 1 && ps->stack_b[1].grp == group)
		ps->stack_b[1].is_high = 1;
	if (ps->stack_b[0].is_low == 1 && ps->stack_b[ps->len_b - 1].grp == group)
		ps->stack_b[ps->len_b - 1].is_low = 1;
	ps->stack_b[0].is_high = 1;
	ps->stack_b[0].is_low = 1;
	ps->stack_b[0].c_stack = 1;
	ps->stack_b[0].grp = ps->grp_in_a + 2;
	pa(ps);
}

/*See big_b_a...*/
void	big_b_a_case2(int group, t_ps *ps)
{
	if (ps->stack_b[0].is_high == 1 && ps->stack_b[1].grp == group)
		ps->stack_b[1].is_high = 1;
	if (ps->stack_b[0].is_low == 1 && ps->stack_b[ps->len_b - 1].grp == group)
		ps->stack_b[ps->len_b - 1].is_low = 1;
	ps->stack_b[0].is_high = 1;
	ps->stack_b[0].is_low = 0;
	ps->stack_b[0].c_stack = 1;
	ps->stack_b[0].grp = ps->grp_in_a + 2;
	ps->stack_a[0].is_high = 0;
	pa(ps);
}

/* This function takes the numbers between one quarter and a half of the */
/* original group and send they below the stack a */
void	medium_b_a(int group, t_ps *ps)
{
	if (len_grup(ps->grp_in_a + 1, 1, ps) == 0)
		medium_b_a_case1(group, ps);
	else
		medium_b_a_case2(group, ps);
}

/* See medium_b_a*/
void	medium_b_a_case1(int group, t_ps *ps)
{
	if (ps->stack_b[0].is_high == 1 && ps->stack_b[1].grp == group)
		ps->stack_b[1].is_high = 1;
	if (ps->stack_b[0].is_low == 1 && ps->stack_b[ps->len_b - 1].grp == group)
		ps->stack_b[ps->len_b - 1].is_low = 1;
	ps->stack_b[0].is_high = 1;
	ps->stack_b[0].is_low = 1;
	ps->stack_b[0].c_stack = 1;
	ps->stack_b[0].grp = ps->grp_in_a + 1;
	pa(ps);
	ra(ps);
}

/* See medium_b_a*/
void	medium_b_a_case2(int group, t_ps *ps)
{
	if (ps->stack_b[0].is_high == 1 && ps->stack_b[1].grp == group)
		ps->stack_b[1].is_high = 1;
	if (ps->stack_b[0].is_low == 1 && ps->stack_b[ps->len_b - 1].grp == group)
		ps->stack_b[ps->len_b - 1].is_low = 1;
	ps->stack_b[0].is_high = 0;
	ps->stack_b[0].is_low = 1;
	ps->stack_b[0].c_stack = 1;
	ps->stack_b[0].grp = ps->grp_in_a + 1;
	ps->stack_a[ps->len_a - 1].is_low = 0;
	pa(ps);
	ra(ps);
}
