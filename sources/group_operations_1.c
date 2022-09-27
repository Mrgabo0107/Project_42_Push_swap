/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:49:36 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:49:38 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* returns the higher index of a group, set c_stack = 1 for search in the */
/* stack a or 2 for search in b. */
/*  Returns elem_num -1 if the group doesn't exist in the stack */
int	indx_grup_h(int group, int c_stack, t_ps *ps)
{
	int	res;

	res = ps->elem_num + 1;
	if (c_stack == 1)
	{
		while (res >= 0)
		{
			if (ps->stack_a[res].grp == group && ps->stack_a[res].is_high == 1)
				return (res);
		res--;
		}
	}
	if (c_stack == 2)
	{
		while (res >= 0)
		{
			if (ps->stack_b[res].grp == group && ps->stack_b[res].is_high == 1)
				return (res);
			res--;
		}
	}
	return (res);
}

/* returns the lower index of a group, set c_stack = 1 for search in the */
/* stack a or 2 for search in b. */
/* returns -1 if the group doesn't exist in the stack */
int	indx_grup_l(int group, int c_stack, t_ps *ps)
{
	int	res;

	res = ps->elem_num + 1;
	if (c_stack == 1)
	{
		while (res >= 0)
		{
			if (ps->stack_a[res].grp == group && ps->stack_a[res].is_low == 1)
				return (res);
			res--;
		}
	}
	if (c_stack == 2)
	{
		while (res >= 0)
		{
			if (ps->stack_b[res].grp == group && ps->stack_b[res].is_low == 1)
				return (res);
		res--;
		}
	}
	return (res);
}

/* Returns the maximum value of a group in the stack defined by c_stack */
/* value, or 0 if the group doesn't exist in the stack. */
int	grup_max(int group, int c_stack, t_ps *ps)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (c_stack == 1)
	{
		while (i < ps->len_a)
		{
			if (ps->stack_a[i].grp == group && ps->stack_a[i].number > res)
				res = ps->stack_a[i].number;
			i++;
		}
	}
	if (c_stack == 2)
	{
		while (i < ps->len_b)
		{
			if (ps->stack_b[i].grp == group && ps->stack_b[i].number > res)
				res = ps->stack_b[i].number;
			i++;
		}
	}
	return (res);
}

/* Returns the minimum value of a group in the stack defined by c_stack */
/* value, or num_elem + 1 if the group doesn't exist in the stack. */
int	grup_min(int group, int c_stack, t_ps *ps)
{
	int	res;
	int	i;

	i = 0;
	res = ps->elem_num + 1;
	if (c_stack == 1)
	{
		while (i < ps->len_a)
		{
			if (ps->stack_a[i].grp == group && ps->stack_a[i].number < res)
				res = ps->stack_a[i].number;
		i++;
		}
	}
	if (c_stack == 2)
	{
		while (i < ps->len_b)
		{
			if (ps->stack_b[i].grp == group && ps->stack_b[i].number < res)
				res = ps->stack_b[i].number;
			i++;
		}
	}
	return (res);
}

/* Returns the lenght of the group in the stack defined by the c_stack */
/* value or 0 if the group doesn't exist in the group. */
int	len_grup(int group, int c_stack, t_ps *ps)
{
	int	res;

	res = 0;
	if (c_stack == 1 && indx_grup_h(group, 1, ps)
		>= 0 && indx_grup_l(group, 1, ps) >= 0)
		res = len_gr_a(group, ps);
	if (c_stack == 2 && indx_grup_h(group, 2, ps)
		>= 0 && indx_grup_l(group, 2, ps) >= 0)
		res = len_gr_b(group, ps);
	return (res);
}
