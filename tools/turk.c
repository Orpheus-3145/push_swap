/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turk.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 22:48:46 by fra           #+#    #+#                 */
/*   Updated: 2023/02/06 21:19:07 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_single_on_top(t_stack *element, t_stack **dst)
{
	int	n_rot_a;
	int	tot_elements;

	tot_elements = n_nodes(*dst);
	n_rot_a = count_rot_on_top(element, *dst);
	if (n_rot_a > (tot_elements / 2))
		perform_action("rra", ft_mod(n_rot_a - tot_elements), dst, NULL);
	else
		perform_action("ra", ft_mod(n_rot_a), dst, NULL);
}

void	move_double_on_top(t_stack **src, t_stack **dst)
{
	char	*stk_1;
	char	*stk_2;
	int		n_rot_a;
	int		n_rot_b;
	t_stack	*best_man;

	best_man = find_best_man(*src, *dst);
	n_rot_a = count_rot_on_top(best_man, *src);
	n_rot_b = count_rot_on_top(find_alpha(best_man, *dst), *dst);
	optimize(&n_rot_a, &n_rot_b, n_nodes(*src), n_nodes(*dst));
	if (n_rot_a * n_rot_b > 0)
		merge(n_rot_a, n_rot_b, src, dst);
	else
	{
		stk_1 = "ra";
		stk_2 = "rb";
		if (n_rot_a < 0)
			stk_1 = "rra";
		else if (n_rot_b < 0)
			stk_2 = "rrb";
		perform_action(stk_1, ft_mod(n_rot_a), src, NULL);
		perform_action(stk_2, ft_mod(n_rot_b), dst, NULL);
	}
}

void	optimize(int *r_a, int *r_b, int len_a, int len_b)
{
	int	t1;
	int	t2;
	int	t3;
	int	t4;

	t1 = get_r(*r_a, *r_b) + get_rr(*r_a, *r_b);
	t2 = *r_a + ft_mod(*r_b - len_b);
	t3 = ft_mod(*r_a - len_a) + *r_b;
	t4 = get_r(*r_a - len_a, *r_b - len_b) + get_rr(*r_a - len_a, *r_b - len_b);
	if (t2 <= t1 && t2 <= t3 && t2 <= t4)
		*r_b -= len_b;
	else if (t3 <= t1 && t3 <= t2 && t3 <= t4)
		*r_a -= len_a;
	else if (t4 <= t1 && t4 <= t2 && t4 <= t3)
	{
		*r_a -= len_a;
		*r_b -= len_b;
	}
}

void	merge(int n_rot_a, int n_rot_b, t_stack **src, t_stack **dst)
{
	if (n_rot_a > 0 && n_rot_b > 0)
	{
		perform_action("rr", get_rr(n_rot_a, n_rot_b), src, dst);
		if (n_rot_a > n_rot_b)
			perform_action("ra", get_r(n_rot_a, n_rot_b), src, NULL);
		else
			perform_action("rb", get_r(n_rot_a, n_rot_b), dst, NULL);
	}
	else if (n_rot_a < 0 && n_rot_b < 0)
	{
		perform_action("rrr", get_rr(n_rot_a, n_rot_b), src, dst);
		if (n_rot_b > n_rot_a)
			perform_action("rra", get_r(n_rot_a, n_rot_b), src, NULL);
		else
			perform_action("rrb", get_r(n_rot_a, n_rot_b), dst, NULL);
	}
}

void	algo_turk(t_stack **a)
{
	t_stack	*b;
	int		first_two;

	b = NULL;
	first_two = 2;
	while (n_nodes(*a) > 3)
	{
		if (first_two)
			first_two--;
		else
			move_double_on_top(a, &b);
		perform_action("pb", 1, a, &b);
	}
	sort_three_ele(a);
	while (b)
	{
		move_single_on_top(find_beta(b, *a), a);
		perform_action("pa", 1, &b, a);
	}
	move_single_on_top(find_min(*a), a);
}
