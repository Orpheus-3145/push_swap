/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_moves.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 03:19:11 by fra           #+#    #+#                 */
/*   Updated: 2023/02/04 20:36:20 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*first;
	t_stack	*third;

	if (! list || ! *list || ! (*list)->next)
		return ;
	first = *list;
	third = first->next->next;
	(*list) = first->next;
	(*list)->next = first;
	(*list)->next->next = third;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp_src;

	if (! *src)
		return ;
	tmp_src = *src;
	*src = (*src)->next;
	tmp_src->next = *dst;
	*dst = tmp_src;
}

void	rotate(t_stack **turn)
{
	t_stack	*last;
	t_stack	*curr;

	if (! turn || ! *turn || ! (*turn)->next)
		return ;
	else if (! (*turn)->next->next)
	{
		swap(turn);
		return ;
	}
	else
	{
		last = *turn;
		*turn = (*turn)->next;
		curr = *turn;
		while (curr->next)
			curr = curr->next;
		last->next = NULL;
		curr->next = last;
	}
}

void	reverse(t_stack **turn)
{
	t_stack	*second;
	t_stack	*first;
	t_stack	*last;

	if (! turn || ! *turn || ! (*turn)->next)
		return ;
	else if (! (*turn)->next->next)
	{
		swap(turn);
		return ;
	}
	else
	{
		second = *turn;
		first = *turn;
		while (first->next)
		{
			last = first;
			first = first->next;
		}
		first->next = second;
		last->next = NULL;
		*turn = first;
	}
}

void	perform_action(char *type, int times, t_stack **a, t_stack **b)
{
	while (times--)
	{
		if (type[0] == 'p')
			push(a, b);
		else if (type[0] == 's')
		{
			if (type[1] == 's')
				swap(b);
			swap(a);
		}
		else if (ft_strlen(type) == 3)
		{
			if (type[2] == 'r')
				reverse(b);
			reverse(a);
		}
		else
		{
			if (type[1] == 'r')
				rotate(b);
			rotate(a);
		}
		ft_printf("%s\n", type);
	}
}
