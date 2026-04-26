/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:51:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 18:15:52 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	run_algorithm(t_stack **a, t_stack **b, int strategy, int bench)
{
	t_op_counter	count;

	(void)bench;
	init_counter(&count);
	count.disorder = compute_disorder(*a);
	if (strategy == SIMPLE)
		bubble_sort(a, &count);
	if (strategy == COMPLEX)
		quicksort_a(a, b, stack_size(*a), &count);
	bubble_sort(a, &count);
	if (bench)
		benchmark_mode(count, SIMPLE);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b = NULL;
	int		strategy;
	int		bench;
	int		offset;
	char	**args;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	offset = check_for_flags(av + 1, &strategy, &bench);
	if (ac == offset + 1)
		args = ft_split(av[offset], ' ');
	else
		args = av + offset;
	if (validate_input(args, ac - (offset + 1)) == 0)
		return (1);
	stack_a = NULL;
	stack_a = init_stack_a(stack_a, args);
	if (ac == offset + 1)
		free_arr(args);
	if (!index_stack(&stack_a))
		return (1);
	run_algorithm(&stack_a, &stack_b, strategy, bench);
	// print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}

