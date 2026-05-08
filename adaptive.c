/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptive.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-win <lvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/01 14:58:13 by lvan-win      #+#    #+#                 */
/*   Updated: 2026/05/01 15:08:44 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_stack **a, t_stack **b, t_op_counter *count)
{
	if (count->disorder < 0.2)
		cocktail_sort(a, count, stack_size(*a));
	else if (count->disorder >= 0.2 && count->disorder < 0.5)
		messy_room_sort(a, b, count);
	else
		quicksort_a(a, b, stack_size(*a));
}
