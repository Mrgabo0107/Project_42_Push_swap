/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helpers_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:29 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:38:32 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* Set the right number of groups int he stack a in the final case of the */
/* split_a_to_b function*/
void	low_grade_a(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len_a)
	{
		if (ps->stack_a[i].grp == 2)
			ps->stack_a[i].grp = 1;
	i++;
	}
}

/* Set the is_high, is_low, grp and c_stack values to zero when a group */
/* is sorted, in the stack a or b if the c_stack value is one or two */
/* respectively.*/
void	set_zero(int group, int c_stack, t_ps *ps)
{
	if (c_stack == 1)
		set_zero_case_a(group, ps);
	else if (c_stack == 2)
		set_zero_case_b(group, ps);
}

/* See set_zero... */
void	set_zero_case_a(int group, t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->elem_num)
	{
		if (ps->stack_a[i].grp == group)
		{
			ps->stack_a[i].c_stack = 0;
			ps->stack_a[i].is_high = 0;
			ps->stack_a[i].is_low = 0;
			ps->stack_a[i].grp = 0;
		}
		i++;
	}
}

/* See set_zero... */
void	set_zero_case_b(int group, t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->elem_num)
	{
		if (ps->stack_b[i].grp == group)
		{
			ps->stack_b[i].c_stack = 0;
			ps->stack_b[i].is_high = 0;
			ps->stack_b[i].is_low = 0;
			ps->stack_b[i].grp = 0;
		}
		i++;
	}
}

/* Find the next number that isn't sorted in the stack a*/
int	find_next_number(t_ps *ps)
{
	int	i;
	int	res;

	res = ps->elem_num + 1;
	i = 0;
	while (i < ps->len_a)
	{
		if (ps->stack_a[i].grp == 0
			&& 0 < ps->stack_a[i].number && ps->stack_a[i].number < res)
			res = ps->stack_a[i].number;
		i++;
	}
	return (res - 1);
}
