/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   slinky_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 13:42:50 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 17:26:43 by yoneshev      ########   odam.nl         */
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
	if (n1->index > n2->index && n1->index > n2->index && n2->index > n3->index)
		run_op_chain(a, b, "papapa", counter);
	else if (n1->index > n2->index && n1->index > n3->index)
		run_op_chain(a, b, "pasbpapa", counter);
	else if (n1->index < n2->index && n1->index < n3->index)
	{
		if (n2->index < n3->index)
			run_op_chain(a, b, "sbpasbpasapa", counter);
		else
			run_op_chain(a, b, "sbpasbpapa", counter);
	}
	else if (n1->index > n2->index)
		run_op_chain(a, b, "pasbpasapa", counter);
	else
		run_op_chain(a, b, "sbpapapa", counter);
}

void	slinky_a(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	int	arr[3];

	arr[ROTATED] = 0;
	arr[PUSHED] = 0;
	if (count <= 5)
		return (sort_top_in_a(a, b, count, counter));
	arr[MEDIAN] = find_median(*a, count);
	while (count--)
	{
		if ((*a)->index < arr[MEDIAN])
		{
			pb(a, b, counter);
			arr[PUSHED]++;
		}
		else
		{
			ra(a, counter);
			arr[ROTATED]++;
		}
	}
	if (arr[ROTATED] != stack_size(*a))
		rotate_a(a, arr[ROTATED], counter);
	slinky_a(a, b, arr[ROTATED], counter);
	slinky_b(a, b, arr[PUSHED], counter);
}

void	slinky_b(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	int	arr[3];

	arr[PUSHED] = 0;
	arr[ROTATED] = 0;
	if (count <= 4)
		return (sort_top_in_b(a, b, count, counter));
	arr[MEDIAN] = find_median(*b, count);
	while (count--)
	{
		if ((*b)->index > arr[MEDIAN])
		{
			pa(a, b, counter);
			arr[PUSHED]++;
		}
		else
		{
			rb(b, counter);
			arr[ROTATED]++;
		}
	}
	if (arr[ROTATED] != stack_size(*b))
		rotate_b(b, arr[ROTATED], counter);
	slinky_a(a, b, arr[PUSHED], counter);
	slinky_b(a, b, arr[ROTATED], counter);
}
