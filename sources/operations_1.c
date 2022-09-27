/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:01:58 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/13 11:57:20 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sa(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_a > 1)
	{
		curr = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = curr;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_b > 1)
	{
		curr = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = curr;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_ps *ps)
{
	t_lelem	curr;

	if (ps->len_a > 1)
	{
		curr = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = curr;
	}
	if (ps->len_b > 1)
	{
		curr = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = curr;
	}
	ft_putstr_fd("ss\n", 1);
}

void	pb(t_ps *ps)
{
	if (ps->len_a > 0)
	{
		ddb(ps);
		ps->stack_b[0] = ps->stack_a[0];
		dua(ps);
	}
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_ps *ps)
{
	if (ps->len_b > 0)
	{
		dda(ps);
		ps->stack_a[0] = ps->stack_b[0];
		dub(ps);
	}
	ft_putstr_fd("pa\n", 1);
}
