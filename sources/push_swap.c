/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 18:19:47 by faru          #+#    #+#                 */
/*   Updated: 2023/02/10 01:09:09 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	initialize_stack(argc, argv, &a);
	sort(&a);
	free_stack(&a);
	return (0);
}
