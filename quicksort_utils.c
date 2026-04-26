/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 16:39:00 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 16:48:49 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack *stack, int count)
{
	int	min;
	int	max;
	int	median;

	min = stack->index;
	max = stack->index;
	while (count--)
	{
		if (stack->index < min)
			min = stack->index;
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	median = (min + max) / 2;
	return (median);
}

void	run_operations_chain(t_stack **a, t_stack **b, char *operations)
{
	while (*operations)
	{
		if (!ft_strncmp(operations, "pa", 2))
			push(a, b);
		else if (!ft_strncmp(operations, "pb", 2))
			push(b, a);
		else if (!ft_strncmp(operations, "sa", 2))
			swap(a);
		else if (!ft_strncmp(operations, "sb", 2))
			swap(b);
		operations += 2;
	}
}

void	rotate_a(t_stack **stack_a, int rotated)
{
	while (rotated--)
		rev_rotate(stack_a);
}

void	rotate_b(t_stack **stack_b, int rotated)
{
	while (rotated--)
		rev_rotate(stack_b);
}

void	push_sorted_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (count--)
		push(stack_a, stack_b);
}
