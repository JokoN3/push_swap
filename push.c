/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 15:16:57 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 15:28:22 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_op_counter *count)
{
	push(a, b);
	count->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_op_counter *count)
{
	push(b, a);
	count->pb++;
	write(1, "pb\n", 3);
}
