/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 13:42:50 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 16:17:11 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *stack_a;
	node2 = (*stack_a)->next;
	node3 = (*stack_a)->next->next;
	if (node1->index < node2->index && node1->index < node2->index && node2->index < node3->index)
		return ;
	if (node1->index < node2->index && node1->index < node3->index)
	{
		push(stack_b, stack_a);
		swap(stack_a);
		push(stack_a, stack_b);
	}
	else if (node1->index > node2->index && node1->index > node3->index)
	{
		if (node2->index > node3->index)
		{
			swap(stack_a);
			push(stack_b, stack_a);
			swap(stack_a);
			push(stack_a, stack_b);
			swap(stack_a);
		}
		else
		{
			swap(stack_a);
			push(stack_b, stack_a);
			swap(stack_a);
			push(stack_a, stack_b);
		}
	}
	else if (node1->index > node2->index)
		swap(stack_a);
	else
	{
		push(stack_b, stack_a);
		swap(stack_a);
		push(stack_a, stack_b);
		swap(stack_a);
	}
}

void	sort_three_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *stack_b;
	node2 = (*stack_b)->next;
	node3 = (*stack_b)->next->next;
	if (node1->index > node2->index && node1->index > node2->index && node2->index > node3->index)
		return ;
	if (node1->index > node2->index && node1->index > node3->index)
	{
		push(stack_a, stack_b);
		swap(stack_b);
		push(stack_b, stack_a);
	}
	else if (node1->index < node2->index && node1->index < node3->index)
	{
		if (node2->index < node3->index)
		{
			swap(stack_b);
			push(stack_a, stack_b);
			swap(stack_b);
			push(stack_b, stack_a);
			swap(stack_b);
		}
		else
		{
			swap(stack_b);
			push(stack_a, stack_b);
			swap(stack_b);
			push(stack_b, stack_a);
		}
	}
	else if (node1->index < node2->index)
		swap(stack_b);
	else
	{
		push(stack_a, stack_b);
		swap(stack_b);
		push(stack_b, stack_a);
		swap(stack_b);
	}
}

void	push_sorted_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	while (count--)
	{
		push(stack_a, stack_b);
	}
}

void	sort_three_on_top(t_stack **stack_a, t_stack **stack_b, char ab, int count)
{
	if (ab == 'a')
	{
		if (count < 3)
		{
			if ((*stack_a)->index > (*stack_a)->next->index)
				swap(stack_a);
		}
		else
			sort_three_in_a(stack_a, stack_b);
	}
	else
	{
		if (count < 3)
		{
			if ((*stack_b)->index < (*stack_b)->next->index)
				swap(stack_b);
		}
		else
			sort_three_in_b(stack_a, stack_b);
		push_sorted_to_a(stack_a, stack_b, count);
	}
}

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

void	rotate_a(t_stack **stack_a, int rotated)
{
	while (rotated--)
		rev_rotate(stack_a);
}

void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	median;
	int	pushed;
	int	rotated;

	rotated = 0;
	pushed = 0;
	if (count <= 3)
	{
		// sort_three_in_a(stack_a, stack_b);
		sort_three_on_top(stack_a, stack_b, 'a', count);
		return ;
	}
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
	// print_stack(*stack_a);
	// printf("\n\n--------------------------------------------------------\n\n");
	quicksort_a(stack_a, stack_b, rotated);
	quicksort_b(stack_a, stack_b, pushed);
}

void	rotate_b(t_stack **stack_b, int rotated)
{
	while (rotated--)
		rev_rotate(stack_b);
}

void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	median;
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	if (count <= 3)
	{
		sort_three_on_top(stack_a, stack_b, 'b', count);
		// sort_three_in_b(stack_a, stack_b);
		return ;
	}
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
	// print_stack(*stack_b);
	// printf("\n\n--------------------------------------------------------\n\n");
	quicksort_a(stack_a, stack_b, pushed);
	quicksort_b(stack_a, stack_b, rotated);
}
