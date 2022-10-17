/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:44:49 by gamoreno          #+#    #+#             */
/*   Updated: 2022/09/27 02:33:17 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_lelem
{
	int	number;
	int	grp;
	int	is_high;
	int	is_low;
	int	c_stack;
}	t_lelem;

typedef struct s_ps
{
	t_lelem	*stack_a;
	t_lelem	*stack_b;
	int		len_a;
	int		len_b;
	int		grp_in_a;
	int		grp_in_b;
	int		elem_num;

}	t_ps;

/*--------------------parsing------------------*/

void	check_args(int ac, char **av);
void	is_int(int ac, char **av);
void	fits_int(int ac, char **av);
void	fits_max_int(char *s);
void	no_repet(int ac, char **av);

/*--------------------init---------------------*/

void	init_ps(t_ps *ps, int ac, char **av);
t_lelem	*init_index(t_ps *ps, int ac, char **av);
t_lelem	*init_zero(t_lelem *stk, int ac);
t_lelem	*fill_index(t_lelem *a, int i_min, int ac, char **av);
int		index_of_min(int ac, char **av);
int		next_min_in(int c_min, int ac, char **av);
int		first_max(int c_min, int ac, char **av);
int		check_good_init_order(t_ps	*ps);

/*-----------------------error-----------------*/

void	free_ps_exit(t_ps *ps);

/*-------------------operations----------------*/

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pb(t_ps *ps);
void	pa(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	dda(t_ps *ps);
void	ddb(t_ps *ps);
void	dub(t_ps *ps);
void	dua(t_ps *ps);

/*-----------------------algorithm--------------------*/

void	kill_bitch(t_ps *ps);
void	split(int group, int c_stack, t_ps *ps);

/*------------------split_from_a_to_b-----------------*/

void	split_a_b(int group, t_ps *ps);
void	one_split_a_to_b(int group, t_ps *ps);
void	one_split_a_b_high(int group, t_ps *ps);
void	one_split_a_b_low(int group, t_ps *ps);
void	medium_a_b(int group, t_ps *ps, int min, int max);
void	medium_a_b_case1(int group, t_ps *ps, int min, int max);
void	medium_a_b_case2_1(int group, t_ps *ps);
void	medium_a_b_case2_2(int group, t_ps *ps, int min, int max);
void	small_a_b(int group, t_ps *ps);
void	small_a_b_case1(int group, t_ps *ps);
void	small_a_b_case2(int group, t_ps *ps);
void	final_case_a(int group, t_ps *ps);
void	final_case_a_1(int group, t_ps *ps);
void	final_case_a_2(int group, t_ps *ps);
void	final_case_a_3(int group, t_ps *ps);
void	final_case_a_3_1(t_ps *ps);
void	final_case_a_3_2(t_ps *ps);
void	final_case_a_3_3(t_ps *ps);
void	final_case_a_3_4(t_ps *ps);

/*---------------split_from_b_to_a-------------------*/

void	split_b_a(int group, t_ps *ps);
void	one_split_b_to_a(int group, t_ps *ps);
void	one_split_b_a_high(int group, t_ps *ps);
void	one_split_b_a_low(int group, t_ps *ps);
void	big_b_a(int group, t_ps *ps);
void	big_b_a_case1(int group, t_ps *ps);
void	big_b_a_case2(int group, t_ps *ps);
void	medium_b_a(int group, t_ps *ps);
void	medium_b_a_case1(int group, t_ps *ps);
void	medium_b_a_case2(int group, t_ps *ps);
void	final_case_b(int group, t_ps *ps);
void	final_case_b_1(int group, t_ps *ps);
void	final_case_b_2(int group, t_ps *ps);
void	final_case_b_3(int group, t_ps *ps);
void	final_case_b_3_1(t_ps *ps);
void	final_case_b_3_2(t_ps *ps);
void	final_case_b_3_3(t_ps *ps);
void	final_case_b_3_4(t_ps *ps);
void	final_case_b_3_5(t_ps *ps);
void	final_case_b_3_6(t_ps *ps);

/*-----------------split_helpers------------------*/

void	low_grade_a(t_ps *ps);
void	set_zero(int group, int c_stack, t_ps *ps);
void	set_zero_case_a(int group, t_ps *ps);
void	set_zero_case_b(int group, t_ps *ps);
int		find_next_number(t_ps *ps);
int		find_next_number_group(t_ps *ps);
int		find_next_number_stack(t_ps *ps);
int		check_less_than_half(int group, int midle, int c_stack, t_ps *ps);
int		check_more_than_three_quarters(int group,
			int middle, int c_stack, t_ps *ps);

/*-------------------group_operations-----------------*/

int		indx_grup_h(int group, int c_stack, t_ps *ps);
int		indx_grup_l(int group, int c_stack, t_ps *ps);
int		grup_max(int group, int c_stack, t_ps *ps);
int		grup_min(int group, int c_stack, t_ps *ps);
int		len_grup(int group, int c_stack, t_ps *ps);
int		len_gr_a(int group, t_ps *ps);
int		len_gr_b(int group, t_ps *ps);
int		indx_grup_h_a(int group, t_ps *ps);
int		indx_grup_h_b(int group, t_ps *ps);
int		indx_grup_l_a(int group, t_ps *ps);
int		indx_grup_l_b(int group, t_ps *ps);

/*-----------------attracts----------------------*/

int		to_attract_low(int group, int c_stack, t_ps *ps);
int		to_attract_high(int group, int c_stack, t_ps *ps);
void	attract_low(int group, int c_stack, t_ps *ps);
void	attract_high(int group, int c_stack, t_ps *ps);
void	attract_down(int steps, int c_stack, t_ps *ps);
void	attract_up(int steps, int c_stack, t_ps *ps);
void	attract_near(int group, int c_stack, t_ps *ps);

#endif
