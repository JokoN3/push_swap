/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 13:42:50 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/08 13:33:18 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_a(t_stack **a, t_stack **b, t_op_counter *counter)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *a;
	n2 = (*a)->next;
	n3 = (*a)->next->next;
	if (n1->index < n2->index && n1->index < n2->index && n2->index < n3->index)
		return ;
	if (n1->index < n2->index && n1->index < n3->index)
		run_op_chain(a, b, "pbsapa", counter);
	else if (n1->index > n2->index && n1->index > n3->index)
	{
		if (n2->index > n3->index)
			run_op_chain(a, b, "sapbsapasa", counter);
		else
			run_op_chain(a, b, "sapbsapa", counter);
	}
	else if (n1->index > n2->index)
		sa(a, counter);
	else
		run_op_chain(a, b, "pbsapasa", counter);
}

void	sort_three_in_b(t_stack **a, t_stack **b, t_op_counter *counter)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *b;
	n2 = (*b)->next;
	n3 = (*b)->next->next;
	if (n1->index > n2->index && n1->index > n2->index && n2->index > n3->index) // 3 2 1
		run_op_chain(a, b, "papapa", counter);
	else if (n1->index > n2->index && n1->index > n3->index) // 3 1 2
		run_op_chain(a, b, "pasbpapa", counter);
	else if (n1->index < n2->index && n1->index < n3->index) //1 x x
	{
		if (n2->index < n3->index) //1 2 3
			run_op_chain(a, b, "sbpasbpasapa", counter);
		else // 1 3 2
			run_op_chain(a, b, "sbpasbpapa", counter);
	}
	else if (n1->index > n2->index) //2 1 3
		run_op_chain(a, b, "pasbpasapa", counter);	
	// sb(b, counter);
	else // 2 3 1
		run_op_chain(a, b, "sbpapapa", counter);
}

void	quicksort_a(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	int	median;
	int	pushed;
	int	rotated;

	rotated = 0;
	pushed = 0;
	if (count <= 5)
		return (sort_top_in_a(a, b, count, counter));
	median = find_median(*a, count);
	while (count--)
	{
		if ((*a)->index < median)
		{
			pb(a, b, counter);
			pushed++;
		}
		else
		{
			ra(a, counter);
			rotated++;
		}
	}
	if (rotated != stack_size(*a))
		rotate_a(a, rotated, counter);
	quicksort_a(a, b, rotated, counter);
	quicksort_b(a, b, pushed, counter);
}

int	check_count_in_order(t_stack *b, int count)
{
	if (!b)
		return (0);
	while (count > 1)
	{
		if (!b->next)
			break ;
		if (b->index < b->next->index)
			return (0);
		b = b->next;
		count--;
	}
	return (1);
}

void	quicksort_b(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	int	median;
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	if (count <= 4)
		return (sort_top_in_b(a, b, count, counter));
	median = find_median(*b, count);
	while (count--)
	{
		if ((*b)->index > median)
		{
			pa(a, b, counter);
			pushed++;
		}
		else
		{
			rb(b, counter);
			rotated++;
		}
	}
	if (rotated != stack_size(*b))
		rotate_b(b, rotated, counter);
	quicksort_a(a, b, pushed, counter);
	quicksort_b(a, b, rotated, counter);
}
