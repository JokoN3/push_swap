/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_top_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/08 13:49:01 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 13:33:47 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_helper(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

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

int	push_biggest(t_stack **a, t_stack **b, t_op_counter *c, int *arr)
{
	int	r;

	r = 0;
	while (arr[0] != (*a)->index && arr[1] != (*a)->index)
	{
		ra(a, c);
		r++;
	}
	pb(a, b, c);
	return (r);
}

int	check_order_top(int *arr, int count)
{
	if (count == 5)
	{
		if (arr[0] < arr[1] && arr[1] < arr[2]
			&& arr[2] < arr[3] && arr[3] < arr[4])
			return (1);
		else
			return (0);
	}
	else
	{
		if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3])
			return (1);
		else
			return (0);
	}
}
