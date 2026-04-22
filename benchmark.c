/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 18:00:02 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/17 14:31:42 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_op_counter *count)
{
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->total = 0;
}

void	print_ops(t_op_counter count)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(count.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(count.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(count.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(count.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(count.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(count.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(count.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(count.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(count.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(count.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(count.rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	benchmark_mode(t_op_counter count, int strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_disorder(count.disorder, 2);
	ft_putstr_fd("\n", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("[bench] strategy: Bubble sort / O(n^2)\n", 2); // fix this
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(count.total, 2);
	ft_putstr_fd("\n", 2);
	print_ops(count);
}
