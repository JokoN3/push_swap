/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 15:33:00 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 15:34:30 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_op_counter *count)
{
	rev_rotate(a);
	count->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_op_counter *count)
{
	rev_rotate(b);
	count->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_op_counter *count)
{
	rev_rotate(a);
	rev_rotate(b);
	count->rrr++;
	write(1, "rrr\n", 4);
}
