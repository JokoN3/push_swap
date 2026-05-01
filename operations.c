/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 19:09:44 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/05/01 13:31:04 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
}

void	push(t_stack **to, t_stack **from)
{
	t_stack	*to_first;
	t_stack	*from_first;
	t_stack	*from_second;

	if (!to || !from || !*from)
		return ;
	to_first = *to;
	from_first = *from;
	from_second = from_first->next;
	*from = from_second;
	from_first->next = to_first;
	*to = from_first;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = last_el(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second_to_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_el(*stack);
	second_to_last = prev_el(*stack, last);
	last->next = first;
	second_to_last->next = NULL;
	*stack = last;
}
