/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:51:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/10 15:02:29 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	if (validate_input(av + 1) == 0)
		return (1);
	stack_a = NULL;
	stack_a = init_stack_a(stack_a, av + 1);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}