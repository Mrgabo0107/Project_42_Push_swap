/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:48:55 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 20:29:17 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ra(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_a > 1)
	{
		curr = ps->stack_a[0];
		dua(ps);
		ps->stack_a[ps->len_a] = curr;
		ps->len_a++;
	}
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_b > 1)
	{
		curr = ps->stack_b[0];
		dub(ps);
		ps->stack_b[ps->len_b] = curr;
		ps->len_b++;
	}
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_a > 1)
	{
		curr = ps->stack_a[0];
		dua(ps);
		ps->stack_a[ps->len_a] = curr;
		ps->len_a++;
	}
	if (ps->len_b > 1)
	{
		curr = ps->stack_b[0];
		dub(ps);
		ps->stack_b[ps->len_b] = curr;
		ps->len_b++;
	}
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_ps *ps)
{
	if (ps->len_a > 1)
	{
		dda(ps);
		ps->stack_a[0] = ps->stack_a[ps->len_a - 1];
		ps->stack_a[ps->len_a - 1].number = 0;
		ps->stack_a[ps->len_a - 1].c_stack = 0;
		ps->stack_a[ps->len_a - 1].grp = 0;
		ps->stack_a[ps->len_a - 1].is_high = 0;
		ps->stack_a[ps->len_a - 1].is_low = 0;
		ps->len_a--;
	}
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_ps *ps)
{
	if (ps->len_b > 1)
	{
		ddb(ps);
		ps->stack_b[0] = ps->stack_b[ps->len_b - 1];
		ps->stack_b[ps->len_b - 1].number = 0;
		ps->stack_b[ps->len_b - 1].c_stack = 0;
		ps->stack_b[ps->len_b - 1].grp = 0;
		ps->stack_b[ps->len_b - 1].is_high = 0;
		ps->stack_b[ps->len_b - 1].is_low = 0;
		ps->len_b--;
	}
	ft_putstr_fd("rrb\n", 1);
}
