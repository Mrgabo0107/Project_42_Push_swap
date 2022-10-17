/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:42:27 by gamoreno          #+#    #+#             */
/*   Updated: 2022/10/17 19:15:56 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	first_max(int c_min, int ac, char **av)
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > c_min)
		{
			res = i - 1;
			break ;
		}
		i++;
	}
	return (res);
}

int	next_min_in(int c_min, int ac, char **av)
{
	int	curr_max;
	int	i;
	int	j;

	i = 1;
	j = first_max(c_min, ac, av);
	curr_max = ft_atoi(av[j + 1]);
	while (i < ac)
	{
		if (ft_atoi(av[i]) > c_min && ft_atoi(av[i]) < curr_max)
		{
			curr_max = ft_atoi(av[i]);
			j = i - 1;
		}
		i++;
	}
	return (j);
}

int	check_good_init_order(t_ps	*ps)
{
	int	i;

	i = 0;
	while (i < ps->elem_num)
	{
		if (ps->stack_a[i].number != i + 1)
			return (0);
		i++;
	}
	return (i);
}
