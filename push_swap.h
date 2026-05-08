/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 18:13:52 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/08 16:08:32 by lvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ADAPTIVE 1
# define SIMPLE 2
# define COMPLEX 3
# define MEDIUM 4
# define BENCH 5

# include <stddef.h>
# include "limits.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_operation_counter
{
	float	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}	t_op_counter;

void	free_stack(t_stack *stack);
void	free_arr(char **arr);
void	print_stack(t_stack *stack);
t_stack	*last_el(t_stack *stack);
t_stack	*prev_el(t_stack *stack, t_stack *element);
int		in_order(t_stack *stack);
int		in_order_circ(t_stack *stack);
int		check_circ_order(t_stack *stack, t_stack *current);

t_stack	*init_stack_a(t_stack *stack_a, char **av);
t_stack	*add_new_node(void);
int		check_for_flags(char **av, int *strategy, int *bench);

void	swap(t_stack **stack);
void	push(t_stack **to, t_stack **from);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

void	sa(t_stack **a, t_op_counter *count);
void	sb(t_stack **b, t_op_counter *count);
void	ss(t_stack **a, t_stack **b, t_op_counter *count);

void	pa(t_stack **a, t_stack **b, t_op_counter *count);
void	pb(t_stack **a, t_stack **b, t_op_counter *count);

void	ra(t_stack **a, t_op_counter *count);
void	rb(t_stack **b, t_op_counter *count);
void	rr(t_stack **a, t_stack **b, t_op_counter *count);

void	rra(t_stack **a, t_op_counter *count);
void	rrb(t_stack **b, t_op_counter *count);
void	rrr(t_stack **a, t_stack **b, t_op_counter *count);

void	bubble_lr(t_stack **a, t_op_counter *count, int bound);
void	bubble_rl(t_stack **a, t_op_counter *count, int bound);
void	bubble_sort(t_stack **a, t_op_counter *count);
void	rotate_to_start(t_stack **a, t_op_counter *count);
void	cocktail_sort(t_stack **a, t_op_counter *count, int bound);

int		square_root(int n);
void	buckets_to_b(t_stack **a, t_stack **b, t_op_counter *count, int sqrt_n);
void	back_and_sort(t_stack **a, t_stack **b, t_op_counter *count, int sqrt_n);
void	messy_room_sort(t_stack **a, t_stack **b, t_op_counter *count);

int		index_stack(t_stack **stack_a);
void	sort_three_in_a(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_three_in_b(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_three_on_top(t_stack **a, t_stack **b, char ab, int count, t_op_counter *counter);
int		find_median(t_stack *stack, int count);
void	slinky_a(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	slinky_b(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	rotate_b(t_stack **stack_b, int rotated, t_op_counter *counter);
void	rotate_a(t_stack **a, int rotated, t_op_counter *counter);
void	run_op_chain(t_stack **a, t_stack **b, char *ops, t_op_counter *counter);
void	push_sorted_to_a(t_stack **a, t_stack **b, int count, t_op_counter *counter);

void	three_way_quick_a(t_stack **a, t_stack **b, int count, t_op_counter *counter);

void	sort_top_in_a(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	sort_top_in_b(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	sort_four_in_a(t_stack **a, t_stack **b, t_op_counter *counter);
void	bubble_helper(int *arr, int size);
int		push_biggest(t_stack **a, t_stack **b, t_op_counter *c, int *arr);

void	adaptive(t_stack **a, t_stack **b, t_op_counter *count);

int		validate_input(char **av, int allocated_av);
int		check_dup(char **av);
int		check_int(char **av);
int		non_num_in_str(char *str);
int		stack_size(t_stack *stack);

void	benchmark_mode(t_op_counter count, int strategy);
void	init_counter(t_op_counter *count);
void	print_ops(t_op_counter count);

float	compute_disorder(t_stack *a);
void	print_disorder(float disorder, int fd);

#endif