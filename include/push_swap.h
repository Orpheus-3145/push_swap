/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 15:37:34 by faru          #+#    #+#                 */
/*   Updated: 2023/02/08 03:41:55 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"

typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stack;

void	push(t_stack **from, t_stack **to);

void	swap(t_stack **stk);

void	rotate(t_stack **stk);

void	reverse(t_stack **stk);

void	perform_action(char *type, int times, t_stack **a, t_stack **b);

void	move_single_on_top(t_stack *element, t_stack **dst);

void	move_double_on_top(t_stack **src, t_stack **dst);

void	optimize(int *r_a, int *r_b, int len_a, int len_b);

void	merge(int n_rot_a, int n_rot_b, t_stack **src, t_stack **dst);

void	algo_turk(t_stack **a);

t_stack	*find_alpha(t_stack *to_check, t_stack *stk);

t_stack	*find_beta(t_stack *to_check, t_stack *stk);

t_stack	*find_best_man(t_stack *stk_a, t_stack *stk_b);

t_stack	*find_min(t_stack *stk);

t_stack	*find_max(t_stack *stk);

void	sort_three_ele(t_stack **stk);

void	sort_two_ele(t_stack **stk);

void	sort(t_stack **a);

int		get_r(int m1, int m2);

int		get_rr(int m1, int m2);

int		count_moves(int mv_a, int mv_b);

int		count_rot_on_top(t_stack *element, t_stack *stk);

void	initialize_stack(int argc, char **argv, t_stack **stk);

void	free_stack(t_stack **lst);

int		append_node(int value, t_stack **stack);

int		is_sorted(t_stack *stk);

int		n_nodes(t_stack *stk);

int		check_char_num(char *char_num);

int		check_and_fill_stack(int argc, char **argv, t_stack **stk);

int		check_triple(t_stack *stk);

#endif