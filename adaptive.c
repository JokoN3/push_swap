/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 14:58:13 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/05/08 13:49:19 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack **a, t_stack **b, t_op_counter *count)
{
	if (count->disorder < 0.2)
		cocktail_sort(a, count, stack_size(*a));// make insertion sort
	else if (count->disorder >= 0.2 && count->disorder < 0.5)
		messy_room_sort(a, b, count);
	else
		quicksort_a(a, b, stack_size(*a));
}

int	insert(t_stack **a, t_stack **b, t_op_counter *count, int i)
{
	int	back;
	
	back = 0;
	pb(a, b, count);
	while ((*b)->index > (*a)->index)
	{
		if (back > 0)
			back++;
		else if ((*a)->index > (*a)->next->index)
			back = 1;
		ra(a, count);
		i++;
	}
	pa(a, b, count);
	while (back > 0)
	{
		rra(a, count);
		back--;
		i--;
	}
	return (i);
}

void	insert_sort(t_stack **a, t_stack **b, t_op_counter *count)
{
	int	len;
	int	i;
	int	back;

	len = stack_size(*a);
	i = 0;
	while (i < len);
	{
		if ((*a)->index > (*a)->next->index)
			i = insert(a, b, count, i);
		else
		{
			ra(a, count);
			i++;
		}
	}
}
