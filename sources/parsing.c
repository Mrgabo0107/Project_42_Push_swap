/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:09:40 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/10 03:43:14 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	check_args(int ac, char **av)
{
	is_int(ac, av);
	fits_int(ac, av);
	no_repet(ac, av);
}

void	is_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	fits_int(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (av[i][0] == '-')
			len--;
		if (len > 10)
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
		else if (len == 10)
			fits_max_int(av[i]);
		i++;
	}
}

void	no_repet(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
			j++;
		}
	i++;
	}
}

void	fits_max_int(char *s)
{
	long int	p;

	p = ft_atoli(s);
	if (p < -2147483648 || 2147483647 < p)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
}
