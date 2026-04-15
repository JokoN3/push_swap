/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:51:18 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/15 16:58:50 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_op_counter *count)
{
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->total = 0;
}

void	run_algorithm(t_stack **stack_a, int strategy, int bench)
{
	t_op_counter	count;

	(void)bench;
	init_counter(&count);
	if (strategy == SIMPLE)
		bubble_sort(stack_a, &count);
	bubble_sort(stack_a, &count);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
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
	run_algorithm(&stack_a, strategy, bench);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
