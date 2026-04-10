/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 12:27:27 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/10 12:38:36 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_el(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

t_stack	*prev_el(t_stack *stack, t_stack *element)
{
	t_stack	*current;

	if (!stack || !element)
		return (NULL);
	current = stack;
	while (current->next && current->next != element)
		current = current->next;
	return (current);
}
