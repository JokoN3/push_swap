/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 15:32:10 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/15 15:43:54 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	bubble_sort(t_stack **a, t_op_counter *count)
{
	int	i;

	while (!in_order(*a))
	{
		i = 1;
		while (i < stack_len(*a))
		{
			if ((*a)->num > (*a)->next->num)
			{
				swap(a);
				count->sa++;
				write(1, "sa\n", 3);
			}
			if (in_order(*a))
				return ;
			rotate(a);
			count->ra++;
			write(1, "ra\n", 3);
			i++;
		}
		rotate(a);
		count->ra++;
		write(1, "ra\n", 3);
	}
}
