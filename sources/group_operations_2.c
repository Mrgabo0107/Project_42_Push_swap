/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:49:42 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 19:49:43 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* see len_group */
int	len_gr_a(int group, t_ps *ps)
{
	int	res;

	res = 1;
	if (indx_grup_h(group, 1, ps) < indx_grup_l(group, 1, ps))
		res += indx_grup_l(group, 1, ps) - indx_grup_h(group, 1, ps);
	else if (indx_grup_h(group, 1, ps) > indx_grup_l(group, 1, ps))
		res += indx_grup_l(group, 1, ps)
			+ (ps->len_a - indx_grup_h(group, 1, ps));
	return (res);
}

/* see len_group */
int	len_gr_b(int group, t_ps *ps)
{
	int	res;

	res = 1;
	if (indx_grup_h(group, 2, ps) < indx_grup_l(group, 2, ps))
		res += indx_grup_l(group, 2, ps) - indx_grup_h(group, 2, ps);
	else if (indx_grup_h(group, 2, ps) > indx_grup_l(group, 2, ps))
		res += indx_grup_l(group, 2, ps)
			+ (ps->len_b - indx_grup_h(group, 2, ps));
	return (res);
}
