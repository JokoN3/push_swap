/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 15:32:10 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/22 19:15:24 by lvan-win      ########   odam.nl         */
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
		if (i < bound - 2)
		{
			rotate(a);
			count->ra++;
			write(1, "ra\n", 3);
		}
		i++;
	}
}

void	bubble_rl(t_stack **a, t_op_counter *count, int bound)
{
	int	i;

	i = 0;
	while (i < bound - 1)
	{
		rev_rotate(a);
		count->rra++;
		write(1, "rra\n", 4);
		if ((*a)->num > (*a)->next->num)
		{
			swap(a);
			count->sa++;
			write(1, "sa\n", 3);
		}
		i++;
	}
	if (!in_order(*a))
	{
		rotate(a);
		count->ra++;
		write(1, "ra\n", 3);
	}
}

void	cocktail_sort(t_stack **a, t_op_counter *count)
{
	int	bound;
	int	i;
	
	bound = stack_size(*a);
	while (in_order_circ(*a) < 0 && bound > 1)
	{
		bubble_lr(a, count, bound);
		bubble_rl(a, count, bound - 1);
		bound = bound - 2;
	}
	i = in_order_circ(*a);
	if (i > stack_size(*a) / 2)
	{
		i = stack_size(*a) - i;
		while (i > 0)
		{
			rev_rotate(a);
			count->rra++;
			write(1, "rra\n", 4);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate(a);
			count->ra++;
			write(1, "ra\n", 3);
			i--;
		}
	}
}

// remove simple bubble sort if we don't use it anymore?
void	bubble_sort(t_stack **a, t_op_counter *count)
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
