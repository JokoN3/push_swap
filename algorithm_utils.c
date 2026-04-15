/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 16:24:21 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/15 16:24:44 by lvan-win      ########   odam.nl         */
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
