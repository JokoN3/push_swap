/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 15:32:10 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/05/13 13:28:16 by yoneshev      ########   odam.nl         */
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
			sa(a, count);
		if (i < bound - 2)
			ra(a, count);
		i++;
	}
}

void	bubble_rl(t_stack **a, t_op_counter *count, int bound)
{
	int	i;

	i = 0;
	while (i < bound - 1)
	{
		rra(a, count);
		if ((*a)->num > (*a)->next->num)
			sa(a, count);
		i++;
	}
	if (!in_order(*a))
		ra(a, count);
}

void	rotate_to_start(t_stack **a, t_op_counter *count)
{
	int	i;

	i = in_order_circ(*a);
	if (i > stack_size(*a) / 2)
	{
		i = stack_size(*a) - i;
		while (i > 0)
		{
			rra(a, count);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(a, count);
			i--;
		}
	}
}

void	cocktail_sort(t_stack **a, t_op_counter *count, int bound)
{
	if (bound > stack_size(*a))
		bound = stack_size(*a);
	while (in_order_circ(*a) < 0 && bound > 1)
	{
		bubble_lr(a, count, bound);
		bubble_rl(a, count, bound - 1);
		bound = bound - 2;
	}
	rotate_to_start(a, count);
}
