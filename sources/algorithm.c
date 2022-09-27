/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:03:24 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 03:20:03 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* This function sorts the numbers in the stacks by defining "groups" of */
/* numbers that are: greater than a half, lower than a half and greater */
/* than a quarter and lower than a quarter, between the maximum and minimum */
/* of a precedent group. Each group is sent to a convenient location in the */
/* stacks in order to split every group into smaller groups until its length */
/* is equal or lower than three, and then is easy to sort them in the right */
/* order in the stack a. */
void	kill_bitch(t_ps *ps)
{
	while (ps->grp_in_a > 0 || ps->grp_in_b > 0)
		split(find_next_number_group(ps), find_next_number_stack(ps), ps);
}

/* If c_stack is equal to one, this function takes the group passed as */
/* paramether in the stack a and send his numbers lowers than the middle to */
/* the stack b defining two news groups in that stack consisting of the lower */
/* and greather quarters of the original half of numbers, and repeats the */
/* process until the length of the group is equal or lower than three and */
/* then sort this remaning numbers. */
/*	If c_stack is equal to two the behavior is analogous except that the */
/* split is realized once. */
void	split(int group, int c_stack, t_ps *ps)
{
	if (c_stack == 1)
		split_a_b(group, ps);
	else if (c_stack == 2)
		split_b_a(group, ps);
}
