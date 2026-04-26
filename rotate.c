/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 15:29:20 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 15:32:26 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_op_counter *count)
{
	rotate(a);
	count->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_op_counter *count)
{
	rotate(b);
	count->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_op_counter *count)
{
	rotate(a);
	rotate(b);
	count->rr++;
	write(1, "rr\n", 3);
}
