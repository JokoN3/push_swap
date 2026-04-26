/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 21:44:00 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 19:17:43 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>//

int	square_root(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

void	messy_room_sort(t_stack **a, t_stack **b, t_op_counter *count)
{
	int	sqrt_n;
	int	bucket;
	int	i;

	if (in_order(*a))
		return ;
	sqrt_n = square_root(stack_size(*a));
	bucket = 0;
	while (stack_size(*a) > sqrt_n)
	{
		i = 0;
		while (i < sqrt_n)
		{
			if ((*a)->index < (bucket + 1) * sqrt_n)
			{
				pb(a, b, count);
				i++;
			}
			else if (i < sqrt_n)
			{
				ra(a, count);
			}
		}
		bucket++;
	}
	cocktail_sort(a, count, stack_size(*a));
	while (stack_size(*b) > 0)
	{
		i = 0;
		while (i < sqrt_n)
		{
			pa(a, b, count);
			i++;
		}
		cocktail_sort(a, count, sqrt_n);
	}
}

// void	push_buckets_to_b(t_stack **a, t_stack **b, t_op_counter *count)
// {
// 	int	sqrt_n;
// 	int	bucket;
// 	int	i;

// 	sqrt_n = square_root(stack_size(*a));
// 	bucket = 0;
// 	while (stack_size(*a) > sqrt_n)
// 	{
// 		i = 0;
// 		while (i < sqrt_n)
// 		{
// 			if ((*a)->index < (bucket + 1) * sqrt_n)
// 			{
// 				pb(a, b, count);
// 				i++;
// 			}
// 			else if (i < sqrt_n)
// 			{
// 				ra(a, count);
// 			}
// 		}
// 		bucket++;
// 	}
// }

// void	push_back_and_sort(t_stack **a, t_stack **b, t_op_counter *count)
// {
// 	int	sqrt_n;
// 	int	i;

// 	sqrt_n = square_root(stack_size(*a));
// 	while (stack_size(*b) > 0)
// 	{
// 		i = 0;
// 		while (i < sqrt_n)
// 		{
// 			pa(a, b, count);
// 			i++;
// 		}
// 		cocktail_sort(a, count, sqrt_n);
// 	}
// }

// void	messy_room_sort(t_stack **a, t_stack **b, t_op_counter *count)
// {
// 	if (in_order(*a))
// 		return ;
// 	push_buckets_to_b(a, b, count);
// 	cocktail_sort(a, count, stack_size(*a));
// 	push_back_and_sort(a, b, count);
// }
