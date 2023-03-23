/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finder.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 02:51:37 by fra           #+#    #+#                 */
/*   Updated: 2023/03/23 02:48:09 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_alpha(t_stack *to_check, t_stack *stk)
{
	t_stack	*sup;
	int		max;

	sup = NULL;
	max = to_check->value;
	if (max > find_max(stk)->value || max < find_min(stk)->value)
		return (find_max(stk));
	while (stk)
	{
		if (! sup && stk->value < max)
			sup = stk;
		if (sup && sup->value < stk->value && stk->value < max)
			sup = stk;
		stk = stk->next;
	}
	return (sup);
}

t_stack	*find_beta(t_stack *to_check, t_stack *stk)
{
	t_stack	*inf;
	t_stack	*tmp;
	int		min;

	inf = NULL;
	tmp = stk;
	min = to_check->value;
	while (tmp)
	{
		if (! inf && tmp->value > min)
			inf = tmp;
		if (inf && tmp->value > min && inf->value > tmp->value)
			inf = tmp;
		tmp = tmp->next;
	}
	if (! inf)
		return (find_min(stk));
	else
		return (inf);
}

t_stack	*find_min(t_stack *stk)
{
	t_stack	*min;

	min = NULL;
	while (stk)
	{
		if (! min || min->value > stk->value)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stk)
{
	t_stack	*max;

	max = NULL;
	while (stk)
	{
		if (! max || max->value < stk->value)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

t_stack	*find_best_man(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*best_man;
	t_stack	*tmp;
	int		moves_a;
	int		moves_b;
	int		best_moves;

	tmp = stk_a;
	best_moves = 0;
	while (tmp)
	{
		moves_a = count_rot_on_top(tmp, stk_a);
		moves_b = count_rot_on_top(find_alpha(tmp, stk_b), stk_b);
		optimize(&moves_a, &moves_b, n_nodes(stk_a), n_nodes(stk_b));
		if (count_moves(moves_a, moves_b) < 2)
			return (tmp);
		else if (! best_moves || best_moves > count_moves(moves_a, moves_b))
		{
			best_man = tmp;
			best_moves = count_moves(moves_a, moves_b);
		}
		tmp = tmp->next;
	}
	return (best_man);
}
