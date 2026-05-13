/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 18:13:52 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/05/13 13:58:47 by yoneshev      ########   odam.nl         */
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

int		check_for_flags(char **av, int *strategy, int *bench);
int		validate_input(char **av, int allocated_av);
int		check_dup(char **av);
int		check_int(char **av);
int		non_num_in_str(char *str);
int		index_stack(t_stack **stack_a);
void	free_arr(char **arr);
void	init_counter(t_op_counter *count);
float	compute_disorder(t_stack *a);

int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
t_stack	*prev_el(t_stack *stack, t_stack *element);
t_stack	*last_el(t_stack *stack);
t_stack	*add_new_node(void);
t_stack	*init_stack_a(t_stack *stack_a, char **av);

int		in_order(t_stack *stack);
int		in_order_circ(t_stack *stack);
int		check_circ_order(t_stack *stack, t_stack *current);

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
void	rotate_to_start(t_stack **a, t_op_counter *count);
void	cocktail_sort(t_stack **a, t_op_counter *count, int bound);

int		square_root(int n);
void	buckets_to_b(t_stack **a, t_stack **b, t_op_counter *c, int sqrt_n);
void	back_and_sort(t_stack **a, t_stack **b, t_op_counter *c, int sqrt_n);
void	messy_room_sort(t_stack **a, t_stack **b, t_op_counter *count);

void	slinky_a(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	slinky_b(t_stack **a, t_stack **b, int count, t_op_counter *counter);
void	sort_top_in_a(t_stack **a, t_stack **b, int count, t_op_counter *c);
void	sort_top_in_b(t_stack **a, t_stack **b, int count, t_op_counter *c);
void	sort_three_in_a(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_three_in_b(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_four_in_a(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_four_in_b(t_stack **a, t_stack **b, t_op_counter *counter);
void	sort_five_in_a(t_stack **a, t_stack **b, t_op_counter *counter);
void	rotate_a(t_stack **a, int rotated, t_op_counter *counter);
void	rotate_b(t_stack **stack_b, int rotated, t_op_counter *counter);
void	push_sorted_to_a(t_stack **a, t_stack **b, int count, t_op_counter *c);
void	bubble_helper(int *arr, int size);
void	run_op_chain(t_stack **a, t_stack **b, char *ops, t_op_counter *c);
int		find_median(t_stack *stack, int count);
int		push_biggest(t_stack **a, t_stack **b, t_op_counter *c, int *arr);
int		check_order_top(int *arr, int count);

void	adaptive(t_stack **a, t_stack **b, t_op_counter *count);
void	insert_sort(t_stack **a, t_stack **b, t_op_counter *count);
int		insert(t_stack **a, t_stack **b, t_op_counter *count, int i);

void	benchmark_mode(t_op_counter count, int strategy);
void	print_ops(t_op_counter count);
void	print_disorder(float disorder, int fd);

#endif