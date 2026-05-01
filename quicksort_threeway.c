/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_threeway.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 18:38:33 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 19:24:33 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pivots(t_stack *stack, int count, int *p_one, int *p_two)
{
	int	min;
	int	max;
	int	range;
	int	i;

	i = 0;
	min = stack->index;
	max = stack->index;
	while (i < count)
	{
		if (stack->index > max)
			max = stack->index;
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
		i++;
	}
	range = max - min;
	*p_one = min + (range / 3);
	*p_two = min + (2 * range / 3);
}
void	three_way_quick_a(t_stack **a, t_stack **b, int count, t_op_counter *counter)
{
	int	p_one;
	int	p_two;
	int	i;

	int	ra_c;
	int	pb_c;
	int	rb_c;

	ra_c = 0;
	pb_c = 0;
	rb_c = 0;
	i = 0;
	if (count <= 3)
		return (sort_three_on_top(a, b, 'a', count, counter));
	find_pivots(*a, count, &p_one, &p_two);
	while (i < count)
	{
		if ((*a)->index >= p_two)
		{
			ra(a, counter);
			ra_c++;
		}
		else
		{
			pb(a, b, counter);
			pb_c++;
			if ((*b)->index < p_one)
			{
				rb(b, counter);
				rb_c++;
			}
		}
		i++;
	}
	int j;
	if (ra_c < rb_c)
		j = ra_c;
	else
		j = rb_c;
	i = j;
	if (ra_c != stack_size(*a) && rb_c != stack_size(*b))
	{
		while (i--)
			rrr(a, b, counter);	
	}
	i = ra_c - j;
	if (ra_c != stack_size(*a))
	{
		while (i--)
			rra(a, counter);
	}	
	i = rb_c - j;
	if (rb_c != stack_size(*b))
	{
		while (i--)
			rrb(b, counter); 
	}
	three_way_quick_a(a, b, ra_c, counter);
	quicksort_b(a, b, pb_c - rb_c, counter);
	quicksort_b(a, b, rb_c, counter);
}
