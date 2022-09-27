/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a_to_b_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:26:48 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 20:27:19 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* See final_case_a */
void	final_case_a_3_1(t_ps *ps)
{
	ra(ps);
	sa(ps);
	rra(ps);
}

/* See final_case_a */
void	final_case_a_3_2(t_ps *ps)
{
	final_case_a_3_1(ps);
	sa(ps);
}

/* See final_case_a */
void	final_case_a_3_3(t_ps *ps)
{
	sa(ps);
	final_case_a_3_1(ps);
}

/* See final_case_a */
void	final_case_a_3_4(t_ps *ps)
{
	sa(ps);
	final_case_a_3_2(ps);
}
