/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:09:20 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/11 23:34:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	free_ps_exit(t_ps *ps)
{
	if (ps->stack_a)
		free(ps->stack_a);
	if (ps->stack_b)
		free(ps->stack_b);
	free(ps);
	exit(0);
}
