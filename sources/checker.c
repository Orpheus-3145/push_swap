/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 18:19:47 by faru          #+#    #+#                 */
/*   Updated: 2023/03/22 04:11:50 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	initialize_stack(argc, argv, &a);
	test_actions(&a);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	return (0);
}
