/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_on_top.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 13:40:08 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/07 20:11:33 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	sort_three_in_a(t_stack **a, t_stack **b, t_op_counter *counter)
// {
// 	t_stack	*n1;
// 	t_stack	*n2;
// 	t_stack	*n3;

// 	n1 = *a;
// 	n2 = (*a)->next;
// 	n3 = (*a)->next->next;
// 	if (n1->index < n2->index && n1->index < n2->index && n2->index < n3->index)
// 		return ;
// 	if (n1->index < n2->index && n1->index < n3->index)
// 		run_op_chain(a, b, "pbsapa", counter);
// 	else if (n1->index > n2->index && n1->index > n3->index)
// 	{
// 		if (n2->index > n3->index)
// 			run_op_chain(a, b, "sapbsapasa", counter);
// 		else
// 			run_op_chain(a, b, "sapbsapa", counter);
// 	}
// 	else if (n1->index > n2->index)
// 		sa(a, counter);
// 	else
// 		run_op_chain(a, b, "pbsapasa", counter);
// }

// void	sort_three_in_b(t_stack **a, t_stack **b, t_op_counter *counter)
// {
// 	t_stack	*n1;
// 	t_stack	*n2;
// 	t_stack	*n3;

// 	n1 = *b;
// 	n2 = (*b)->next;
// 	n3 = (*b)->next->next;
// 	if (n1->index > n2->index && n1->index > n2->index && n2->index > n3->index)
// 		return ;
// 	if (n1->index > n2->index && n1->index > n3->index)
// 		run_op_chain(a, b, "pasbpb", counter);
// 	else if (n1->index < n2->index && n1->index < n3->index)
// 	{
// 		if (n2->index < n3->index)
// 			run_op_chain(a, b, "sbpasbpbsb", counter);
// 		else
// 			run_op_chain(a, b, "sbpasbpb", counter);
// 	}
// 	else if (n1->index < n2->index)
// 		sb(b, counter);
// 	else
// 		run_op_chain(a, b, "pasbpbsb", counter);
// }

// void	sort_three_on_top(t_stack **a, t_stack **b, char ab, int count, t_op_counter *counter)
// {
// 	if (ab == 'a')
// 	{
// 		if (count < 3)
// 		{
// 			if ((*a)->index > (*a)->next->index)
// 				sa(a, counter);
// 		}
// 		else
// 			sort_three_in_a(a, b, counter);
// 	}
// 	else
// 	{
// 		if (count < 3)
// 		{
// 			if ((*b)->index < (*b)->next->index)
// 				sb(b, counter);
// 		}
// 		else
// 			sort_three_in_b(a, b, counter);
// 		push_sorted_to_a(a, b, count, counter);
// 	}
// }

void	bubble_helper(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	// int	*arr;

	// arr = *array;
	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

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
	bubble_helper(arr, 5);
	while (arr[0] != (*a)->index && arr[1] != (*a)->index)
	{
		ra(a, counter);
		rotated++;
	}
	pb(a, b, counter);
	while (arr[0] != (*a)->index && arr[1] != (*a)->index)
	{
		ra(a, counter);
		rotated++;
	}
	pb(a, b, counter);
	while (rotated--)
		rra(a, counter);
	sort_three_in_a(a, b, counter);
	if ((*b)->index < (*b)->next->index)
		sb(b, counter);
	pa(a, b, counter);
	pa(a, b, counter);
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
	// push_sorted_to_a(a, b, 3, counter);
}

void	sort_top_in_b(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	if (count == 1)
		pa(a, b, counter);
	if (count == 2)
	{
		if ((*b)->index < (*b)->next->index)
			sb(b, counter);
		run_op_chain(a, b, "papa", counter);
	}
	if (count == 3)
	{
		sort_three_in_b(a, b, counter);
		// push_sorted_to_a(a, b, count, counter);
	}
	if (count == 4)
		sort_four_in_b(a, b, counter);
}

void	sort_top_in_a(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, counter);
		return ;
	}
	if (count == 3)
		sort_three_in_a(a, b, counter);
	if (count == 4)
		sort_four_in_a(a, b, counter);
	if (count == 5)
		sort_five_in_a(a, b, counter);	
}