/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:51:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/15 15:19:33 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	// t_stack *stack_b;
	t_op_counter	*count;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	if (validate_input(av + 1) == 0)
		return (1);
	stack_a = NULL;
	stack_a = init_stack_a(stack_a, av + 1);
	count = malloc(sizeof(t_op_counter *));
	if (!count)
		return (1);
	count->sa = 0;
	count->ra = 0;
	count->total = 0;
	// ft_putstr_fd("\nStack a:\n", 1);
	// print_stack(stack_a);
	// printf("In order: %d, stacklen: %d", in_order(stack_a), stack_len(stack_a));
	bubble_sort(&stack_a, count);
	// print_stack(stack_a);
	// ft_putstr_fd("\nStack b:\n", 1);
	// print_stack(stack_b);
	free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}