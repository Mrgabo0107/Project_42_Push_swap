/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:49:03 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 20:28:49 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rrr(t_ps *ps)
{
	if (ps->len_a > 1)
	{
		dda(ps);
		ps->stack_a[0] = ps->stack_a[ps->len_a];
		ps->stack_b[ps->len_a].number = 0;
		ps->stack_b[ps->len_a].c_stack = 0;
		ps->stack_b[ps->len_a].grp = 0;
		ps->stack_b[ps->len_a].is_high = 0;
		ps->stack_b[ps->len_a].is_low = 0;
		ps->len_a--;
	}
	if (ps->len_b > 1)
	{
		ddb(ps);
		ps->stack_b[0] = ps->stack_b[ps->len_b];
		ps->stack_b[ps->len_b].number = 0;
		ps->stack_b[ps->len_b].c_stack = 0;
		ps->stack_b[ps->len_b].grp = 0;
		ps->stack_b[ps->len_b].is_high = 0;
		ps->stack_b[ps->len_b].is_low = 0;
		ps->len_b--;
	}
	ft_putstr_fd("rrr\n", 1);
}

void	dda(t_ps *ps)
{
	int	i;

	i = ps->len_a;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->len_a++;
}

void	ddb(t_ps *ps)
{
	int	i;

	i = ps->len_b;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->len_b++;
}

void	dua(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len_a)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->len_a--;
}

void	dub(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len_b)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->len_b--;
}
