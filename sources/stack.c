/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 02:51:37 by fra           #+#    #+#                 */
/*   Updated: 2023/03/22 04:06:23 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(int argc, char **argv, t_stack **stk)
{
	int		status;
	int		free_argv;

	free_argv = 0;
	argc--;
	if (argc == 0)
		exit(0);
	else if (argc == 1)
	{
		argc = 0;
		argv = ft_split(argv[1], ' ');
		if (! argv || !argv[argc])
			raise_error("Error", NULL, 1);
		while (argv[argc])
			argc++;
		free_argv++;
	}
	else
		argv++;
	status = check_and_fill_stack(argc, argv, stk);
	if (free_argv)
		ft_free_double((void ***) &argv, argc);
	if (! status)
		raise_error("Error", NULL, 1);
}

void	free_stack(t_stack **lst)
{
	t_stack	*next;

	if (! lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

int	is_sorted(t_stack *stk)
{
	if (! stk || ! stk->next)
		return (1);
	while (stk->next)
	{
		if (stk->value > stk->next->value)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	n_nodes(t_stack *stk)
{
	int	cnt;

	cnt = 0;
	while (stk)
	{
		cnt++;
		stk = stk->next;
	}
	return (cnt);
}

int	append_node(int value, t_stack **stack)
{
	t_stack	*new_ele;

	new_ele = malloc(sizeof(t_stack));
	if (! new_ele)
	{
		free_stack(stack);
		return (0);
	}
	new_ele->value = value;
	new_ele->next = NULL;
	push(&new_ele, stack);
	return (1);
}
