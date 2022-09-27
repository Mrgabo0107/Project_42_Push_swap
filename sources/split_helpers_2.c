/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helpers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:36 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:48:55 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* Returns the next number's group or minus one if it doesn't find it*/
int	find_next_number_group(t_ps *ps)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (i < ps->len_a)
	{
		if (ps->stack_a[i].number == find_next_number(ps))
			res = ps->stack_a[i].grp;
		i++;
	}
	i = 0;
	while (i < ps->len_b)
	{
		if (ps->stack_b[i].number == find_next_number(ps))
			res = ps->stack_b[i].grp;
		i++;
	}
	return (res);
}

/* Returns the next number's stack control "c_stack" or zero if it doesn't */
/* find it */
int	find_next_number_stack(t_ps *ps)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < ps->len_a)
	{
		if (ps->stack_a[i].number == find_next_number(ps))
			res = 1;
		i++;
	}
	i = 0;
	while (i < ps->len_b)
	{
		if (ps->stack_b[i].number == find_next_number(ps))
			res = 2;
		i++;
	}
	return (res);
}

/* If there are still numbers to split from one group in the strack a */
/* returns one, or zero if is not the case. */
int	check_less_than_half(int group, int middle, int c_stack, t_ps *ps)
{
	int	i;

	i = 0;
	if (c_stack == 1)
	{
		while (i < ps->len_a)
		{
			if (ps->stack_a[i].grp == group && ps->stack_a[i].number <= middle)
				return (1);
			i++;
		}
	}
	if (c_stack == 2)
	{
		while (i < ps->len_b)
		{
			if (ps->stack_b[i].grp == group && ps->stack_b[i].number <= middle)
				return (1);
			i++;
		}
	}
	return (0);
}

/* If there are still numbers to split from one group in the strack b */
/* returns one, or zero if is not the case. */
int	check_more_than_three_quarters(int group, int middle, int c_stack, t_ps *ps)
{
	int	i;

	i = 0;
	if (c_stack == 1)
	{
		while (i < ps->len_a)
		{
			if (ps->stack_a[i].grp == group && ps->stack_a[i].number > middle)
				return (1);
			i++;
		}
	}
	if (c_stack == 2)
	{
		while (i < ps->len_b)
		{
			if (ps->stack_b[i].grp == group && ps->stack_b[i].number > middle)
				return (1);
			i++;
		}
	}
	return (0);
}
