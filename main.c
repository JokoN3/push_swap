/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:51:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 17:47:04 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_algorithm(t_stack **a, t_stack **b, int strategy, int bench)
{
	t_op_counter	count;

	init_counter(&count);
	if (!strategy)
		strategy = ADAPTIVE;
	if (stack_size(*a) == 1)
		count.disorder = 0;
	else
		count.disorder = compute_disorder(*a);
	if (in_order(*a))
	{
		if (bench)
			benchmark_mode(count, strategy);
		return ;
	}
	if (strategy == SIMPLE)
		cocktail_sort(a, &count, stack_size(*a));
	else if (strategy == COMPLEX)
		slinky_a(a, b, stack_size(*a), &count);
	else if (strategy == MEDIUM)
		messy_room_sort(a, b, &count);
	else if (strategy == ADAPTIVE)
		adaptive(a, b, &count);
	if (bench)
		benchmark_mode(count, strategy);
}

int	get_offset(int ac, char **av, int *strategy, int *bench)
{
	int	offset;

	if (ac == 1)
		exit(0);
	offset = check_for_flags(av + 1, strategy, bench);
	return (offset);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_params	pr;
	char		**args;

	stack_b = NULL;
	pr.offset = get_offset(ac, av, &pr.strategy, &pr.bench);
	if (ac == pr.offset + 1)
		args = ft_split(av[pr.offset], ' ');
	else
		args = av + pr.offset;
	if (validate_input(args, ac - (pr.offset + 1)) == 0)
		return (1);
	stack_a = NULL;
	stack_a = init_stack_a(stack_a, args);
	if (ac == pr.offset + 1)
		free_arr(args);
	if (!index_stack(&stack_a))
		return (1);
	run_algorithm(&stack_a, &stack_b, pr.strategy, pr.bench);
	free_stack(stack_a);
	return (0);
}
