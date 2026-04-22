/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 15:32:10 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/22 15:20:17 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_lr(t_stack **a, t_op_counter *count, int bound)
{
	int	i;

	i = 0;
	while (i < bound - 1)
	{
		if ((*a)->num > (*a)->next->num)
		{
			swap(a);
			count->sa++;
			write(1, "sa\n", 3);
		}
		rotate(a);
		count->ra++;
		write(1, "ra\n", 3);
		i++;
	}
}

void	cocktail_sort(t_stack **a, t_op_counter *count)
{
	int	bound;
	int	i;
	
	bound = stack_size(*a);
	while (!in_order(*a))
	{
		bubble_lr(a, count, bound);
		if (in_order(*a))
			return ;
		bubble_rl(a, count, bound);
	}
}

void	bubble_sort(t_stack **a, t_op_counter *count)//can be removed if cocktail is better?
{
	int	i;

	while (!in_order(*a))
	{
		i = 1;
		while (i < stack_size(*a))
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
