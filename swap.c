/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/26 15:07:24 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/04/26 15:12:50 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_op_counter *count)
{
	swap(a);
	count->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_op_counter *count)
{
	swap(b);
	count->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_op_counter *count)
{
	swap(a);
	swap(b);
	count->ss++;
	write(1, "ss\n", 3);
}
