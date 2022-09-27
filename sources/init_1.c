/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 04:11:30 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/23 17:08:28 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	init_ps(t_ps *ps, int ac, char **av)
{
	ps->stack_a = init_index(ps, ac, av);
	ps->stack_b = init_zero(ps->stack_b, ac);
	if (!ps->stack_a || !ps->stack_b)
		free_ps_exit(ps);
	ps->len_a = ac - 1;
	ps->len_b = 0;
	ps->grp_in_a = 1;
	ps->grp_in_b = 0;
	ps->elem_num = ac - 1;
}

t_lelem	*init_index(t_ps *ps, int ac, char **av)
{
	t_lelem	*res;
	int		ind_min;

	res = ps->stack_a;
	res = init_zero(res, ac);
	if (!res)
		return (NULL);
	ind_min = index_of_min(ac, av);
	res = fill_index(res, ind_min, ac, av);
	res[0].is_high = 1;
	res[ac - 2].is_low = 1;
	return (res);
}

t_lelem	*init_zero(t_lelem *stk, int ac)
{
	t_lelem	*res;
	int		i;

	res = stk;
	res = (t_lelem *)malloc(sizeof(t_lelem) * ac);
	if (!res)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res->number = 0;
		res->grp = 0;
		res->is_high = 0;
		res->is_low = 0;
		i++;
	}
	return (res);
}

int	index_of_min(int ac, char **av)
{
	int	i;
	int	index;
	int	min;

	index = 0;
	min = ft_atoi(av[1]);
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= min)
		{
			min = ft_atoi(av[i]);
			index = i - 1;
		}
	i++;
	}
	return (index);
}

/* This function indexes the input numbers giving the value one to the */
/* minimum number in the input and so on until asign the number of */
/* elements to the maximum value. */
t_lelem	*fill_index(t_lelem *a, int i_min, int ac, char **av)
{
	t_lelem	*res;
	int		curr_min;
	int		c_min_in;
	int		i;

	i = 1;
	res = a;
	curr_min = ft_atoi(av[i_min + 1]);
	c_min_in = i_min;
	while (i < ac)
	{
		res[c_min_in].number = i;
		res[c_min_in].grp = 1;
		res[c_min_in].c_stack = 1;
		res[c_min_in].is_high = 0;
		res[c_min_in].is_low = 0;
		c_min_in = next_min_in(curr_min, ac, av);
		curr_min = ft_atoi(av[c_min_in + 1]);
		i++;
	}
	return (res);
}
