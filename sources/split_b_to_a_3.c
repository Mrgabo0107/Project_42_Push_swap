/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b_to_a_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:52:58 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:18:24 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* This function sorts the element of a group of lenght minor or equal to */
/* three when the group is in the stack b.*/
void	final_case_b(int group, t_ps *ps)
{
	if (len_grup(group, 2, ps) == 1)
		final_case_b_1(group, ps);
	else if (len_grup(group, 2, ps) == 2)
		final_case_b_2(group, ps);
	else if (len_grup(group, 2, ps) == 3)
		final_case_b_3(group, ps);
	ps->grp_in_b--;
}

/* See final_case_b */
void	final_case_b_1(int group, t_ps *ps)
{
	set_zero(group, 2, ps);
	pa(ps);
}

/* See final_case_b */
void	final_case_b_2(int group, t_ps *ps)
{
	set_zero(group, 2, ps);
	if (ps->stack_b[0].number < ps->stack_b[1].number)
		sb(ps);
	pa(ps);
	pa(ps);
}

/* See final_case_b */
void	final_case_b_3(int group, t_ps *ps)
{
	set_zero(group, 2, ps);
	if (ps->stack_b[1].number < ps->stack_b[0].number
		&& ps->stack_b[1].number > ps->stack_b[2].number)
		final_case_b_3_1(ps);
	else if (ps->stack_b[2].number < ps->stack_b[0].number
		&& ps->stack_b[2].number > ps->stack_b[1].number)
		final_case_b_3_2(ps);
	else if (ps->stack_b[0].number < ps->stack_b[2].number
		&& ps->stack_b[0].number > ps->stack_b[1].number)
		final_case_b_3_3(ps);
	else if (ps->stack_b[0].number < ps->stack_b[1].number
		&& ps->stack_b[0].number > ps->stack_b[2].number)
		final_case_b_3_4(ps);
	else if (ps->stack_b[1].number < ps->stack_b[2].number
		&& ps->stack_b[1].number > ps->stack_b[0].number)
		final_case_b_3_5(ps);
	else if (ps->stack_b[2].number < ps->stack_b[1].number
		&& ps->stack_b[2].number > ps->stack_b[0].number)
		final_case_b_3_6(ps);
}

/* See final_case_b */
void	final_case_b_3_1(t_ps *ps)
{
	pa(ps);
	pa(ps);
	pa(ps);
}
