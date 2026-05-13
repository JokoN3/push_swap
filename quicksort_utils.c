/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 16:39:00 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/12 16:11:41 by yoneshev      ########   odam.nl         */
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

void	run_op_chain(t_stack **a, t_stack **b, char *ops, t_op_counter *counter)
{
	while (*ops)
	{
		if (!ft_strncmp(ops, "pa", 2))
			pa(a, b, counter);
		else if (!ft_strncmp(ops, "pb", 2))
			pb(a, b, counter);
		else if (!ft_strncmp(ops, "sa", 2))
			sa(a, counter);
		else if (!ft_strncmp(ops, "sb", 2))
			sb(b, counter);
		ops += 2;
	}
}

void	rotate_a(t_stack **a, int rotated, t_op_counter *counter)
{
	while (rotated--)
		rra(a, counter);
}

void	rotate_b(t_stack **stack_b, int rotated, t_op_counter *counter)
{
	while (rotated--)
		rrb(stack_b, counter);
}

void	push_sorted_to_a(t_stack **a, t_stack **b, int count, t_op_counter *c)
{
	while (count--)
		pa(a, b, c);
}
