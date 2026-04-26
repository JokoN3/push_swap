/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 18:13:52 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/26 15:12:02 by yoneshev      ########   odam.nl         */
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
	int				index;
	int				num;
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
int		stack_len(t_stack *stack);
int		in_order(t_stack *stack);

t_stack	*init_stack_a(t_stack *stack_a, char **av);
t_stack	*add_new_node(void);
int		check_for_flags(char **av, int *strategy, int *bench);

void	swap(t_stack **a);
void	push(t_stack **to, t_stack **from);
void	rotate(t_stack **a);
void	rev_rotate(t_stack **a);

void	bubble_sort(t_stack **a, t_op_counter *count);
int		index_stack(t_stack **stack_a);
void	sort_three_in_a(t_stack **stack_a, t_stack **stack_b);
void	sort_three_in_b(t_stack **stack_a, t_stack **stack_b);
void	sort_three_on_top(t_stack **stack_a, t_stack **stack_b, char ab, int count);
int		find_median(t_stack *stack, int count);
void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int count);
void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int count);

int		validate_input(char **av, int allocated_av);
int		check_dup(char **av);
int		check_int(char **av);
int		non_num_in_str(char *str);
int		stack_size(t_stack *stack);

void	benchmark_mode(t_op_counter count, int strategy);
void	init_counter(t_op_counter *count);
void	print_ops(t_op_counter count);

float	compute_disorder(t_stack *a);
void 	put_disorder(float disorder, int fd);

#endif