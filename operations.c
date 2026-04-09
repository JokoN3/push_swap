/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 19:09:44 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/09 19:55:12 by lvan-win      ########   odam.nl         */
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
	
	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	ft_lstadd_back(a, first);
	first->next = NULL;
	*a = second;
}
