/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 13:42:50 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 16:51:47 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *stack_a;
	n2 = (*stack_a)->next;
	n3 = (*stack_a)->next->next;
	if (n1->index < n2->index && n1->index < n2->index && n2->index < n3->index)
		return ;
	if (n1->index < n2->index && n1->index < n3->index)
		run_operations_chain(stack_a, stack_b, "pbsapa");
	else if (n1->index > n2->index && n1->index > n3->index)
	{
		if (n2->index > n3->index)
			run_operations_chain(stack_a, stack_b, "sapbsapasa");
		else
			run_operations_chain(stack_a, stack_b, "sapbsapa");
	}
	else if (n1->index > n2->index)
		swap(stack_a);
	else
		run_operations_chain(stack_a, stack_b, "pbsapasa");
}

void	sort_three_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *stack_b;
	n2 = (*stack_b)->next;
	n3 = (*stack_b)->next->next;
	if (n1->index > n2->index && n1->index > n2->index && n2->index > n3->index)
		return ;
	if (n1->index > n2->index && n1->index > n3->index)
		run_operations_chain(stack_a, stack_b, "pasbpb");
	else if (n1->index < n2->index && n1->index < n3->index)
	{
		if (n2->index < n3->index)
			run_operations_chain(stack_a, stack_b, "sbpasbpbsb");
		else
			run_operations_chain(stack_a, stack_b, "sbpasbpb");
	}
	else if (n1->index < n2->index)
		swap(stack_b);
	else
		run_operations_chain(stack_a, stack_b, "pasbpbsb");
}

void	sort_three_on_top(t_stack **a, t_stack **b, char ab, int count)
{
	if (ab == 'a')
	{
		if (count < 3)
		{
			if ((*a)->index > (*a)->next->index)
				swap(a);
		}
		else
			sort_three_in_a(a, b);
	}
	else
	{
		if (count < 3)
		{
			if ((*b)->index < (*b)->next->index)
				swap(b);
		}
		else
			sort_three_in_b(a, b);
		push_sorted_to_a(a, b, count);
	}
}

void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	median;
	int	pushed;
	int	rotated;

	rotated = 0;
	pushed = 0;
	if (count <= 3)
		return (sort_three_on_top(stack_a, stack_b, 'a', count));
	median = find_median(*stack_a, count);
	while (count--)
	{
		if ((*stack_a)->index < median)
		{
			push(stack_b, stack_a);
			pushed++;
		}
		else
		{
			rotate(stack_a);
			rotated++;
		}
	}
	rotate_a(stack_a, rotated);
	quicksort_a(stack_a, stack_b, rotated);
	quicksort_b(stack_a, stack_b, pushed);
}

void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	median;
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	if (count <= 3)
		return (sort_three_on_top(stack_a, stack_b, 'b', count));
	median = find_median(*stack_b, count);
	while (count--)
	{
		if ((*stack_b)->index > median)
		{
			push(stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate(stack_b);
			rotated++;
		}
	}
	rotate_b(stack_b, rotated);
	quicksort_a(stack_a, stack_b, pushed);
	quicksort_b(stack_a, stack_b, rotated);
}
