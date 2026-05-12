/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 18:00:02 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 13:19:07 by yoneshev      ########   odam.nl         */
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

void	print_adaptive(t_op_counter count)
{
	ft_putstr_fd("[bench] strategy: Adaptive / ", 2);
	if (count.disorder < 0.2)
		ft_putstr_fd("O(n)\n", 2);
	else if (count.disorder >= 0.2 && count.disorder < 0.5)
		ft_putstr_fd("O(n log n)\n", 2);
	else
		ft_putstr_fd("O(n√n)\n", 2);
}

void	benchmark_mode(t_op_counter count, int strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(count.disorder, 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("[bench] strategy: Cocktail Shaker Sort / O(n^2)\n", 2);
	if (strategy == COMPLEX)
		ft_putstr_fd("[bench] strategy: Slinky Sort / O(n log n)\n", 2);
	if (strategy == MEDIUM)
		ft_putstr_fd("[bench] strategy: Messy Room Sort / O(n√n)\n", 2);
	if (strategy == ADAPTIVE)
		print_adaptive(count);
	ft_putstr_fd("[bench] total_ops: ", 2);
	count.total = count.sa + count.sb + count.ss
		+ count.pa + count.pb + count.ra + count.rb
		+ count.rr + count.rra + count.rrb + count.rrr;
	ft_putnbr_fd(count.total, 2);
	ft_putstr_fd("\n", 2);
	print_ops(count);
}
