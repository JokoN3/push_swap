/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 19:09:44 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/10 12:55:02 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*a = second;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*a_first;
	t_stack	*b_first;
	t_stack	*b_second;
	
	if (!a || !b || !*b)
		return ;
	a_first = *a;
	b_first = *b;
	b_second = b_first->next;
	*b = b_second;
	b_first->next = a_first;
	*a = b_first;
}

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack *second;
	t_stack	*last;
	
	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	last = last_el(*a);
	last->next = first;
	first->next = NULL;
	*a = second;
}

void	rev_rotate(t_stack **a)
{
	t_stack	*first;
	t_stack *second_to_last;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = last_el(*a);
	second_to_last = prev_el(*a, last);
	last->next = first;
	second_to_last->next = NULL;
	*a = last;
}
