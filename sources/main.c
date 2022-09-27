/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:41:28 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/11 23:35:18 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;

	if (ac > 1)
	{
		check_args(ac, av);
		ps = (t_ps *)malloc(sizeof(t_ps) * 1);
		if (!ps)
			exit(0);
		init_ps(ps, ac, av);
		kill_bitch(ps);
		free_ps_exit(ps);
	}
	return (0);
}
