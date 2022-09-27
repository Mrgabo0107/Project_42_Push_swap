/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b_to_a_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:53:07 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:20:40 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See final_case_b */
void	final_case_b_3_2(t_ps *ps)
{
	pa(ps);
	sb(ps);
	pa(ps);
	pa(ps);
}

/* See final_case_b */
void	final_case_b_3_3(t_ps *ps)
{
	rb(ps);
	sb(ps);
	pa(ps);
	rrb(ps);
	pa(ps);
	pa(ps);
}

/* See final_case_b */
void	final_case_b_3_4(t_ps *ps)
{
	sb(ps);
	final_case_b_3_1(ps);
}

/* See final_case_b */
void	final_case_b_3_5(t_ps *ps)
{
	rb(ps);
	sb(ps);
	if (len_grup (ps->grp_in_b, 2, ps) == 3)
		final_case_b_3_1(ps);
	else
	{
		pa(ps);
		pa(ps);
		rrb(ps);
		pa(ps);
	}
}

/* See final_case_b */
void	final_case_b_3_6(t_ps *ps)
{
	rb(ps);
	if (len_grup (ps->grp_in_b, 2, ps) == 3)
		final_case_b_3_1(ps);
	else
	{
		pa(ps);
		pa(ps);
		rrb(ps);
		pa(ps);
	}
}
