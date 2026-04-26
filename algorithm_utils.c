/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 16:24:21 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 13:35:57 by lvan-win      ########   odam.nl         */
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

int	check_circ_order(t_stack *stack, t_stack *current)
{
	int	i;

	i = 0;
	while (i < stack_size(stack) - 1)
	{
		if (!current->next)
		{
			if (current->num > stack->num)
					return (0);
			current = stack;
		}
		else
		{
			if (current->num > current->next->num)
				return (0);
			current = current->next;
		}
		i++;
	}
	return (1);
}

int	in_order_circ(t_stack *stack)
{
	t_stack	*current;
	int		begin;

	begin = 0;
	current = stack;
	while (current->index != 0)
	{
		begin++;
		current = current->next;
	}
	if (!check_circ_order(stack, current))
		return (-1);
	return (begin);
}
