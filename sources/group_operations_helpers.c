/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_operations_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:46:47 by gamoreno          #+#    #+#             */
/*   Updated: 2022/10/17 18:40:00 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	indx_grup_h_a(int group, t_ps *ps)
{
	int	res;

	res = ps->len_a;
	while (res >= 0)
	{
		if (ps->stack_a[res].grp == group && ps->stack_a[res].is_high == 1)
			return (res);
		res--;
	}
	return (res);
}

int	indx_grup_h_b(int group, t_ps *ps)
{
	int	res;

	res = ps->len_b;
	while (res >= 0)
	{
		if (ps->stack_b[res].grp == group && ps->stack_b[res].is_high == 1)
			return (res);
		res--;
	}
	return (res);
}

int	indx_grup_l_a(int group, t_ps *ps)
{
	int	res;

	res = ps->len_a;
	while (res >= 0)
	{
		if (ps->stack_a[res].grp == group && ps->stack_a[res].is_low == 1)
			return (res);
		res--;
	}
	return (res);
}

int	indx_grup_l_b(int group, t_ps *ps)
{
	int	res;

	res = ps->len_b;
	while (res >= 0)
	{
		if (ps->stack_b[res].grp == group && ps->stack_b[res].is_low == 1)
			return (res);
		res--;
	}
	return (res);
}
