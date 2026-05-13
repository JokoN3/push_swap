/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_on_top.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 13:40:08 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 13:34:03 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_in_a(t_stack **a, t_stack **b, t_op_counter *counter)
{
	int	rotated;
	int	arr[5];

	rotated = 0;
	arr[0] = (*a)->index;
	arr[1] = (*a)->next->index;
	arr[2] = (*a)->next->next->index;
	arr[3] = (*a)->next->next->next->index;
	arr[4] = (*a)->next->next->next->next->index;
	if (check_order_top(arr, 5) == 1)
		return ;
	bubble_helper(arr, 5);
	rotated = push_biggest(a, b, counter, arr);
	rotated += push_biggest(a, b, counter, arr);
	while (rotated--)
		rra(a, counter);
	sort_three_in_a(a, b, counter);
	if ((*b)->index < (*b)->next->index)
		sb(b, counter);
	run_op_chain(a, b, "papa", counter);
}

void	sort_four_in_a(t_stack **a, t_stack **b, t_op_counter *counter)
{
	int	rotated;
	int	arr[4];

	rotated = 0;
	arr[0] = (*a)->index;
	arr[1] = (*a)->next->index;
	arr[2] = (*a)->next->next->index;
	arr[3] = (*a)->next->next->next->index;
	if (check_order_top(arr, 4) == 1)
		return ;
	bubble_helper(arr, 4);
	while (arr[0] != (*a)->index)
	{
		ra(a, counter);
		rotated++;
	}
	pb(a, b, counter);
	while (rotated--)
		rra(a, counter);
	sort_three_in_a(a, b, counter);
	pa(a, b, counter);
}

void	sort_four_in_b(t_stack **a, t_stack **b, t_op_counter *counter)
{
	int	rotated;
	int	arr[4];

	rotated = 0;
	arr[0] = (*b)->index;
	arr[1] = (*b)->next->index;
	arr[2] = (*b)->next->next->index;
	arr[3] = (*b)->next->next->next->index;
	bubble_helper(arr, 4);
	while (arr[3] != (*b)->index)
	{
		rb(b, counter);
		rotated++;
	}
	pa(a, b, counter);
	while (rotated--)
		rrb(b, counter);
	sort_three_in_b(a, b, counter);
}

void	sort_top_in_b(t_stack **a, t_stack **b, int c, t_op_counter *counter)
{
	if (c == 1)
		pa(a, b, counter);
	if (c == 2)
	{
		if ((*b)->index < (*b)->next->index)
			sb(b, counter);
		run_op_chain(a, b, "papa", counter);
	}
	if (c == 3)
		sort_three_in_b(a, b, counter);
	if (c == 4)
		sort_four_in_b(a, b, counter);
}

void	sort_top_in_a(t_stack **a, t_stack **b, int c, t_op_counter *counter)
{
	if (c == 1)
		return ;
	if (c == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, counter);
		return ;
	}
	if (c == 3)
		sort_three_in_a(a, b, counter);
	if (c == 4)
		sort_four_in_a(a, b, counter);
	if (c == 5)
		sort_five_in_a(a, b, counter);
}
