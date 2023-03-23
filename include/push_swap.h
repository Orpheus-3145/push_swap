/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 15:37:34 by faru          #+#    #+#                 */
/*   Updated: 2023/03/23 03:20:46 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"

// implementation of a linked list
// @p value	-> value of node
// @param next	-> reference for next element in list
typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stack;

// performs swap operation on stack
// @param stk	-> stack to modify
//
// @return void
void	swap(t_stack **stk);

// performs push operation on stack to
// @param stk	-> stack to modify
//
// @return void
void	push(t_stack **from, t_stack **to);

// performs rotate operation on stack
// @param stk	-> stack to modify
//
// @return void
void	rotate(t_stack **stk);

// performs reverse rotate operation on stack
// @param stk	-> stack to modify
//
// @return void
void	reverse(t_stack **stk);

// executes times 'times' the operation associated to type on
// stack a and/or b
// @param type	-> nome of the operation to perform
// @param times	-> number of times to execute the action
// @param a		-> main stack
// @param b		-> auxiliary stack
//
// @return void
void	perform_action(char *type, int times, t_stack **a, t_stack **b);

// puts the node element on top of stack dst
// @param element	-> node to move
// @param dst		-> stack to look for (and put on top) the first parameter
//
// @return void
void	move_single_on_top(t_stack *element, t_stack **dst);

// puts of on top of each stack the next couple of elements that requires less
// moves
// @param src	-> stack to look for the best_man (TM)
// @pram dst	-> stack to be pushed with the best_man
//
// @return void
void	move_double_on_top(t_stack **src, t_stack **dst);

// does some checking to find if is possibile to merge some situations
// of rot(a) + rot(b) into rrot() (same for reverse)
// @param r_a	-> this variable is going to be updated with the best number
//				of rotations (positive)/rev. rotations (negative) to do on a
// @param r_b	-> this variable is going to be updated with the best number
//				of rotations (positive)/rev. rotations (negative) to do on b
// @param len_a	-> number of elements of stack a
// @param len_b	-> number of elements of stack b
//
// @return void
void	optimize(int *r_a, int *r_b, int len_a, int len_b);

// if the moves to perform on a and b are the same (i.e. both rotations or rev.
// rotations) it merges them as much as possible with the formula:
//	Mov(r(a) + r(b)) > Mov(min(r(a),r(b)) + [max(r(a),r(b)) - min(r(a),r(b))])
// @param n_rot_a	-> number of rot/rev.rot to do on a
// @param n_rot_b	-> number of rot/rev.rot to do on b
// @param src		--> stack a
// @param dst		--> stack b
//
// @return void
void	merge(int n_rot_a, int n_rot_b, t_stack **src, t_stack **dst);

// for stack greater than the three elements applies the turk algorithm to sort
// stack a
// @param a	-> stack to sort
//
// @return void
void	algo_turk(t_stack **a);

// finds the biggest element in stack stk smaller than to_check (sup)
// alpha > i, for every i belonging to stk && i < alpha < to_check
// @param to_check	-> maximum element
// @param stk		-> stack in which search for alpha
//
// @return t_stack*	-> alpha aka sup
t_stack	*find_alpha(t_stack *to_check, t_stack *stk);

// finds the smallest element in stack stk bigger than to_check (inf)
// beta < i, for every i belonging to stk && i > beta > to_check
// @param to_check	-> minimum element
// @param stk		-> stack in which search for beta
//
// @return t_stack*	-> beta aka inf
t_stack	*find_beta(t_stack *to_check, t_stack *stk);

// the best_man is the element of stack a that requires less moves top his
// linked alpha (aka the biggest element of stack b smaller than the best_man)
// on top of b and itself on top of stack a
// @param stk_a	-> stack in which search for the best_man
// @param stk_b	-> stack in which search for the linked alpha
t_stack	*find_best_man(t_stack *stk_a, t_stack *stk_b);

// finds the minimum element of stack
// @param stk		-> stack to inspect
//
// @return t_stack*	-> minimum node
t_stack	*find_min(t_stack *stk);

// finds the maximum element of stack
// @param stk		-> stack to inspect
//
// @return t_stack*	-> maximum node
t_stack	*find_max(t_stack *stk);

// sorts a stack of three elements, because such stack requires at most
// 2 moves, every possible combination (5 = 6-1 [already sorted]) is hardcoded
// @param stk	-> stack to sort
//
// return void
void	sort_three_ele(t_stack **stk);

// sorts a stack of two elements: they're either sorted or a swap op. is enough
// to complete the job
// @param stk	-> stack to sort
//
// return void
void	sort_two_ele(t_stack **stk);

// sorts a stack
// @param stk	-> stack to sort
//
// return void
void	sort(t_stack **a);

// having rot/rev. rot on both stacks, it finds the number of single
// rot/rev. rot to do along with double rot/rev. rot:
// [max(r(a),r(b)) - min(r(a),r(b))]
// @param m1	-> rot/rev. rot on stack a
// @param m2	-> rot/rev. rot on stack b
int		get_r(int m1, int m2);

// having rot/rev. rot on both stacks, it finds the number of double
// rot/rev. rot to perform: min(r(a),r(b))
// @param m1	-> rot/rev. rot on stack a
// @param m2	-> rot/rev. rot on stack b
int		get_rr(int m1, int m2);

// gets the final amount of rot/rev. rot and, if present the doubles,
// @param mv_a	-> rot/rev. rot to do on a
// @param mv_b	-> rot/rev. rot to do on b
//
// @return int	-> gives back the total rot/rev. rot to apply on a + b
int		count_moves(int mv_a, int mv_b);

// counts a row numbers of rotations to put the node element
// on top of stack stk (nb only rotations, i.e. doesn't give
// rev. rotations the the count goes over the half of the stack)
// @param element	-> element to put on top
// @param stk		-> stack to be modified
//
// @return int		-> number of rotations
int		count_rot_on_top(t_stack *element, t_stack *stk);


// checks if the input is one (i.e. the list is inside
// double quotes) or more than one (no double quotes), then it
// creates the stack 
// @param argc	-> number of nodes + 1
// @param argv	-> elements to be parsed
// @prama stk	-> stack to fill
//
// @return void	(errors occurred during parsing or memory related terminate the
// 				program and print 'Error' n stderr
void	initialize_stack(int argc, char **argv, t_stack **stk);

// deallocates every element of the stack
// @param lst	-> linked list to free
//
// @return void
void	free_stack(t_stack **lst);

// created a node with 'value ' value and pushed is into stack
// @param value	-> value of the node
// @param stack	-> stack to be pushed
//
// @return int 	-> true (false for memory failures)
int		append_node(int value, t_stack **stack);

// checks if the stack is sorted
// @param stk	-> stack to inspect
//
// @return int	true/false
int		is_sorted(t_stack *stk);

// counts the number of element of stk
// @param stk	-> stack to inspect
//
// @return int	-> counter
int		n_nodes(t_stack *stk);

// checks if the string char_num represents a valid integer number 
// @param stk	-> stack to inspect
//
// @return int	true/false
int		check_char_num(char *char_num);

// fills stk with the values received in input creating a node
// for each one of them, every node is going to be pushed inside the stack
// @param argc	-> number of nodes
// @param argv	-> elements to be parsed
// @prama stk	-> stack to fill
//
// @return int	true/false
int		check_and_fill_stack(int argc, char **argv, t_stack **stk);

// for three element stacks, finds which one of the possibile 6 combinations is
// the one that represents the tk
// @param stk	-> stack to inspect
//
// @return int	-> number from 0 to 5
int		check_triple(t_stack *stk);

// [bonus]
// saves the action received from stdin inside a double dimension array
// @param actions	-> 2d array to initialize
// @input input		-> string formatted as: "action1|action2|...|action2"
//
// @return int 	-> true (false for memory failures)
int		store_actions(char **actions, char *input);

// [bonus]
// checks if every action is avalid name, i.e. 'pa', 'ss', ...
// @param action	-> action to check
//
// @return int	true/false
int		check_action(char *action);

// [bonus]
// executes every action parsed inside the 2d array on stack a
// @param actions	-> list of operation
// @pram a			-> stack to perform the actions
//
// @return void
void	run_actions(char **actions, t_stack **a);

// [bonus]
// saves the actions from stdin (store_action()) and checks them
// (check_action()) and then it tries to execute the operations
// (run_actions())
//
// @return void
void	test_actions(t_stack **stk_a);

#endif